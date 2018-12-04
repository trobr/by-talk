# -*- coding: utf-8 -*-


from PyPDF2 import PdfFileReader, PdfFileWriter


pdf_file = r'D:\ImgPro\Algorithm\MIL\refer\wuys.pdf'


def read_txt_from_pdf(pdffile):
    with open(pdffile, 'rb') as fd:
        pdf = PdfFileReader(fd)
        num_pages = pdf.getNumPages()
        print('pdf pages:', num_pages)
        print('info:', pdf.getDocumentInfo())


read_txt_from_pdf(pdf_file)
