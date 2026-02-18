import socket

# Create TCP socket
server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

HOST = '127.0.0.1'   # localhost
PORT = 8080

server_socket.bind((HOST, PORT))
server_socket.listen(1)

print(f"HTTP Server running on http://{HOST}:{PORT}")

while True:
    client_socket, client_address = server_socket.accept()
    print("Connection from:", client_address)

    request = client_socket.recv(1024).decode()
    print("Request:\n", request)

    # HTML content
    html_content = """
    <html>
    <head>
        <title>Python HTTP Server</title>
    </head>
    <body>
        <h1>Hello from Python HTTP Server!</h1>
        <p>This webpage is served using socket programming.</p>
    </body>
    </html>
    """

    # HTTP response
    response = (
        "HTTP/1.1 200 OK\r\n"
        "Content-Type: text/html\r\n"
        f"Content-Length: {len(html_content)}\r\n"
        "\r\n"
        + html_content
    )

    client_socket.sendall(response.encode())
    client_socket.close()
