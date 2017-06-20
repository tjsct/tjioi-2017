
from PyPDF2 import PdfFileWriter, PdfFileReader

output = PdfFileWriter()

# to prevent garbage collection :\
lmao = []

for i in range(56):
    filename = '%d.pdf' % i
    f = open(filename, 'rb')
    pdf = PdfFileReader(f)
    output.addPage(pdf.getPage(0))
    lmao.append(f)

with open('out.pdf', 'wb') as f:
    output.write(f)

