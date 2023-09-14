import ray
import socket

ray.init()

server_ip = "127.0.0.1"
server_port = 9999

@ray.remote
class Server:
    def __init__(self) -> None:
        pass

    def setup(self):
        pass

    def recvWait(self):
        with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as server_socket:
            server_socket.bind((server_ip, server_port))
            server_socket.listen()

            print(f" Wait Server . . . {server_ip}:{server_port}.")

            while True:
                conn, addr = server_socket.accept()
                with conn:
                    print(f"Connected . . : {addr}")
                    data = conn.recv(1024)
                    if not data:
                        break
                    self.recvMessageFromUnreal(data)
        pass

    def recvMessageFromUnreal(self, data):
        print(f"Recv data : : {data.decode('utf-8')}")
        pass

    def sendMessageToUnreal(self):
        pass

rayServer = Server.remote()

rayServer.recvWait.remote()

print("TEST ! ! !")
