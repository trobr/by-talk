import os
import threading


class uncompress(threading.Thread):
    lock = threading.Lock()
    __compress_list = []

    def __init__(self, threadId, name, counter):
        threading.Thread.__init__(self)
        self.threadId = threadId
        self.name = name
        self.counter = counter

    @classmethod
    def get_ucl(cls):
        return uncompress.__compress_list

    @classmethod
    def set_ucl(cls, ucl):
        uncompress.__compress_list = ucl

    def run(self):
        while True:
            try:
                uncompress.lock.acquire()
                file = uncompress.__compress_list.pop()
            except IndexError:
                break
            finally:
                uncompress.lock.release()

            cmd = 'UnRAR.exe x %s %s' % (file, os.path.dirname(file))
            os.system(cmd)


def main():
    root = r'D:\ImgPro\code\python\threading\1'
    compress_list = os.listdir(root)
    compress_list = [os.path.join(root, ist)
                     for ist in compress_list if '.rar' in ist]
    uncompress.set_ucl(compress_list)

    thread_list = []
    for i in range(2):
        thread_list.append(uncompress(i, 'uc-%d' % (i), i))

    for t in thread_list:
        t.start()


if __name__ == '__main__':
    main()
