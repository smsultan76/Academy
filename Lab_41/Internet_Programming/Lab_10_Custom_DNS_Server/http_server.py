from http.server import HTTPServer, SimpleHTTPRequestHandler

HOST = "127.0.0.1"
PORT = 8080

server = HTTPServer((HOST, PORT), SimpleHTTPRequestHandler)
print("HTTP Server running on localhost...")
server.serve_forever()
