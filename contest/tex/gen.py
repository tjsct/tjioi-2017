import subprocess
import os
import glob

s = r'''\documentclass{{article}}
\usepackage{{main}}

\begin{{document}}

\setcounter{{section}}{{5}}
\include{{problems/{}}}

\end{{document}}'''

problems = list(map(lambda x: x[x.find("/")+1:x.find(".")], glob.glob("problems/*.tex")))

for p in problems:
	f = open("{}.tex".format(p), "w")
	f.write(s.format(p))
	f.close()
	subprocess.call(['pdflatex', p])
	if not os.path.exists("../{}/statement".format(p)):
		os.makedirs("../{}/statement".format(p))
	os.rename("{}.pdf".format(p), "../{0}/statement/{0}.pdf".format(p))
	os.remove("{}.tex".format(p))
