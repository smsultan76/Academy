import socket
HOST = 'localhost'
PORT = 5001
sultan_server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sultan_server.bind((HOST, PORT))
sultan_server.listen(1)
print(f"[SERVER] Listening on {HOST}:{PORT}")
conn, addr = sultan_server.accept()
print(f"[SERVER] Connected by {addr}")
while True:
    data = conn.recv(1024).decode()
    if not data or data.lower() == 'sm_sultan':
        print("[SERVER] Client disconnected.")
        break
    print(f"[CLIENT]: {data}")
    conn.send(data.encode())
conn.close()
sultan_server.close()