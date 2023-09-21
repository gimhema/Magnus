import asyncio
import socket
import argparse

server_ip = "127.0.0.1"
server_port = 9999

async def send_messages(client_sock):
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

async def recv_responses(client_sock):
    while True:
        try:
            data = await asyncio.to_thread(client_sock.recv, 1024)
            print(f"Received from server: {data.decode('utf-8')}")
        except Exception as e:
            print(f"Error receiving data: {str(e)}")
            break

def main():
    parser = argparse.ArgumentParser(description="Socket client for sending and receiving messages.")
    parser.add_argument("-s", "--send", action="store_true", help="Send mode")
    parser.add_argument("-r", "--receive", action="store_true", help="Receive mode")

    args = parser.parse_args()

    if not args.send and not args.receive:
        print("Please specify either -s (send) or -r (receive) mode.")
        return

    if args.send and args.receive:
        print("Please choose either -s (send) or -r (receive) mode, but not both.")
        return

    client_sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client_sock.connect((server_ip, server_port))
    print("Connected to server.")

    if args.send:
        print("Send mode activated. You can type messages to send to the server.")
        asyncio.run(send_messages(client_sock))
    elif args.receive:
        print("Receive mode activated. You will see messages received from the server.")
        asyncio.run(recv_responses(client_sock))

    # 연결 종료
    client_sock.close()
    print("Disconnected from server.")

if __name__ == "__main__":
    main()
