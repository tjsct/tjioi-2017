var EMAIL_SUBJECT = "Confirm your TJ IOI registration";
var EMAIL_BODY = '<p>' + [
  "Dear {SPONSOR_NAME},",
  "This automated message is to confirm our records regarding your registration for TJ IOI. Information for each team you've registered is listed below. Inside the parentheses next to each person are their T-shirt size and dietary restrictions.",
  "{TEAM_INFO}",
  "We request that you reply to this email by this <b>Friday, April 19</b> to tell us whether the information above is accurate. If it is, great â but please send us an email anyway! If there are any errors, please let us know what needs to be changed.",
  "<b>T-shirt sizes:</b> Although we will do our best to accommodate changes up until the date of the competition, we will be ordering T-shirts very soon. As a result, <i>we may not be able to honor T-shirt size changes after Friday.</i>",
  "<b>Checks:</b> You should have received an email once we have received a check for your team; hopefully, this is consistent with what is listed above. If it has been more than one week since you sent a check, and we have not yet received it, please let us know.",
  "Finally, as mentioned in previous emails, please take a look at the Registration page at <a href=\"https://activities.tjhsst.edu/tjioi/registration/\">https://activities.tjhsst.edu/tjioi/registration/</a> for important information about the Media Release Form, Study Guide, and Student Information Form. Please share this link with your students as well.",
  "Thank you, and we hope to see you at the competition!",
  "Kevin Geng<br>TJ IOI Planning Committee"
].join('</p><p>') + '</p>';

/*
function rowToDict(headers, row) {
  var out = {};
  for (var i = 0; i < headers.length; i++) {
    out[headers[i]] = row[i];
  }
  return out;
}
*/

function getRowValue(headers, row, key) {
  var pos = headers.indexOf(key);
  return row[pos];
}

function getSheetHeaders(sheet) {
  return sheet.getRange(1, 1, 1, sheet.getLastColumn()).getValues()[0];
}

function getSheetData(sheet) {
  return sheet.getRange(2, 1, sheet.getLastRow() - 1, sheet.getLastColumn()).getValues();
}

function sendEmails() {
  var ss = SpreadsheetApp.getActiveSpreadsheet();

  var teamSheet = ss.getSheetByName('Team info');
  var teamHeaders = getSheetHeaders(teamSheet);
  var teamData = getSheetData(teamSheet);

  var peopleSheet = ss.getSheetByName('Participant info');
  var peopleHeaders = getSheetHeaders(peopleSheet);
  var peopleData = getSheetData(peopleSheet);

  var uniqueEmails = [];
  var uniqueEmailNames = [];
  teamData.forEach(function(data) {
    var email = getRowValue(teamHeaders, data, 'Sponsor email');
    var name = getRowValue(teamHeaders, data, 'Sponsor name');
    if (uniqueEmails.indexOf(email) == -1) {
      uniqueEmails.push(email);
      uniqueEmailNames.push(name);
    }
  });
  
  Logger.log(uniqueEmails);

  uniqueEmails.forEach(function(email, email_pos) {
    
    // find teams corresponding to this email
    var teams = teamData.filter(function(data) {
      return email == getRowValue(teamHeaders, data, 'Sponsor email');
    });

    // generate text for teams
    var teamTexts = teams.map(function(data) {
      
      // find participants corresponding to this team
      var people = peopleData.filter(function(data2) {
        return getRowValue(teamHeaders, data, 'Team ID') == getRowValue(peopleHeaders, data2, 'Team ID');
      });
      
      // generate text for participants
      var peopleTexts = people.map(function(data2, i) {
        var out = '<i>' + ((i == 0) ? 'Team sponsor' : 'Member ' + i) + ':</i> ';
        out += getRowValue(peopleHeaders, data2, 'Name') || '<span style="color: red">unknown</span>';
        out += ' (size ';
        out += getRowValue(peopleHeaders, data2, 'T-shirt size') || '<span style="color: red">unknown</span>';
        out += '; ';
        out += getRowValue(peopleHeaders, data2, 'Dietary restrictions') || 'none';
        out += ')';
        return out;
      });
      
      // LOL THIS IS INJECTABLE but w/e
      var out = '<b>' + getRowValue(teamHeaders, data, 'Team name') + '</b>';
      out += '<br><i>School name:</i> ';
      out += getRowValue(teamHeaders, data, 'School name');
      out += '<br><i>Check received:</i> ';
      out += getRowValue(teamHeaders, data, 'Check received') ? 'Yes' : '<span style="color: red">Not received</span>';
      out += '<br>';
      out += peopleTexts.join('<br>');
      return out;
    });

    var body = EMAIL_BODY;
    body = body.replace(/\{SPONSOR_NAME\}/, uniqueEmailNames[email_pos]);
    body = body.replace(/\{TEAM_INFO\}/, teamTexts.join('<br><br>'));
    Logger.log(email + ' ' + body);

    var dest = 'gengkev+whatever@gmail.com';
    // var dest = email;
    GmailApp.sendEmail(dest, EMAIL_SUBJECT, null, {
      from: 'tjioiofficers@gmail.com',
      name: 'TJ IOI Officers',
      bcc: 'tjioiofficers+regconf@gmail.com',
      htmlBody: body
    });
  });

}

