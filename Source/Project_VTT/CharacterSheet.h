#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CharacterSheet.generated.h"

// =================================================================
// ENUMS (Listy wyborów)
// =================================================================

// Poziom bieg³oœci (np. w umiejêtnoœciach)
UENUM(BlueprintType)
enum class EProficiencyLevel : uint8
{
    None        UMETA(DisplayName = "None"),
    Proficient  UMETA(DisplayName = "Proficient"),
    Expertise   UMETA(DisplayName = "Expertise")
};

// Charakter postaci (Alignment)
UENUM(BlueprintType)
enum class EAlignment : uint8
{
    LawfulGood,
    NeutralGood,
    ChaoticGood,
    LawfulNeutral,
    TrueNeutral,
    ChaoticNeutral,
    LawfulEvil,
    NeutralEvil,
    ChaoticEvil
};

// Rodzaje koœci (do Hit Dice i broni)
UENUM(BlueprintType)
enum class EDiceType : uint8
{
    D4, D6, D8, D10, D12, D20
};

// =================================================================
// SUB-STRUCTS (Mniejsze kawa³ki karty dla porz¹dku)
// =================================================================

// 1. G³ówne Atrybuty (Stats)
USTRUCT(BlueprintType)
struct FAbilityScores
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 Strength = 10;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 Dexterity = 10;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 Constitution = 10;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 Intelligence = 10;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 Wisdom = 10;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 Charisma = 10;
};

// 2. Klasy postaci (Classes)
USTRUCT(BlueprintType)
struct FClasses
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 Barbarian = 0;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 Bard = 0;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 Cleric = 0;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 Druid = 0;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 Fighter = 0;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 Monk = 0;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 Paladin = 0;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 Ranger = 0;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 Rogue = 0;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 Sorcerer = 0;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 Warlock = 0;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 Wizard = 0;
};

// 3. Rzuty Obronne (Saving Throws) - Flagi czy jest bieg³oœæ
USTRUCT(BlueprintType)
struct FSavingThrows
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite) EProficiencyLevel Strength = EProficiencyLevel::None;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) EProficiencyLevel Dexterity = EProficiencyLevel::None;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) EProficiencyLevel Constitution = EProficiencyLevel::None;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) EProficiencyLevel Intelligence = EProficiencyLevel::None;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) EProficiencyLevel Wisdom = EProficiencyLevel::None;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) EProficiencyLevel Charisma = EProficiencyLevel::None;
};

// 4. Umiejêtnoœci (Skills) - Flagi czy jest bieg³oœæ
USTRUCT(BlueprintType)
struct FSkillProficiencies
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite) EProficiencyLevel Acrobatics = EProficiencyLevel::None;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) EProficiencyLevel AnimalHandling = EProficiencyLevel::None;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) EProficiencyLevel Arcana = EProficiencyLevel::None;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) EProficiencyLevel Athletics = EProficiencyLevel::None;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) EProficiencyLevel Deception = EProficiencyLevel::None;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) EProficiencyLevel History = EProficiencyLevel::None;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) EProficiencyLevel Insight = EProficiencyLevel::None;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) EProficiencyLevel Intimidation = EProficiencyLevel::None;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) EProficiencyLevel Investigation = EProficiencyLevel::None;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) EProficiencyLevel Medicine = EProficiencyLevel::None;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) EProficiencyLevel Nature = EProficiencyLevel::None;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) EProficiencyLevel Perception = EProficiencyLevel::None;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) EProficiencyLevel Performance = EProficiencyLevel::None;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) EProficiencyLevel Persuasion = EProficiencyLevel::None;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) EProficiencyLevel Religion = EProficiencyLevel::None;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) EProficiencyLevel SleightOfHand = EProficiencyLevel::None;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) EProficiencyLevel Stealth = EProficiencyLevel::None;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) EProficiencyLevel Survival = EProficiencyLevel::None;
};

// 5. ¯ycie i Œmieræ (Vitals)
USTRUCT(BlueprintType)
struct FVitals
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 MaxHP;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 CurrentHP;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 TemporaryHP;

    // Koœci Wytrzyma³oœci (Hit Dice)
    UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 TotalHitDice;     // Np. 5
    UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 CurrentHitDice;   // Np. 3
    UPROPERTY(EditAnywhere, BlueprintReadWrite) EDiceType HitDiceType;  // Np. D8

    // Rzuty na œmieræ (Death Saves)
    UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 DeathSaveSuccesses; // 0-3
    UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 DeathSaveFailures;  // 0-3
};

// 6. Pieni¹dze (Currency)
USTRUCT(BlueprintType)
struct FCurrency
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 Copper = 0;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 Silver = 0;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 Gold = 0;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 Platinum = 0;
};

// ============================
// G£ÓWNA STRUKTURA POSTACI 
// ============================

USTRUCT(BlueprintType)
struct FDnD_Character_Sheet
{
    GENERATED_BODY()

    // Sekcja 1: Informacje Fabularne
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "1. Info")
    FString CharacterName = "Unknown Hero";

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "1. Info")
    FString Level = "1";

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "1. Info")
    FClasses ClassLevels;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "1. Info")
    FString Race = "Human";

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "1. Info")
    FString Background;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "1. Info")
    EAlignment Alignment;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "1. Info")
    int32 ExperiencePoints = 0;

    // Sekcja 2: Statystyki G³ówne (STR, DEX...)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "2. Attributes")
    FAbilityScores Abilities;

    // Sekcja 3: Walka i Przetrwanie
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "3. Combat")
    FVitals Vitals;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "3. Combat")
    int32 ArmorClass = 10;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "3. Combat")
    int32 InitiativeBonus = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "3. Combat")
    float Speed = 900.0f; // w cm (9 metrów = 30 stóp)

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "3. Combat")
    int32 ProficiencyBonus = 2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "3. Combat")
    bool bInspiration = false;

    // --- Sekcja 4: Umiejêtnoœci ---
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "4. Skills")
    FSavingThrows SavingThrows;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "4. Skills")
    FSkillProficiencies Skills;

    // --- Sekcja 5: Pieni¹dze ---
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "5. Inventory")
    FCurrency Wallet;

    // UWAGA: Ekwipunek (Inventory) zazwyczaj robi siê jako oddzieln¹ tablicê aktorów lub struktur itemów,
    // wiêc nie wrzucam go tutaj, ¿eby nie komplikowaæ pliku.
};

/**
 * Pusta klasa wymagana przez Unreal, aby plik nag³ówkowy dzia³a³
 */
UCLASS()
class PROJECT_VTT_API UCharacterSheet : public UObject
{
    GENERATED_BODY()

public:
    UCharacterSheet();
    ~UCharacterSheet();
};