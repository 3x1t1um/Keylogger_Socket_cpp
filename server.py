import socket

banner = ''' ▄▄▄        ██████  ██░ ██  ██▓ ▄▄▄      
 ▒████▄    ▒██    ▒ ▓██░ ██▒▓██▒▒████▄    
 ▒██  ▀█▄  ░ ▓██▄   ▒██▀▀██░▒██▒▒██  ▀█▄  
 ░██▄▄▄▄██   ▒   ██▒░▓█ ░██ ░██░░██▄▄▄▄██ 
  ▓█   ▓██▒▒██████▒▒░▓█▒░██▓░██░ ▓█   ▓██▒file:///C:/Users/gaston/Downloads/main.cpp
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
        data = conn.recv(1024)
        print(' '+data.decode('utf-8'))
