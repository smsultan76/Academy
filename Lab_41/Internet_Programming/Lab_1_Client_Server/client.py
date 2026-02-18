import socket
sultan_server = socket.socket(socket.AF_INET,
socket.SOCK_STREAM)
HOST = 'localhost'
PORT = 5000
sultan_server.connect((HOST, PORT))
print(f"Connected to server at {HOST}:{PORT}")
while True:
    message = input("Client: ")
    sultan_server.send(message.encode())
    if message.lower() == 'sm_sultan':
        break
    data = sultan_server.recv(1024).decode()
    print(f"Server: {data}")
    if data.lower() == 'sm_sultan':
        break

sultan_server.close()