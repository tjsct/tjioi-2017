# Confirmation emails

This is a script to send confirmation emails to teams with our current team information, and asking them to confirm if it is correct.

This is developed as a Google Apps Script relying on values from a Google Spreadsheet.
The original sheet is [Registered teams](https://docs.google.com/spreadsheets/d/1zqaERfq570Jbdif1OVFe5JNPs7pO07li5hBRzl1f0Ko/edit).
Also team names aren't properly escaped so if there's a team named `<script>alert()</script>` you'll need to watch for that.
To set it up with a new spreadsheet, go to Tools > Script Editor, paste it in, and fix all the hardcoded stuff :)

