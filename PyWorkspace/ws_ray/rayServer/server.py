import ray
import socket
from ray.rllib.env.policy_server_input import PolicyServerInput

ray.init()

server_ip = "127.0.0.1"
server_port = 9999


@ray.remote
class Server:
    def __init__(self) -> None:
        pass

    def setup(self):
        pass

    def run(self):
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
                    print(f"Recv data : : {data.decode('utf-8')}")
        pass

    def recvMessageFromUnreal(self):
        pass

    def sendMessageToUnreal(self):
        pass
