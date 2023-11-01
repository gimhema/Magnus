// Fill out your copyright notice in the Description page of Project Settings.


#include "RLServerConnector.h"

#include <Runtime/Networking/Public/Interfaces/IPv4/IPv4Address.h>


// Sets default values
ARLServerConnector::ARLServerConnector() 
{

//    SocketSubsystemPtr = SocketSubsystem.GetSocketSubsystem();
}

// Called when the game starts or when spawned
void ARLServerConnector::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARLServerConnector::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ARLServerConnector::InitSocketSystem()
{

}

void ARLServerConnector::CreateSocket()
{
    if (SocketSubsystemPtr)
    {
        // 家南 积己
//        TSharedRef<FInternetAddr> ServerAddress = SocketSubsystemPtr->CreateInternetAddr();
        bool bIsValid = true;
        //        ServerAddress->SetIp(*GameServerIP, bIsValid);
        //        ServerAddress->SetPort(GameServerPort);

        if (bIsValid)
        {
            // TCP 家南 积己
  //          Socket = SocketSubsystemPtr->CreateSocket(NAME_Stream, TEXT("YourSocketName"), false);

            // 辑滚俊 楷搬
            TSharedRef<FInternetAddr> ServerAddress = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();;

            FIPv4Address ip;
            FIPv4Address::Parse(RLServerIP, ip);

            ServerAddress->SetIp(ip.Value);
            ServerAddress->SetPort(RLServerPort);
            if (Socket->Connect(*ServerAddress))
            {
                // 皋技瘤 傈价
                int32 BytesSent = 0;
                bool bSuccess = SendMessageToRLServer("Hello RL Server . . . ");

                if (bSuccess)
                {
                    UE_LOG(LogTemp, Warning, TEXT("Send Message Successful"));
                }
                else
                {
                    UE_LOG(LogTemp, Error, TEXT("Failed Send Message"));
                }

                isRun = true;
            }
            else
            {
                UE_LOG(LogTemp, Error, TEXT("Connect Server Failed"));
            }
        }
        else
        {
            UE_LOG(LogTemp, Error, TEXT("This IP Address Invalid . . . "));
        }
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("Failed Socket Subsystem"));
    }
}

void ARLServerConnector::Start()
{
    CreateSocket();

    // Listen . . . 

    while (isRun)
    {
        uint32 pendingDataSize = 0;
        TArray<uint8> recvedData;

        int32 totalReadData = 0;

        Socket->SetNonBlocking(true);
        int32 _read;
        uint8 _temp;
        if (!Socket->Recv(&_temp, 1, _read, ESocketReceiveFlags::Peek))
        {
            isRun = false;
            continue;
        }

        Socket->SetNonBlocking(false);

        while (isRun)
        {
            if (!Socket->HasPendingData(pendingDataSize))
            {
                break;
            }

            recvedData.SetNumUninitialized(totalReadData + pendingDataSize);

            int32 readData = 0;

            if (!Socket->Recv(recvedData.GetData() + totalReadData, pendingDataSize, readData))
            {
                // Data Read Failed.
                break;
            }
            totalReadData = totalReadData + readData;
        }

        if (isRun && recvedData.Num() != 0)
        {
            // Recv Logic
            RecvMessageFromServer(recvedData);
        }

        // sleep for loop control . . .
    }
}

bool ARLServerConnector::SendMessageToRLServer(const FString& Message)
{
    // 皋技瘤 傈价
    int32 BytesSent = 0;

    return Socket->Send((uint8*)TCHAR_TO_UTF8(*Message), Message.Len(), BytesSent);
}

void ARLServerConnector::RecvMessageFromServer(TArray<uint8>& Message)
{
    // Recv Logic . . .

    //    if (arenaGameMode)
    //    {
    //        FString _data = ReadDataAsString(Message, Message.Num());
    //        //        arenaGameMode->CallMessageFunctionByName();
    //        //        arenaGameMode->CallMessageFunctionByUnique();
    //    }
}

