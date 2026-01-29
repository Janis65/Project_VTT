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

// Odpornoœci
UENUM(BlueprintType)
enum class EResistances : uint8
{
    None                UMETA(DisplayName = "None"),
    Resistance          UMETA(DisplayName = "Resistance"),
    Invulnerability     UMETA(DisplayName = "Invulnerability"),
    Vulnerability       UMETA(DisplayName = "Vulnerability")
};

// Rodzaje broni
UENUM(BlueprintType)
enum class EWeaponType : uint8
{
    // --- Kategorie Ogólne (jeœli postaæ ma bieg³oœæ w ca³ej grupie) ---
    SimpleMelee     UMETA(DisplayName = "Simple Melee Weapons"),
    MartialMelee    UMETA(DisplayName = "Martial Melee Weapons"),
    SimpleRanged    UMETA(DisplayName = "Simple Ranged Weapons"),
    MartialRanged   UMETA(DisplayName = "Martial Ranged Weapons"),

    // --- Konkretne Bronie ---
    Club,
    Dagger,
    Greatclub,
    Handaxe,
    Javelin,
    LightHammer,
    Mace,
    Quarterstaff,
    Sickle,
    Spear,
    LightCrossbow,
    Dart,
    Shortbow,
    Sling,
    Battleaxe,
    Flail,
    Glaive,
    Greataxe,
    Greatsword,
    Halberd,
    Lance,
    Longsword,
    Maul,
    Morningstar,
    Pike,
    Rapier,
    Scimitar,
    Shortsword,
    Trident,
    WarPick,
    Warhammer,
    Whip,
    Blowgun,
    HandCrossbow,
    HeavyCrossbow,
    Longbow,
    Net
};

// Rodzaje pancerzy
UENUM(BlueprintType)
enum class EArmorType : uint8
{
    Light       UMETA(DisplayName = "Light Armor"),
    Medium      UMETA(DisplayName = "Medium Armor"),
    Heavy       UMETA(DisplayName = "Heavy Armor"),
    Shield      UMETA(DisplayName = "Shield")
};

// Klasy
UENUM(BlueprintType)
enum class ECharacterClass : uint8
{
    None        UMETA(DisplayName = "None"),
    Barbarian   UMETA(DisplayName = "Barbarian"),
    Bard        UMETA(DisplayName = "Bard"),
    Cleric      UMETA(DisplayName = "Cleric"),
    Druid       UMETA(DisplayName = "Druid"),
    Fighter     UMETA(DisplayName = "Fighter"),
    Monk        UMETA(DisplayName = "Monk"),
    Paladin     UMETA(DisplayName = "Paladin"),
    Ranger      UMETA(DisplayName = "Ranger"),
    Rogue       UMETA(DisplayName = "Rogue"),
    Sorcerer    UMETA(DisplayName = "Sorcerer"),
    Warlock     UMETA(DisplayName = "Warlock"),
    Wizard      UMETA(DisplayName = "Wizard")
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

// Rodzaje koœci
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

// 2. Rzuty Obronne (Saving Throws) - Flagi czy jest bieg³oœæ
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

// 3. Umiejêtnoœci (Skills) - Flagi czy jest bieg³oœæ
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

// 4. Akcje (Actions)
USTRUCT(BlueprintType)
struct FActions
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 MaxActions;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 CurrentActions;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 MaxBonusActions;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 CurrentBonusActions;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 MaxReactions;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 CurrentReactions;
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
    UPROPERTY(EditAnywhere, BlueprintReadWrite) TMap<EDiceType, int32> TotalHitDices;     // Np. 5 k6, 2 k8
    UPROPERTY(EditAnywhere, BlueprintReadWrite) TMap<EDiceType, int32> CurrentHitDices;   // Np. 3 k6, 0 k8

    // Rzuty na œmieræ (Death Saves)
    UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 DeathSaveSuccesses; // 0-3
    UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 DeathSaveFailures;  // 0-3
};

// 6. Odpornoœci (Resistances) - Flagi czy jest odporny
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

// 7. Czary (Spell Slots)
USTRUCT(BlueprintType)
struct FSpellSlots
{
    GENERATED_BODY()

    // Poziomy 1-9
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

// ============================
// G£ÓWNA STRUKTURA POSTACI 
// ============================

USTRUCT(BlueprintType)
struct FDnD_Character_Sheet
{
    GENERATED_BODY()

    // Sekcja 1: Info
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "1. Info")
    FString CharacterName = "Unknown Hero";

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "1. Info")
    FString Level = "1";

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "1. Info")
    TMap<ECharacterClass, int32> ClassLevels;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "1. Info")
    FString Race = "Human";

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "1. Info")
    FString Background;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "1. Info")
    EAlignment Alignment;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "1. Info")
    int32 ExperiencePoints = 0;

    // Sekcja 2: Stats
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "2. Stats")
    FAbilityScores Stats;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "2. Stats")
    float DarkVisionDistance = 0.0f; // w cm (9 metrów = 30 stóp)

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "2. Stats")
    int32 ProficiencyBonus = 2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "3. Skills")
    int32 PassivePerception = 10;

    // Sekcja 3: Skills
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "3. Skills")
    FSavingThrows SavingThrows;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "3. Skills")
    FSkillProficiencies SkillProficiencies;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "3. Skills")
    TSet<EWeaponType> WeaponProficiencies;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "3. Skills")
    TSet<EArmorType> ArmorProficiencies;

    // Sekcja 4: Combat
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "4. Combat")
    FActions Actions;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "4. Combat")
    FVitals Vitals;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "4. Combat")
    FDamageResistances Resistances;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "4. Combat")
    float MaxSpeed; // w cm (900.0f = 9 metrów = 30 stóp)

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "4. Combat")
    float CurrentSpeed; // w cm (9 metrów = 30 stóp)

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "4. Combat")
    int32 ArmorClass = 10;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "4. Combat")
    int32 InitiativeBonus = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "4. Combat")
    bool bInspiration = false;

    // Sekcja 5: Magic
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "5. Magic")
    FSpellSlots SpellSlots;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "5. Magic") int32 SpellSaveDC = 10;

    // UWAGA: Ekwipunek (Inventory) zazwyczaj robi siê jako oddzieln¹ tablicê aktorów lub struktur itemów,
    // wiêc nie wrzucam go tutaj, ¿eby nie komplikowaæ pliku.
};

// ======================================================================
// Pusta klasa wymagana przez Unreal, aby plik nag³ówkowy dzia³a³
// ======================================================================

UCLASS()
class PROJECT_VTT_API UCharacterSheet : public UObject
{
    GENERATED_BODY()

public:
    UCharacterSheet();
    ~UCharacterSheet();
};