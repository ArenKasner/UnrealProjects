// Copyright Aren Kasner 2021

#include "DrawDebugHelpers.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "Grabber.h"

#define OUT

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	// ...

	FindPhysicsHandle();
	SetupInputComponent();

}

void UGrabber::Grab() {



	FHitResult HitResult = GetFirstPhysicsBodyInReach();
	UPrimitiveComponent* ComponentToGrab = HitResult.GetComponent();
	//if we hit something then attach the physics handle
	
	//Todo attach physics handle
	if (HitResult.GetActor()) {
		PhysicsHandle->GrabComponentAtLocation
		(
			ComponentToGrab,
			NAME_None,
			GetPlayersReach()
		);
	}
}
void UGrabber::Release() {
	UE_LOG(LogTemp, Warning, TEXT("Release Pressed"));
	//TODO remove/release the physics handle
	PhysicsHandle->ReleaseComponent();
}
void UGrabber::FindPhysicsHandle()
{	//Check Phisics handle component
	PhysicsHandle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();
	if (PhysicsHandle) {
		//Physics handle is found
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("%s has no physics handle"), *GetOwner()->GetName());
	}
}
void UGrabber::SetupInputComponent()
{
	InputComponent = GetOwner()->FindComponentByClass<UInputComponent>();
	if (InputComponent) {
		InputComponent->BindAction("Grab", IE_Pressed, this, &UGrabber::Grab);
		InputComponent->BindAction("Grab", IE_Released, this, &UGrabber::Release);
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("%s has no Input handler"), *GetOwner()->GetName());
	}
}
FVector UGrabber::GetPlayerWorldPos() const {
	//get player viewpoint
	FVector PlayerViewPointLocaton;
	FRotator PlayerViewPointRotation;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
		OUT PlayerViewPointLocaton,
		OUT PlayerViewPointRotation
	);

	//draw line from player showing the reach
	return PlayerViewPointLocaton;
}
FVector UGrabber::GetPlayersReach() const{
//get player viewpoint
	FVector PlayerViewPointLocaton;
	FRotator PlayerViewPointRotation;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
		OUT PlayerViewPointLocaton,
		OUT PlayerViewPointRotation
	);

	//draw line from player showing the reach
	return PlayerViewPointLocaton + PlayerViewPointRotation.Vector() * Reach;
		

}
void UGrabber::DebugLineFunction(FVector &PlayerViewPointLocation,FVector &LineTraceEnd) const
{
	DrawDebugLine(
		GetWorld(),
		PlayerViewPointLocation,
		LineTraceEnd,
		FColor(0, 255, 0),
		false,
		0.f,
		0,
		5.f
	);
}
FHitResult UGrabber::GetFirstPhysicsBodyInReach() const
{
	
	FHitResult Hit;
	FCollisionQueryParams TraceParams(FName(TEXT("")), false, GetOwner());
	//Ray Cast out to a certant distance (reach)
	GetWorld()->LineTraceSingleByObjectType(
		OUT Hit,
		GetPlayerWorldPos(),
		GetPlayersReach(),
		FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody),
		TraceParams
	);

	return Hit;
}
// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{

	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	//GetPlayerViewpoint

	//If the phyisics handle is attached
		//move the boject we are holding
	if (PhysicsHandle->GrabbedComponent) {
		PhysicsHandle->SetTargetLocation(GetPlayersReach());

	}

	
	// See what it hits

	// ...
}

