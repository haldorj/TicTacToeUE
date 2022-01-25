// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MyPawn.generated.h"

UCLASS()
class TICTACTOENEW_API AMyPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMyPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//My designated area
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Mytools)
		class UStaticMeshComponent* StaticMeshComp;

	// Array that keeps spheres in it. Will be 9 elements.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Mytools)
		TArray<UStaticMeshComponent*> SphereArray;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Mytools)
		TArray<int> WhichPlayer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Mytools)
		bool bPlayerTurn;

	// Camera component
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Mytools)
		class UCameraComponent* Camera;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Mytools)
		class USpringArmComponent* SpringArm;

	// Material
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Mytools)
		class UMaterial* BlueMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Mytools)
		class UMaterial* RedMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Mytools)
		class UMaterial* WhiteMaterial;

	UFUNCTION(Category = "UFunctions")
		void OnePressed();

	UFUNCTION(Category = "UFunctions")
		void TwoPressed();

	UFUNCTION(Category = "UFunctions")
		void ThreePressed();

	UFUNCTION(Category = "UFunctions")
		void FourPressed();

	UFUNCTION(Category = "UFunctions")
		void FivePressed();

	UFUNCTION(Category = "UFunctions")
		void SixPressed();

	UFUNCTION(Category = "UFunctions")
		void SevenPressed();

	UFUNCTION(Category = "UFunctions")
		void EightPressed();

	UFUNCTION(Category = "UFunctions")
		void NinePressed();
};