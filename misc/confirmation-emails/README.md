# Confirmation emails

This is a script to automatically send confirmation emails to team sponsors
with the current team information in our spreadsheet, and asking them to
confirm if it is correct. This is developed as a Google Apps Script relying
on values from our team info spreadsheet (`Registered teams`).

By the way, team names aren't properly escaped into the email HTML, so if
there's a team named `<script>alert()</script>` you'll need to fix that!

To set it up with a new spreadsheet, go to Tools > Script Editor, paste it in,
and fix all the hardcoded stuff :) When you run it, you'll also need to
authorize as the account you want to send from.

