#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CharacterSheet.generated.h"

// =================================================================
// ENUMS (Listy wyborów)
// =================================================================

UENUM(BlueprintType)
enum class EAtributeType : uint8
{
    Strength        UMETA(DisplayName = "Strength"),
    Dexterity       UMETA(DisplayName = "Dexterity"),
    Constitution    UMETA(DisplayName = "Constitution"),
    Intelligence    UMETA(DisplayName = "Intelligence"),
    Wisdom          UMETA(DisplayName = "Wisdom"),
    Charisma        UMETA(DisplayName = "Charisma")
};

UENUM(BlueprintType)
enum class EProficiencyLevel : uint8
{
    None        UMETA(DisplayName = "None"),
    Proficient  UMETA(DisplayName = "Proficient"),
    Expertise   UMETA(DisplayName = "Expertise")
};

UENUM(BlueprintType)
enum class ESkillType : uint8
{
    // Si³a (Strength)
    Athletics       UMETA(DisplayName = "Athletics"),

    // Zrêcznoœæ (Dexterity)
    Acrobatics      UMETA(DisplayName = "Acrobatics"),
    SleightOfHand   UMETA(DisplayName = "Sleight of Hand"),
    Stealth         UMETA(DisplayName = "Stealth"),

    // Inteligencja (Intelligence)
    Arcana          UMETA(DisplayName = "Arcana"),
    History         UMETA(DisplayName = "History"),
    Investigation   UMETA(DisplayName = "Investigation"),
    Nature          UMETA(DisplayName = "Nature"),
    Religion        UMETA(DisplayName = "Religion"),

    // M¹droœæ (Wisdom)
    AnimalHandling  UMETA(DisplayName = "Animal Handling"),
    Insight         UMETA(DisplayName = "Insight"),
    Medicine        UMETA(DisplayName = "Medicine"),
    Perception      UMETA(DisplayName = "Perception"),
    Survival        UMETA(DisplayName = "Survival"),

    // Charyzma (Charisma)
    Deception       UMETA(DisplayName = "Deception"),
    Intimidation    UMETA(DisplayName = "Intimidation"),
    Performance     UMETA(DisplayName = "Performance"),
    Persuasion      UMETA(DisplayName = "Persuasion")
};

UENUM(BlueprintType)
enum class EResistances : uint8
{
    None             UMETA(DisplayName = "None"),
    Resistance       UMETA(DisplayName = "Resistance"),
    Invulnerability  UMETA(DisplayName = "Invulnerability"),
    Vulnerability    UMETA(DisplayName = "Vulnerability")
};

UENUM(BlueprintType)
enum class EWeaponType : uint8
{
    SimpleMelee     UMETA(DisplayName = "Simple Melee Weapons"),
    MartialMelee    UMETA(DisplayName = "Martial Melee Weapons"),
    SimpleRanged    UMETA(DisplayName = "Simple Ranged Weapons"),
    MartialRanged   UMETA(DisplayName = "Martial Ranged Weapons"),
    Club, Dagger, Greatclub, Handaxe, Javelin, LightHammer, Mace, Quarterstaff, Sickle, Spear,
    LightCrossbow, Dart, Shortbow, Sling, Battleaxe, Flail, Glaive, Greataxe, Greatsword,
    Halberd, Lance, Longsword, Maul, Morningstar, Pike, Rapier, Scimitar, Shortsword, Trident,
    WarPick, Warhammer, Whip, Blowgun, HandCrossbow, HeavyCrossbow, Longbow, Net
};

UENUM(BlueprintType)
enum class EArmorType : uint8
{
    Light   UMETA(DisplayName = "Light Armor"),
    Medium  UMETA(DisplayName = "Medium Armor"),
    Heavy   UMETA(DisplayName = "Heavy Armor"),
    Shield  UMETA(DisplayName = "Shield")
};

UENUM(BlueprintType)
enum class EDiceType : uint8
{
    D4, D6, D8, D10, D12, D20
};

// =================================================================
// SUB-STRUCTS (Mniejsze kawa³ki)
// =================================================================

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

USTRUCT(BlueprintType)
struct FActions
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 MaxActions = 1;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 CurrentActions = 1;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 MaxBonusActions = 1;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 CurrentBonusActions = 1;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 MaxReactions = 1;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 CurrentReactions = 1;
};

USTRUCT(BlueprintType)
struct FDamageResistances
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, BlueprintReadWrite) EResistances Piercing = EResistances::None;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) EResistances Slashing = EResistances::None;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) EResistances Bludgeoning = EResistances::None;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) EResistances Acid = EResistances::None;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) EResistances Cold = EResistances::None;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) EResistances Fire = EResistances::None;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) EResistances Force = EResistances::None;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) EResistances Lightning = EResistances::None;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) EResistances Necrotic = EResistances::None;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) EResistances Poison = EResistances::None;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) EResistances Psychic = EResistances::None;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) EResistances Radiant = EResistances::None;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) EResistances Thunder = EResistances::None;
};

USTRUCT(BlueprintType)
struct FSpellSlots
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 Level1_Max;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 Level1_Current;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 Level2_Max;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 Level2_Current;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 Level3_Max;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 Level3_Current;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 Level4_Max;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 Level4_Current;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 Level5_Max;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 Level5_Current;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 Level6_Max;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 Level6_Current;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 Level7_Max;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 Level7_Current;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 Level8_Max;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 Level8_Current;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 Level9_Max;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 Level9_Current;
};

// ===========================
// G£ÓWNA KLASA DANYCH 
// ===========================

UCLASS(BlueprintType, EditInlineNew, DefaultToInstanced)
class PROJECT_VTT_API UCharacterSheet : public UObject
{
    GENERATED_BODY()

public:
    UCharacterSheet();
    ~UCharacterSheet();

    // --- SEKCJA 1: INFO ---
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "1. Info")
    FString CharacterName = "Unknown Hero";

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "1. Info")
    int32 Level = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "1. Info")
    FString Race = "Human";

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "1. Info")
    FString Background;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "1. Info")
    int32 ExperiencePoints = 0;

    // --- SEKCJA 2: STATS ---
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "2. Stats")
    FAbilityScores Stats;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "2. Stats")
    float DarkVisionDistance = 0.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "2. Stats")
    int32 ProficiencyBonus = 2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "2. Stats")
    int32 PassivePerception = 10;

    // --- SEKCJA 3: SKILLS ---
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "3. Skills")
    TMap<EAtributeType, EProficiencyLevel> SavingThrows;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "3. Skills")
    TMap<ESkillType, EProficiencyLevel> SkillProficiencies;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "3. Skills")
    TSet<EWeaponType> WeaponProficiencies;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "3. Skills")
    TSet<EArmorType> ArmorProficiencies;

    // --- SEKCJA 4: COMBAT ---
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "4. Combat")
    FActions Actions;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "4. Combat")
    int32 MaxHP = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "4. Combat")
    int32 CurrentHP = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "4. Combat")
    int32 TemporaryHP = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "4. Combat")
    TMap<EDiceType, int32> TotalHitDices;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "4. Combat")
    TMap<EDiceType, int32> CurrentHitDices;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "4. Combat")
    int32 DeathSaveSuccesses = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "4. Combat")
    int32 DeathSaveFailures = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "4. Combat")
    FDamageResistances Resistances;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "4. Combat")
    float MaxSpeed = 900.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "4. Combat")
    float CurrentSpeed = 900.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "4. Combat")
    int32 ArmorClass = 10;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "4. Combat")
    int32 InitiativeBonus = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "4. Combat")
    bool bInspiration = false;

    // --- SEKCJA 5: MAGIC ---
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "5. Magic")
    FSpellSlots SpellSlots;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "5. Magic")
    int32 SpellSaveDC = 10;
};