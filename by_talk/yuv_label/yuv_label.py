import os
import cv2
import argparse
import datetime
import numpy as np


class brPrint(object):
    __cur_progress = 0

    def __init__(self, total=1000, *args, **kwargs):
        self.__total = total
        self.__str_process = ''
        return super().__init__(*args, **kwargs)

    @classmethod
    def set_progress(cls, cur):
        brPrint.__cur_progress = cur

    def set_total(self, total):
        self.__total = total

    def _print(self, own, msg):
        if own is None:
            own = os.path.basename(__file__).split('.')[0]
        time = datetime.datetime.now().strftime('%H:%M:%S.%f')

        try:
            self.__str_process = '[%3.5f%%]' % (
                brPrint.__cur_progress * 100 / self.__total)
        except ZeroDivisionError:
            print('[%s] %s %s:  %s' % (time, self.__str_process,
                                       'brTools', 'set the __total variable'))

        out = '[%s] %s %s:  %s' % (time, self.__str_process, own, msg)
        print(out)


class label(object):
    def __init__(self, filename, label_file, size, *args, **kwargs):
        self.width, self.height = size
        self.frame_len = int(self.width * self.height * 3 / 2)
        self.shape = (int(self.height*1.5), self.width)
        self.f = open(filename, 'rb')
        self.flb = open(label_file, 'w')

        if (self.f == None or self.flb == None):
            bprint('file open error')
        else:
            bprint('file open success')

        return super().__init__(*args, **kwargs)

    def read_raw(self):
        try:
            raw = self.f.read(self.frame_len)
            yuv = np.frombuffer(raw, dtype=np.uint8)
            yuv = yuv.reshape(self.shape)
        except Exception as e:
            return False, None
        return True, yuv

    def read(self):
        ret, yuv = self.read_raw()
        if not ret:
            return ret, yuv
        bgr = cv2.cvtColor(yuv, cv2.COLOR_YUV2BGR_NV21)
        return ret, bgr

    def write_rois(self, cnt, rois):
        self.flb.write('FrameID,%d,ObjNum,%d,' % (cnt, len(rois)))

        for roi in rois:
            # x,y,w,h
            self.flb.write('x1,%d,y1,%d,x2,%d,y2,%d,'
                           % (roi[0], roi[1], roi[2] + roi[0], roi[3] + roi[1]))

        self.flb.write('\n')
        self.flb.flush()

    def run(self):
        cnt = 1
        while True:
            read_ok, frame = self.read()
            if not read_ok:
                break

            cv2.namedWindow('frame')
            cv2.imshow('frame', frame)
            rois = cv2.selectROIs('frame', frame)
            self.write_rois(cnt, rois)
            bprint('frame label @ %d' % (cnt))
            cnt += 1

            key = cv2.waitKey()
            if key == -1:
                continue
            elif chr(key) == 'e':
                break

        self.flb.close()


def bprint(msg, own=None, is_progress=False):
    if is_progress:
        brPrint()._print(own, msg)
    else:
        if own is None:
            own = os.path.basename(__file__).split('.')[0]
        time = datetime.datetime.now().strftime('%H:%M:%S.%f')
        out = '[%s] %s:  %s' % (time, own, msg)
        print(out)


def init():
    parser = argparse.ArgumentParser()
    parser.add_argument('yuv', type=str, help='yuv file path',
                        default=r'D:\ImgPro\file\by_talk\yuv_label\BasketballPass_416x240_50.yuv')
    parser.add_argument('width', type=int, help='frame width', default=416)
    parser.add_argument('height', type=int, help='frame height', default=240)
    args = parser.parse_args()

    return args


def main():
    args = init()
    yuv_file = args.yuv
    size = (args.width, args.height)

    wd = os.getcwd()
    label_file = os.path.join(wd, 'label.csv')
    lo = label(yuv_file, label_file, size)
    lo.run()


if __name__ == "__main__":
    main()
