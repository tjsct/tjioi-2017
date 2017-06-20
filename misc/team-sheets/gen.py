#!/usr/bin/env python3

LATEX_FILE = r'''
\documentclass[12pt]{{article}}
\usepackage[utf8]{{inputenc}}
\usepackage{{geometry}}
\usepackage{{hyperref}}

\usepackage{{fancyhdr}}
\pagestyle{{fancy}}

\lhead{{Programming Round Instructions}}
\rhead{{{username}}}
\cfoot{{}}

\setlength{{\parindent}}{{0pt}}

\begin{{document}}

{{\Huge {first_name}}}\\\\
{{\Large {last_name}}}\\

\textbf{{Username:}} \verb|{username}|\\
\textbf{{Password:}} \verb|{password}|

\section*{{Instructions}}

\begin{{enumerate}}
    \item Do not touch the computer until the round begins.
    \item Log into the virtual machine using the password \verb|tjioi|.
    \item Open the contest site at \url{{https://activities.tjhsst.edu/tjioi/grader/}}.
    \item Click on ``Contest Grader'' to access the grader, and log in using the username and password above.
\end{{enumerate}}

\section*{{Rules}}

\begin{{itemize}}
    \item You may use only one computer during the contest.
    \item Do not attempt to exit the virtual machine.
    \item Do not use any other electronic devices. If you have any, give them to a volunteer or your team coach before the contest begins.
    \item If you have a problem with your computer, or accidentally exit the virtual machine, alert a volunteer immediately.
\end{{itemize}}

\end{{document}}
'''

import subprocess
import yaml

with open('../contest/contest.yaml') as f:
    teams = yaml.load(f)['users']

team_map = {team['username']: team for team in teams}
for team, data in team_map.items():
    if 'hidden' in data and data['hidden']:
        continue
    print(team, data)
    text = LATEX_FILE.format(**data)
    filename = '%s.tex' % team
    with open(filename, 'w') as f:
        f.write(text)
    subprocess.call(['pdflatex', filename])

