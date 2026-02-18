import socket

client_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

SERVER_HOST = "127.0.0.1"
SERVER_PORT = 5353

domain = input("Enter domain name: ")

client_socket.sendto(domain.encode(), (SERVER_HOST, SERVER_PORT))

response, _ = client_socket.recvfrom(1024)
print("Resolved IP Address:", response.decode())

client_socket.close()
