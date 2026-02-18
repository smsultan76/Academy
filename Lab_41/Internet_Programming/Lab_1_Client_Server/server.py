import socket
sultan_server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
HOST = 'localhost'
PORT = 5000
sultan_server.bind((HOST, PORT))
sultan_server.listen(1)
print(f"Server started. Listening on {HOST}:{PORT}")
conn, addr = sultan_server.accept()
print(f"Connected by {addr}")
while True:
    data = conn.recv(1024).decode()
    if not data or data.lower() == 'sm_sultan':
        print("Client disconnected.")
        break
    print(f"Client: {data}")
    message = input("Server: ")
    conn.send(message.encode())
    if message.lower() == 'sm_sultan':
        break
conn.close()
sultan_server.close()