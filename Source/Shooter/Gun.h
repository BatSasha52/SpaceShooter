// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Gun.generated.h"

UCLASS()
class SHOOTER_API AGun : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGun();

	void PullTrigger();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(VisibleAnywhere, Category = "Components")
	class USceneComponent* Root;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	class USkeletalMeshComponent* Mesh;

	UPROPERTY(EditAnywhere, Category = "Effects")
	UParticleSystem* MuzzleFlashEffect;

	UPROPERTY(EditAnywhere, Category = "Effects")
	USoundBase* MuzzleSound;

	UPROPERTY(EditAnywhere, Category = "Effects")
	USoundBase* BulletHitSound;

	UPROPERTY(EditAnywhere, Category = "Effects")
	UParticleSystem* BulletHitEffect;

	UPROPERTY(EditAnywhere)
	float MaxRange{ 3000.f };

	UPROPERTY(EditAnywhere)
	float Damage{ 15.f };

	bool GunTrace(FHitResult& Hit, FVector& ShotDirection);

	AController* GetOwnerController() const;

};
