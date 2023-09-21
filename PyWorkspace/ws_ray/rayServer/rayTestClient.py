import asyncio
import socket

server_ip = "127.0.0.1"
server_port = 9999

async def send_messages():
    # 서버에 연결
    client_sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client_sock.connect((server_ip, server_port))
    print("Connected to server.")

    try:
        while True:
            # 사용자로부터 메시지 입력
            message = input("Enter a message (or 'exit' to quit): ")

            if message == "exit":
                break

            # 메시지를 서버로 전송
            client_sock.sendall(message.encode('utf-8'))

    except KeyboardInterrupt:
        pass
    finally:
        # 연결 종료
        client_sock.close()
        print("Disconnected from server.")

async def recv_responses(client_sock):
    while True:
        try:
            data = await asyncio.to_thread(client_sock.recv, 1024)
            print(f"Received from server: {data.decode('utf-8')}")
        except Exception as e:
            print(f"Error receiving data: {str(e)}")
            break

async def main():
    client_sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client_sock.connect((server_ip, server_port))
    print("Connected to server.")

    recv_task = asyncio.create_task(recv_responses(client_sock))

    try:
        await asyncio.gather(send_messages(), recv_task)
    except KeyboardInterrupt:
        pass
    finally:
        # 연결 종료
        client_sock.close()
        print("Disconnected from server.")

if __name__ == "__main__":
    asyncio.run(main())
