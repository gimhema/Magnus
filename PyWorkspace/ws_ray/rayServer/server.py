import ray
import socket
import queue
import threading

ray.init()

server_ip = "127.0.0.1"
server_port = 9999

@ray.remote
class Server:
    def __init__(self) -> None:
        self.server_sock = None
        self.message_queue = queue.Queue()
        self.terminated = False
        self.conn = None
        self.echoTest = True # For test, when train agent change False
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
            self.conn, addr = self.server_sock.accept()
            with self.conn:
                print(f"Connected . . : {addr}")
                while True:  # 연결을 종료하지 않고 계속 통신
                    data = self.conn.recv(1024)
                    if not data:
                        break
                    self.recvMessageFromUnreal(data)
        pass

    def recvMessageFromUnreal(self, data):
        # 언리얼에서 수신받은 데이터들을 Env Status에 업데이트해놓는다.
        print(f"Recv data : : {data.decode('utf-8')}")

        if self.echoTest is True:
            print(f"Push Message : {data}")
            self.message_queue.put(data)
            print(f"Push Message Completed")
        pass

    def sendMessageToUnreal(self, message):
        print("Send Message To Client Step")
        try:
            print(f"Make Message : {message}" )
            message_bytes = message.encode('utf-8')
            self.conn.sendall(message_bytes)
            print(f"Sent message to Unreal Engine: {message}")
        except Exception as e:
            print(f"Error sending message to Unreal Engine: {str(e)}")
        pass

    def acceptClients(self):
        self.setup()
        while True:
            conn, addr = self.server_sock.accept()
            client_thread = threading.Thread(target=self.handleClient, args=(conn, addr))
            client_thread.start()
        pass

    def handleClient(self, conn, addr):
        with conn:
            print(f"Connected: {addr}")
            while True:
                data = conn.recv(1024)
                if not data:
                    break
                self.recvMessageFromUnreal(data)
        pass

    def sendLoop(self):
        # Unreal Env 에서 push한 메세지큐들을 쭉 돌면서 메세지를 전송한다.
        print("Send Loop Start . . .")
        self.setup()
        while True:
            if self.terminated is True:
                break
            if self.message_queue.empty() is False:
                _sendMsg = self.message_queue.get()
                self.sendMessageToUnreal(_sendMsg)
        pass

rayServer = Server.remote()

# rayServer.recvWait.remote()
# rayServer.sendLoop.remote()
rayServer.acceptClients.remote()

loop = True
while True:
    if loop is False:
        break

print("TEST ! ! !")
