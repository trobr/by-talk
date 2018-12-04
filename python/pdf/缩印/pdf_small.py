from reportlab.pdfgen import canvas

pdf_path = r'./hello.pdf'


def hello():
    c = canvas.Canvas(pdf_path)
    c.drawString(100, 100, "Hello World")  # 简单的文件内容布局和内容
    c.showPage()  # 停止画图
    c.save()


def small():
    c = canvas.Canvas(pdf_path)


hello()
