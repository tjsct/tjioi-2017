# certificates

A Python script to generate TJ IOI certificates, which were distributed to
each participant in the team folder at the start of the competition.

We first printed an identical certificate template (in the Logistics folder,
`certificate_template.pdf`) for each student, in color. Then we used this
script to generate PDF files with each student's name and school, positioned
to match the certificate template. These were generated from CSV files which
we downloaded directly from our Google Spreadsheet with team info.

Then, we combined each of the PDFs into one file for printing (located at
`certificates.pdf`) and used a black-and-white printer to print on top of the
certificate templates. (Oh, and don't forget to disable double-sided
printing...)

