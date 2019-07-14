// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"

UCLASS()
class CPP_STUDY_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* FollowCamera;
public:
	ABaseCharacter();

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		float BaseLookUpRate;

	/** Base Sprint Speed*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Character)
		float SprintSpeed = 800.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Character)
		float BaseSpeed = 400.0f;

	/** Base Variables to Status*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Status)
		float MaxHealth = 100.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Status)
		float CurrentHealth = 100.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Status)
		float Damage = 10.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Status)
		bool EnableMovement = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Status)
		float AttackSpeed = 1.0f;

	/** Base Variables to combat*/

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Combat)
		bool IsAttacking = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Combat)
		float Skill1Cooldown = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Combat)
		float Skill2Cooldown = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Combat)
		float Skill3Cooldown = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Combat)
		float Skill4Cooldown = 0;


	// Skill Inputs
	UFUNCTION(BlueprintNativeEvent, Category = "Skills")
		void Skill1();

	UFUNCTION(BlueprintNativeEvent, Category = "Skills")
		void Skill2();

	UFUNCTION(BlueprintNativeEvent, Category = "Skills")
		void Skill3();

	UFUNCTION(BlueprintNativeEvent, Category = "Skills")
		void Skill4();

	UFUNCTION(BlueprintNativeEvent, Category = "Combat")
		void BaseAttack();


	UFUNCTION(BlueprintCallable, Category = Status)
		void SlowCharacter(float SpeedDivide);

	UFUNCTION(BlueprintCallable, Category = Status)
	    void SpeedCharacter(float SpeedDivide);

	// Sprint Actions

	void Sprint();
	void StopSprint();





protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;






public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Handles input for moving forward and backward.
	UFUNCTION()
		void MoveForward(float Value);

	// Handles input for moving right and left.
	UFUNCTION()
		void MoveRight(float Value);



private:



};