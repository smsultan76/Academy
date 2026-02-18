import socket

# Domain to IP mapping
dns_records = {
    "google.com": "142.250.183.206",
    "facebook.com": "157.240.241.35",
    "openai.com": "104.18.12.123",
    "localhost": "127.0.0.1"
}

# Create UDP socket
server_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

HOST = "127.0.0.1"
PORT = 5353

server_socket.bind((HOST, PORT))
print("Simple DNS Server is running...")

while True:
    data, client_address = server_socket.recvfrom(1024)
    domain_name = data.decode().strip()

    print("DNS Query for:", domain_name)

    ip_address = dns_records.get(domain_name, "Domain not found")

    server_socket.sendto(ip_address.encode(), client_address)
