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
	SpringArm->TargetArmLength = 400.f;

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