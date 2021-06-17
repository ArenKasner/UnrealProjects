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
	UE_LOG(LogTemp, Warning, TEXT("Grabber Pressed"));
	//Try and reach any actor with physics body collison channel set
	
	
	//get player viewpoint
	FVector PlayerViewPointLocaton;
	FRotator PlayerViewPointRotation;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
		OUT PlayerViewPointLocaton,
		OUT PlayerViewPointRotation
	);

	//draw line from player showing the reach
	FVector LineTraceEnd = PlayerViewPointLocaton + PlayerViewPointRotation.Vector() * Reach;


	FHitResult HitResult = GetFirstPhysicsBodyInReach();
	UPrimitiveComponent* ComponentToGrab = HitResult.GetComponent();
	//if we hit something then attach the physics handle
	
	//Todo attach physics handle
	if (HitResult.GetActor()) {
		PhysicsHandle->GrabComponentAtLocation
		(
			ComponentToGrab,
			NAME_None,
			LineTraceEnd
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
	//get player viewpoint
	FVector PlayerViewPointLocaton;
	FRotator PlayerViewPointRotation;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
		OUT PlayerViewPointLocaton,
		OUT PlayerViewPointRotation
	);

	//draw line from player showing the reach
	FVector LineTraceEnd = PlayerViewPointLocaton + PlayerViewPointRotation.Vector() * Reach;
		DebugLineFunction(LineTraceEnd, PlayerViewPointLocaton);
	FHitResult Hit;
	FCollisionQueryParams TraceParams(FName(TEXT("")), false, GetOwner());
	//Ray Cast out to a certant distance (reach)
	GetWorld()->LineTraceSingleByObjectType(
		OUT Hit,
		PlayerViewPointLocaton,
		LineTraceEnd,
		FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody),
		TraceParams
	);
	AActor* ActorHit = Hit.GetActor();
	if (ActorHit) {

		UE_LOG(LogTemp, Warning, TEXT("%s is hit."), *(ActorHit->GetName()));
	}
	return Hit;
}
// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{

	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	//GetPlayerViewpoint
	FVector PlayerViewPointLocaton;
	FRotator PlayerViewPointRotation;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
		OUT PlayerViewPointLocaton,
		OUT PlayerViewPointRotation
	);

	//draw line from player showing the reach
	FVector LineTraceEnd = PlayerViewPointLocaton + PlayerViewPointRotation.Vector() * Reach;
	//If the phyisics handle is attached
		//move the boject we are holding
	if (PhysicsHandle->GrabbedComponent) {
		PhysicsHandle->SetTargetLocation(LineTraceEnd);

	}

	
	// See what it hits

	// ...
}

