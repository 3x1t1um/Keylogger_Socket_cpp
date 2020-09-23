import socket

banner = ''' ▄▄▄        ██████  ██░ ██  ██▓ ▄▄▄      
 ▒████▄    ▒██    ▒ ▓██░ ██▒▓██▒▒████▄    
 ▒██  ▀█▄  ░ ▓██▄   ▒██▀▀██░▒██▒▒██  ▀█▄  
 ░██▄▄▄▄██   ▒   ██▒░▓█ ░██ ░██░░██▄▄▄▄██ 
  ▓█   ▓██▒▒██████▒▒░▓█▒░██▓░██░ ▓█   ▓██▒
  ▒▒   ▓▒█░▒ ▒▓▒ ▒ ░ ▒ ░░▒░▒░▓   ▒▒   ▓▒█░
   ▒   ▒▒ ░░ ░▒  ░ ░ ▒ ░▒░ ░ ▒ ░  ▒   ▒▒ ░
   ░   ▒   ░  ░  ░   ░  ░░ ░ ▒ ░  ░   ▒   
       ░  ░      ░   ░  ░  ░ ░        ░  ░
 
 
                   \033[31m{ By AskaD }\033[00m
              [=] \033[34mAuthor\033[00m  : AskaD    [=]
                 { \033[34mGithub\033[00m : 3x1t1um }  

'''

print(banner)
print()

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s: # (wtf)
    
    s.bind(('127.0.0.1', 1337))
    s.listen(1)
    conn, addr = s.accept()
    
    while 1:
        with open(f'{addr}.txt', 'a+') as file:
         
            data = conn.recv(1024).decode('utf-8')
            print(' '+data)
            now = datetime.now()
            dt_string = now.strftime("%d/%m/%Y %H:%M:%S")
            file.write(f'{dt_string} : {data}')
