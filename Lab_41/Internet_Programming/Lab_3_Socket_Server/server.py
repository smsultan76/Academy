import socket
import threading

# Function to handle each client
def handle_client(client_socket, address):
    print(f"[NEW CONNECTION] {address} connected.")

    while True:
        try:
            message = client_socket.recv(1024).decode()
            if not message:
                break

            print(f"[{address}] {message}")

            reply = f"Server received: {message}"
            client_socket.send(reply.encode())

        except:
            break

    print(f"[DISCONNECTED] {address}")
    client_socket.close()

# Create socket
server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

HOST = '127.0.0.1'   # localhost
PORT = 12345

server_socket.bind((HOST, PORT))
server_socket.listen()

print(f"[SERVER STARTED] Listening on {HOST}:{PORT}")

while True:
    client_socket, address = server_socket.accept()

    # Create a new thread for each client
    thread = threading.Thread(
        target=handle_client,
        args=(client_socket, address)
    )
    thread.start()
