import socket 
import sys 

HOST = '0.0.0.0' 
PORT = 53 

def run_mobile_dns_server(): 
    print(f"--- Mobile DNS Server Starting ---") 
    
    try: 
        with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as server_socket: 
            server_socket.bind((HOST, PORT)) 
             
            print(f"Listening on {HOST}:{PORT} (UDP)") 
            print(f"Waiting for DNS queries from mobile devices...") 
            print(f"Press CTRL+C to stop.") 
 
            while True: 
                data, address = server_socket.recvfrom(512) 
                print(f"[Request] Received DNS query from Phone: {address}") 
 
    except PermissionError: 
        print("\n[ERROR] Permission Denied!") 
        print("You must run this script with elevated privileges to bind to Port 53.") 
    except Exception as e: 
        print(f"Error: {e}") 
 
if __name__ == "__main__": 
    run_mobile_dns_server()