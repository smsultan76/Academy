import socket
HOST = 'localhost'
PORT = 5001
sultan_server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sultan_server.connect((HOST, PORT))
print(f"[CLIENT] Connected to server at {HOST}:{PORT}")
while True:
    message = input("[CLIENT]: ")
    sultan_server.send(message.encode())
    if message.lower() == 'sm_sultan':
        break
    echoed = sultan_server.recv(1024).decode()
    print(f"[SERVER (echo)]: {echoed}")
sultan_server.close()