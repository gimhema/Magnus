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

            # 서버로부터 응답 받기
#            data = client_sock.recv(1024)
#            print(f"Received from server: {data.decode('utf-8')}")

    except KeyboardInterrupt:
        pass
    finally:
        # 연결 종료
        client_sock.close()
        print("Disconnected from server.")

async def main():
    await send_messages()

if __name__ == "__main__":
    asyncio.run(main())
