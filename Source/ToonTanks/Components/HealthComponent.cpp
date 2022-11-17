// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"

#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	Health = DefaultHealth;
	GameModeRef = Cast<ATankGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));

	GetOwner()->OnTakeAnyDamage.AddDynamic(this, &UHealthComponent::TakeDamage);
}

void UHealthComponent::TakeDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType,
                                  AController* InstigatedBy, AActor* DamageCauser)
{
	if (Damage == 0 || Health <= 0) return;
	
	Health = FMath::Clamp(Health - Damage, 0.0f, DefaultHealth);
	UE_LOG(LogTemp, Warning, TEXT("Take Damage: %f"), Damage);
	UE_LOG(LogTemp, Warning, TEXT("Current Health: %f"), Health);
	if (Health <= 0)
	{
		if (GameModeRef)
		{
			GameModeRef->ActorDied(GetOwner());
		}
	}

}


// Called every frame
void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                     FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}