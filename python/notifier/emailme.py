#! /usr/bin/env python
""" Email Me.
Fork of: https://gist.github.com/alexalemi/2150894

Usage:
    emailme <message>
    emailme [-s] <message>
    emailme [-s] <subject> <message>
    emailme <toaddr> <subject> <message>
    emailme <toaddr> <fromaddr> <subject> <message>
    emailme -h | --help
    emailme --version

Options:
    -h --help   Show help
    -s --sms    Send SMS
    --version   Show version
"""
#Python script to send simple emails
import smtplib
from email.mime.text import MIMEText
import netrc
from docopt import docopt

DEFAULTFROM = "your_email@gmail.com"
DEFAULTTO = "recipients_email@gmail.com"
SMSADDRESS = None #"YOURNUMBER@messaging.sprintpcs.com"
DEFAULTSUBJECT = "Your subject"

"""
Note that by default, this looks to check your netrc credentials
to use this feature, create a .netrc file, so that only you can read and write it

    touch ~/.netrc
    chmod 600 ~/.netrc

and then add the information for the gmail smtp server, i.e.

    machine smtp.gmail.com
            login yourusername@gmail.com
            password yourpassword

This way only you will have access to this file.  Do not use your actual account
password, instead create an application specific password for your Google
account at: https://security.google.com/settings/security/apppasswords

For SMS support, use your service providers gateway.
See: http://en.wikipedia.org/wiki/List_of_SMS_gateways

Notice that this can be used either as a command line script, as documented
in the main doc string, or as a python module.  To use as a module:

  import emailme

  emailme.send_email("message")
or
  emailme.send_sms("message")
"""

from functools import partial

def send_email(message="",subject=DEFAULTSUBJECT,
    me=DEFAULTFROM,recipients=[DEFAULTTO],
    smtpserver="smtp.gmail.com",tls=True,login=None,
    password=None):
    """ Send an email using the gmail smtp servers, and netrc to hide the username
        and password information """

    if login is None or password is None:
        secrets = netrc.netrc()
        netrclogin,netrcaccount,netrcpassword = secrets.authenticators(smtpserver)
    if login is None:
        login = netrclogin
    if password is None:
        password = netrcpassword

    msg = MIMEText(message)

    msg['Subject'] = subject
    msg['From'] = me
    msg['To'] = ", ".join(recipients)

    s = smtplib.SMTP(smtpserver, '587')
    if tls:
        s.starttls()
        s.login(login,password)

    s.sendmail(me,recipients, msg.as_string())
    s.quit()

send_sms = partial(send_email, recipients =[SMSADDRESS] ,subject="")


if __name__=="__main__":
    args = docopt(__doc__, version="Email Me version 0.1")

    toaddr = args['<toaddr>'] or DEFAULTTO
    fromaddr = args['<fromaddr>'] or DEFAULTFROM
    message = args['<message>']

    if args['--sms']:
        subject = args['<subject>'] or ''
        send_sms(subject=subject,
                message=message)
    else:
        subject = args['<subject>'] or DEFAULTSUBJECT
        send_email(recipients=[toaddr],
                me=fromaddr,
                subject=subject,
                message=message)
