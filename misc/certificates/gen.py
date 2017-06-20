#!/usr/bin/env python3

LATEX_FILE = r'''
\documentclass{{article}}
\usepackage{{mathptmx}}
\usepackage{{lscape}}
\begin{{document}}
\pagenumbering{{gobble}}
\begin{{landscape}}
    \topskip0pt
    \vspace*{{\fill}}
    \begin{{table}}[htb!]
        \centering
        %\tiny
        %\setlength{{\tabcolsep}}{{2pt}}
        \begin{{tabular}}{{c}}
            {{\fontsize{{56}}{{40}}\selectfont {name}}}\\\\\\
            {{\fontsize{{24}}{{20}}\selectfont {school_name}}}\\\\\\\\\\\\\\\\\\\\\\\\\
        \end{{tabular}}
        \label{{tab:wide_table}}
    \end{{table}}
    %\vspace*{{\fill}}
\end{{landscape}}
\end{{document}}
'''


import csv
import subprocess

teams = {}
coaches = set()
with open('teams.csv') as f:
    for row in csv.DictReader(f):
        teams[row['Team ID']] = row
        coaches.add(row['Sponsor name'])

participants = []
with open('participants.csv') as f:
    for row in csv.DictReader(f):
        team = teams[row['Team ID']]
        school_name = team['School name']
        name = row['Name']
        if name in coaches:
            print('SKIPPING COACH:', name)
            continue
        participants.append({'name': name, 'school_name': school_name})

for i, obj in enumerate(participants):
    print(obj)
    filename = '%d.tex' % i
    with open(filename, 'w') as f:
        f.write(LATEX_FILE.format(**obj))
    subprocess.call(['pdflatex', filename])

