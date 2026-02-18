import socket
client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
HOST = '127.0.0.1'
PORT = 12345
client_socket.connect((HOST, PORT))
while True:
    message = input("Enter message (type 'exit' to quit): ")
    if message.lower() == 'exit':
        break
    client_socket.send(message.encode())
    reply = client_socket.recv(1024).decode()
    print("Server:", reply)
client_socket.close()
