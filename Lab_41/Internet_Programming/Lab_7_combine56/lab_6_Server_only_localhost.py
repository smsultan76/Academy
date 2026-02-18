from http.server import HTTPServer, SimpleHTTPRequestHandler

HOST = "127.0.0.1"   # Localhost only
PORT = 8080

server = HTTPServer((HOST, PORT), SimpleHTTPRequestHandler)

print(f"Localhost HTTP Server running at http://{HOST}:{PORT}")
server.serve_forever()