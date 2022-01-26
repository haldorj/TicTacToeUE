// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPawn.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Containers/Array.h"
#include "Camera/CameraComponent.h"

// Sets default values
AMyPawn::AMyPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MainMeshComponent"));
	StaticMeshComp->SetupAttachment(GetRootComponent());
	SphereArray.Init(NULL, 9);
	// 9 is the size of array
	// 0 is all elements empty or 0
	WhichPlayer.Init(0, 9);
	bPlayerTurn = true;

	SphereArray[0] = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Sphere1 MeshComponent"));
	SphereArray[1] = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Sphere2 MeshComponent"));
	SphereArray[2] = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Sphere3 MeshComponent"));
	SphereArray[3] = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Sphere4 MeshComponent"));
	SphereArray[4] = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Sphere5 MeshComponent"));
	SphereArray[5] = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Sphere6 MeshComponent"));
	SphereArray[6] = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Sphere7 MeshComponent"));
	SphereArray[7] = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Sphere8 MeshComponent"));
	SphereArray[8] = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Sphere9 MeshComponent"));

	// Materials
	BlueMaterial = CreateDefaultSubobject<UMaterial>(TEXT("BlueMaterial"));
	RedMaterial = CreateDefaultSubobject<UMaterial>(TEXT("RedMaterial"));
	WhiteMaterial = CreateDefaultSubobject<UMaterial>(TEXT("WhiteMaterial"));

	// Spring arm or camera boom
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(GetRootComponent());
	SpringArm->SetRelativeRotation(FRotator(-50.f,0.f,0.f));
	SpringArm->TargetArmLength = 500.f;

	//Camera
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);

	int ArraySize = WhichPlayer.Num();
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereMesh(TEXT("StaticMesh'/Game/StarterContent/Props/MaterialSphere.MaterialSphere'")); //copy reference

	if (SphereMesh.Succeeded()) {
		for (int i = 0; i < ArraySize; i++) {
			SphereArray[i]->SetStaticMesh(SphereMesh.Object);
			SphereArray[i]->SetMaterial(0, WhiteMaterial);
		}
	}
	SphereArray[0]->SetWorldLocation(FVector(0.f, -150.f, 100.f));
	SphereArray[1]->SetWorldLocation(FVector(0.f, 0.f, 100.f));
	SphereArray[2]->SetWorldLocation(FVector(0.f, 150.f, 100.f));
	SphereArray[3]->SetWorldLocation(FVector(-150.f, -150.f, 100.f));
	SphereArray[4]->SetWorldLocation(FVector(-150.f, 0.f, 100.f));
	SphereArray[5]->SetWorldLocation(FVector(-150.f, 150.f, 100.f));
	SphereArray[6]->SetWorldLocation(FVector(-300.f, -150.f, 100.f));
	SphereArray[7]->SetWorldLocation(FVector(-300.f, 0.f, 100.f));
	SphereArray[8]->SetWorldLocation(FVector(-300.f, 150.f, 100.f));
}

// Called when the game starts or when spawned
void AMyPawn::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AMyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AMyPawn::OnePressed()
{
	
}

void AMyPawn::TwoPressed()
{
}

void AMyPawn::ThreePressed()
{
}

void AMyPawn::FourPressed()
{
}

void AMyPawn::FivePressed()
{
}

void AMyPawn::SixPressed()
{
}

void AMyPawn::SevenPressed()
{
}

void AMyPawn::EightPressed()
{
}

void AMyPawn::NinePressed()
{
}

// Function to check if there is a winner
void AMyPawn::IsWinner()
{
	// Checking rows (Player 1)
	if ((WhichPlayer[0] == 1 && WhichPlayer[1] == 1 && WhichPlayer[2] == 1) ||
		(WhichPlayer[3] == 1 && WhichPlayer[4] == 1 && WhichPlayer[5] == 1) ||
		(WhichPlayer[6] == 1 && WhichPlayer[7] == 1 && WhichPlayer[8] == 1)) {
		if (GEngine) {
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Player 1 won!"));
		}
		UE_LOG(LogTemp, Warning, TEXT(" Player 1 won!"));
	}

	// Checking rows (Player 1)
	if ((WhichPlayer[0] == 2 && WhichPlayer[1] == 2 && WhichPlayer[2] == 2) ||
		(WhichPlayer[3] == 2 && WhichPlayer[4] == 2 && WhichPlayer[5] == 2) ||
		(WhichPlayer[6] == 2 && WhichPlayer[7] == 2 && WhichPlayer[8] == 2)) {
		if (GEngine) {
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Player 2 won!"));
		}
		UE_LOG(LogTemp, Warning, TEXT(" Player 2 won!"));
	}

	// Checking columns (Player 1)
	if ((WhichPlayer[0] == 1 && WhichPlayer[3] == 1 && WhichPlayer[6] == 1) ||
		(WhichPlayer[1] == 1 && WhichPlayer[4] == 1 && WhichPlayer[7] == 1) ||
		(WhichPlayer[2] == 1 && WhichPlayer[5] == 1 && WhichPlayer[8] == 1)) {
		if (GEngine) {
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Player 1 won!"));
		}
		UE_LOG(LogTemp, Warning, TEXT(" Player 1 won!"));
	}

	// Checking columns (Player 2)
	if ((WhichPlayer[0] == 2 && WhichPlayer[3] == 2 && WhichPlayer[6] == 2) ||
		(WhichPlayer[1] == 2 && WhichPlayer[4] == 2 && WhichPlayer[7] == 2) ||
		(WhichPlayer[2] == 2 && WhichPlayer[5] == 2 && WhichPlayer[8] == 2)) {
		if (GEngine) {
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Player 2 won!"));
		}
		UE_LOG(LogTemp, Warning, TEXT(" Player 2 won!"));
	}

	// Checking diagonals (Player 1)
	if ((WhichPlayer[0] == 1 && WhichPlayer[4] == 1 && WhichPlayer[8] == 1) ||
		(WhichPlayer[2] == 1 && WhichPlayer[4] == 1 && WhichPlayer[6] == 1)) {
		if (GEngine) {
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Player 1 won!"));
		}
		UE_LOG(LogTemp, Warning, TEXT(" Player 1 won!"));
	}

	// Checking diagonals (Player 1)
	if ((WhichPlayer[0] == 2 && WhichPlayer[4] == 2 && WhichPlayer[8] == 2) ||
		(WhichPlayer[2] == 2 && WhichPlayer[4] == 2 && WhichPlayer[6] == 2)) {
		if (GEngine) {
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Player 2 won!"));
		}
		UE_LOG(LogTemp, Warning, TEXT(" Player 2 won!"));
	}
}

// TEST MELDING FOR GITHUB