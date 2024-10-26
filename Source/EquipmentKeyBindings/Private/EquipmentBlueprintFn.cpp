#include "EquipmentBlueprintFn.h"
#include "FGCharacterPlayer.h"

DEFINE_LOG_CATEGORY(EquipmentKeyBindings);

void UEquipmentBlueprintFn::MultiCycleEquipment(AFGCharacterPlayer* CharacterPlayer, int32 cycles, bool hasAuthority)
{
    UE_LOG(EquipmentKeyBindings, Verbose, TEXT("[EquipmentBlueprintFn] Total Cycles: %d"), cycles);
    UE_LOG(EquipmentKeyBindings, Verbose, TEXT("[EquipmentBlueprintFn] Has Authority? %s"), (hasAuthority ? TEXT("true") : TEXT("false")));

    int32 dir;
    if (cycles > 0) {
        UE_LOG(EquipmentKeyBindings, Verbose, TEXT("[EquipmentBlueprintFn] Cycles > 0"));
        dir = 1;
    }
    else {
        UE_LOG(EquipmentKeyBindings, Verbose, TEXT("[EquipmentBlueprintFn] Cycles < 0"));
        dir = -1;
    }

    while (cycles != 0) {
        if (hasAuthority) {
            UE_LOG(EquipmentKeyBindings, Verbose, TEXT("[EquipmentBlueprintFn][Server] Cycle number: %d"), cycles);
            CharacterPlayer->DoCycleEquipment(dir);
        }
        else {
            UE_LOG(EquipmentKeyBindings, Verbose, TEXT("[EquipmentBlueprintFn][Client] Cycle number: %d"), cycles);
            CharacterPlayer->Server_CycleHandEquipmentPressed(dir);
        }
        cycles = cycles - dir;
        UE_LOG(EquipmentKeyBindings, Verbose, TEXT("[EquipmentBlueprintFn] Cycles updated to: %d"), cycles);
    }
}