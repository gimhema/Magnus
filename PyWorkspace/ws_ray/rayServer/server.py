import ray
import socket

ray.init()

server_ip = "127.0.0.1"
server_port = 9999

@ray.remote
class Server:
    def __init__(self) -> None:
        self.server_sock = None
        pass

    def setup(self):
        if self.server_sock is None:
            self.server_sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            self.server_sock.bind((server_ip, server_port))
            self.server_sock.listen()
        pass

    def recvWait(self):
        self.setup()
        while True:
            conn, addr = self.server_sock.accept()
            with conn:
                print(f"Connected . . : {addr}")
                data = conn.recv(1024)
                if not data:
                    break
                self.recvMessageFromUnreal(data)
        pass

    def recvMessageFromUnreal(self, data):
        print(f"Recv data : : {data.decode('utf-8')}")
        # 언리얼에서 수신받은 데이터들을 Env Status에 업데이트해놓는다.
        pass

    def sendMessageToUnreal(self, message):
        self.setup()
        try:
            message_bytes = message.encode('utf-8')
            self.server_sock.sendall(message_bytes)
            print(f"Sent message to Unreal Engine: {message}")
        except Exception as e:
            print(f"Error sending message to Unreal Engine: {str(e)}")
        pass

    def sendLoop(self):
        # Unreal Env 학습을 시작한다.
        # observation은 수신루프에서 업데이트해주는 Env Status에서 받아온다
        # 액션을 보낼때마다 sendMessageToUnreal 함수를 호출하여 보내준다.
        pass

rayServer = Server.remote()

rayServer.recvWait.remote()
rayServer.sendLoop.remote()

print("TEST ! ! !")
