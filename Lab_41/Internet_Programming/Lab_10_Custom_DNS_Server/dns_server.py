import socket

dns_records = {
    "Sultan_1021.com": "127.0.0.1"
}

server_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
HOST = "127.0.0.1"
PORT = 5353

server_socket.bind((HOST, PORT))
print("Local DNS Server running on port", PORT)

while True:
    data, addr = server_socket.recvfrom(1024)
    domain = data.decode().strip()
    print("DNS query received for:", domain)

    ip_address = dns_records.get(domain, "Domain not found")
    server_socket.sendto(ip_address.encode(), addr)
