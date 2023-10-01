import ray
import socket
import queue
import threading

ray.init()


@ray.remote
class Server:
    def __init__(self) -> None:
        self.server_ip = "127.0.0.1"
        self.server_port = 9999

        self.server_sock = None
        self.terminated = False
        
        self.conn = None
        self.client_conns = {}

        self.echoTest = False # For test, when train agent change False

        self.message_queue = queue.Queue() # send buffer
        self.recv_recent_msg = None # current state
        pass

    def setup(self):
        if self.server_sock is None:
            self.server_sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            self.server_sock.bind((self.server_ip, self.server_port))
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

    def sendMessageToUnreal(self, message):
        print("Send Message To Client Step")
        try:
            print(f"Make Message : {message}")
            for client_id, conn in self.client_conns.items():
                conn.sendall(message)  # 모든 클라이언트에게 메시지 전송
                print(f"Sent message to {client_id}: {message}")
        except Exception as e:
            print(f"Error sending message to Unreal Engine: {str(e)}")

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
            client_id = f"{addr[0]}:{addr[1]}"  # 클라이언트를 구분할 수 있는 고유한 ID 생성
            self.client_conns[client_id] = conn  # 각 클라이언트에 대한 연결을 저장

            while True:
                data = conn.recv(1024)
                if not data:
                    break
                self.recvMessageFromUnreal(data, client_id)
                if self.message_queue.empty() is False:
                    _sendMsg = self.message_queue.get()
                    self.sendMessageToUnreal(_sendMsg)
        pass
        
    def recvMessageFromUnreal(self, data, client_id):
        # 언리얼에서 수신받은 데이터들을 Env Status에 업데이트해놓는다.
        print(f"Recv data from {client_id}: {data.decode('utf-8')}")

        self.recv_recent_msg = data.decode('utf-8')

        if self.echoTest is True:
            print(f"Push Message : {data}")
            self.message_queue.put(data)
            print(f"Push Message Completed")
        pass

    def PushStateToContainer(self, state):
        msg = ""

        # convert state to msg . . .
        
        self.message_queue.put(msg)
        pass

    def GetRecentState(self):
        captured = self.recv_recent_msg

        # convert msg to state container & reward & done

        current_state = {}
        reward = 0
        done = False

        # return state & reward
        return current_state, reward, done

rayServer = Server.remote()
rayServer.acceptClients.remote()

loop = True
while True:
    if loop is False:
        break

print("TEST ! ! !")
