// Copyright Aren Kasner 2021

#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "OpenDoor.h"
#include "GameFramework/Actor.h"



// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();
	//UE_LOG(LogTemp,Warning, TEXT("this is the target yaw: %f"),TargetYaw);
	InitalYaw = GetOwner()->GetActorRotation().Yaw;
	CurrentYaw = InitalYaw;
	TargetYaw = InitalYaw + TargetYaw;
	
	if (!PressurePlate) {
	
		UE_LOG(LogTemp, Error, TEXT("%s does not have a pressure plate assinged!"), *GetOwner()->GetName());

	}

	ActorThatOpens = GetWorld()->GetFirstPlayerController()->GetPawn();
	//FRotator CurrentRotation = GetOwner()->GetActorRotation();
	//CurrentRotation.Yaw = -90.f;
	//UE_LOG(LogTemp, Warning, TEXT("this is the target yaw: %s"), *CurrentRotation.ToString());
	//FRotator OpenDoor { 0.f,-90.f,0.f};

	//GetOwner()->SetActorRotation(CurrentRotation);

	// ...

}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (PressurePlate && PressurePlate->IsOverlappingActor(ActorThatOpens)) {

		OpenDoor(DeltaTime);
		DoorLastOpened = GetWorld()->GetTimeSeconds();
	}
	else 
	{
		if (GetWorld()->GetTimeSeconds()-DoorLastOpened>DoorCloseDelay) {
			CloseDoor(DeltaTime);
		}
	}
	//CurrentYaw = GetOwner()->GetActorRotation().Yaw;
	/*FRotator OpenDoor{ 0.f,TargetYaw,0.f };
	 FMath::Lerp(CurrentYaw,TargetYaw,DeltaTime*.5f);
	OpenDoor.Yaw = FMath::FInterpTo(CurrentYaw, TargetYaw, DeltaTime, 2);
	GetOwner()->SetActorRotation(OpenDoor);*/

	// ...
}

void UOpenDoor::OpenDoor(float DeltaTime)
{
	
	CurrentYaw = FMath::FInterpTo(CurrentYaw, TargetYaw, DeltaTime, DoorOpenSpeed);
	FRotator DoorRotaton = GetOwner()->GetActorRotation();

	DoorRotaton.Yaw = CurrentYaw;
	GetOwner()->SetActorRotation(DoorRotaton);
}

void UOpenDoor::CloseDoor(float DeltaTime)
{
	CurrentYaw = FMath::FInterpTo(CurrentYaw, InitalYaw, DeltaTime, DoorCloseSpeed);
	FRotator DoorRotaton = GetOwner()->GetActorRotation();

	DoorRotaton.Yaw = CurrentYaw;
	GetOwner()->SetActorRotation(DoorRotaton);
}

