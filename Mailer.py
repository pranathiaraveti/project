import smtplib
from email.mime.text import MIMEText
from email.mime.multipart import MIMEMultipart
from email.mime.base import MIMEBase
from email import encoders
email_user = (input('enter the sender email : ')+'@gmail.com')
email_password = input('enter the password : ')
email_send = (input('enter the receiver mail : ')+'@gmail.com')

subject = input("enter subject of the mail : ")

msg = MIMEMultipart()
msg['from'] = email_user
msg['to'] = email_send
msg['subject'] = subject

body = input("enter the body of the mail : ")
msg.attach(MIMEText(body,'plain'))

filename=input('enter the filename with extension : ')
attachment =open(filename,'rb')

part = MIMEBase('application','octet-stream')
part.set_payload((attachment).read())
encoders.encode_base64(part)
part.add_header('content-disposition',"attachment; filename = "+filename)

msg.attach(part)
text = msg.as_string()
server = smtplib.SMTP('smtp.gmail.com',587)
server.starttls()
server.login(email_user,email_password)
print("sent")

server.sendmail(email_user,email_send,text)
server.quit()
