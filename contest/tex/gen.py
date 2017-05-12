import subprocess
import os
import glob

s = r'''\documentclass{{article}}
\usepackage{{main}}

\begin{{document}}

\setcounter{{section}}{{{}}}
\include{{problems/{}}}

\end{{document}}'''

problems = ['race', 'lunchbox', 'singing', 'pencils', 'puck', 'candy', 'larryopoly', 'cookie', 'hungry', 'grocery']

for (i, p) in enumerate(problems):
	f = open("{}.tex".format(p), "w")
	f.write(s.format(i, p))
	f.close()
	subprocess.call(['pdflatex', p])
	if not os.path.exists("../{}/statement".format(p)):
		os.makedirs("../{}/statement".format(p))
	os.rename("{}.pdf".format(p), "../{0}/statement/{0}.pdf".format(p))
	os.remove("{}.tex".format(p))
