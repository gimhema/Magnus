// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Sockets.h"
#include "SocketSubsystem.h"
#include "SocketSubsystemModule.h"
#include "IPAddress.h"
#include "RLServerConnector.generated.h"

UCLASS()
class UNREALCLIENT_API ARLServerConnector : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARLServerConnector();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:

	UPROPERTY(BlueprintReadWrite)
	FString RLServerIP = TEXT("");
	UPROPERTY(BlueprintReadWrite)
	int32 RLServerPort = 0;

	FSocketSubsystemModule& SocketSubsystem = FModuleManager::LoadModuleChecked<FSocketSubsystemModule>("SocketSubsystem");
	ISocketSubsystem* SocketSubsystemPtr;
	FSocket* Socket;

public:
	UFUNCTION()
	void InitSocketSystem();

	UFUNCTION()
	void CreateSocket();

	UFUNCTION()
	bool SendMessageToRLServer(const FString& Message);
};
