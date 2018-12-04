def re_store():
    import os

    src_path = r'/home/rand1'
    dst_path = r'/home/rand2'

    files = os.listdir(src_path)
    for file in files:
        full_path = os.path.join(src_path, file)
        new_file = os.path.join(dst_path, file)
        with open(full_path, 'r') as fd:
            msg = fd.read().split('\n')
            msg = msg[:len(msg) // 2]
            with open(new_file, 'w') as nfd:
                for _msg in msg:
                    nfd.write(_msg + '\n')

def print_power():
    
import xml.etree.ElementTree as ET
from os import getcwd

sets = [('_lpr', 'train')]# , ('2018', 'train_val')]

classes = ["LP"]


def convert_annotation(year, image_id, list_file):
    in_file = open('%s/VOC%s/Annotations/%s.xml' % (wd, year, image_id))
    tree = ET.parse(in_file)
    root = tree.getroot()

    try:
        for obj in root.iter('object'):
            difficult = obj.find('difficult').text
            cls = obj.find('name').text
            if cls not in classes or int(difficult) == 1:
                continue
            cls_id = classes.index(cls)
            xmlbox = obj.find('bndbox')
            b = (int(xmlbox.find('xmin').text), int(xmlbox.find('ymin').text),
                 int(xmlbox.find('xmax').text), int(xmlbox.find('ymax').text))
            list_file.write(" " + ",".join([str(a)
                                        for a in b]) + ',' + str(cls_id))
    except:
        print('parse error >> %s/VOC%s/Annotations/%s.xml' % (wd, year, image_id))
        continue


wd = getcwd()

for year, image_set in sets:
    image_ids = open('%s/VOC%s/ImageSets/Main/%s.txt' %
                     (wd, year, image_set)).read().strip().split()
    list_file = open('%s_%s.txt' % (year, image_set), 'w')
    for image_id in image_ids:
        list_file.write('%s/VOC%s/JPEGImages/%s.jpg' %
                        (wd, year, image_id))
        convert_annotation(year, image_id, list_file)
        list_file.write('\n')
    list_file.close() 