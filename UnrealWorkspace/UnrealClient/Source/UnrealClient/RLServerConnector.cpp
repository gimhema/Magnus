// Fill out your copyright notice in the Description page of Project Settings.


#include "RLServerConnector.h"

// Sets default values
ARLServerConnector::ARLServerConnector() 
{

    SocketSubsystemPtr = SocketSubsystem.GetSocketSubsystem();
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
        TSharedRef<FInternetAddr> ServerAddress = SocketSubsystemPtr->CreateInternetAddr();
        bool bIsValid;
        ServerAddress->SetIp(*RLServerIP, bIsValid);
        ServerAddress->SetPort(RLServerPort);

        if (bIsValid)
        {
            // TCP 家南 积己
            Socket = SocketSubsystemPtr->CreateSocket(NAME_Stream, TEXT("YourSocketName"), false);

            // 辑滚俊 楷搬
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

bool ARLServerConnector::SendMessageToRLServer(const FString& Message)
{
    // 皋技瘤 傈价
    int32 BytesSent = 0;

    return Socket->Send((uint8*)TCHAR_TO_UTF8(*Message), Message.Len(), BytesSent);
}



