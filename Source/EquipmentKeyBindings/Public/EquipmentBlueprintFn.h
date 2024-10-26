#pragma once

#include "CoreMinimal.h"
#include "FGCharacterPlayer.h"
#include "EquipmentBlueprintFn.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(EquipmentKeyBindings, Verbose, All);

UCLASS()
class UEquipmentBlueprintFn : public UBlueprintFunctionLibrary
{	
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "CharacterPlayer")
	static void MultiCycleEquipment(AFGCharacterPlayer* CharacterPlayer, int32 cycles, bool hasAuthority);
};