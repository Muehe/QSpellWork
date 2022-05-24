#pragma once

#include <QObject>

#include "../../../qsw.h"

#define MAX_SPELL_REAGENTS 8
#define MAX_SPELL_TOTEMS   2
#define MAX_EFFECT_INDEX   3

#if defined( __GNUC__ )
#pragma pack(1)
#else
#pragma pack(push,1)
#endif


namespace SkillLine
{
    struct entry
    {
        quint32 id;                                          // 0 index
        qint32  categoryId;                                  // 1 index from SkillLineCategory.dbc
        quint32 skillCostId;                                 // 2 not used
        quint32 nameOffset;                                  // 3
        quint32 nameLocalizedOffset[15];                     // 4-18 always empty, not used
        quint32 nameFlags;                                   // 19 not used
        quint32 descriptionOffset;                           // 20
        quint32 descriptionLocalizedOffset[15];              // 21-35 always empty, not used
        quint32 descriptionFlags;                            // 36 not used
        quint32 spellIcon;                                   // 37
        quint32 verbOffset;                                  // 38
        quint32 verbLocalizedOffset[15];                     // 39-53 always empty, not used
        quint32 verbFlags;                                   // 54 not used
        quint32 vanLink;                                     // 55

        const QString name() const;
        const QString description() const;
        const QString verb() const;
    };

    DBCFile& getDbc();
    quint32 getRecordCount();
    const entry* getRecord(quint32 id, bool realId = false);
}

namespace SkillLineAbility
{
    struct entry
    {
        quint32 id;                                              // 0 index
        quint32 skillId;                                         // 1
        quint32 spellId;                                         // 2
        quint32 raceMask;                                        // 3
        quint32 classMask;                                       // 4
        quint32 excludeRaceMask;                                 // 5
        quint32 excludeClassMask;                                // 6
        quint32 requiredSkillValue;                              // 7 for trade skill.not for training.
        quint32 forwardSpellId;                                  // 8
        quint32 learnOnGetSkill;                                 // 9 can be 1 or 2 for spells learned on get skill
        quint32 maxValue;                                        // 10
        quint32 minValue;                                        // 11
        quint32 charPoints[2];                                   // 12-13
    };

    DBCFile& getDbc();
    quint32 getRecordCount();
    const entry* getRecord(quint32 id, bool realId = false);
}

namespace SpellDifficulty
{
    struct entry
    {
        quint32    id;                                              // 0
        quint32    spellId[4];
    };

    DBCFile& getDbc();
    quint32 getRecordCount();
    const entry* getRecord(quint32 id, bool realId = false);
}

namespace SpellRuneCost
{
    struct entry
    {
        quint32    id;                                              // 0
        quint32    runeCost[3];
        quint32    runePowerGain;
    };

    DBCFile& getDbc();
    quint32 getRecordCount();
    const entry* getRecord(quint32 id, bool realId = false);
}

namespace SpellDuration
{
    struct entry
    {
        quint32    id;
        qint32     duration;
        qint32     durationPerLevel;
        qint32     maxDuration;
    };

    DBCFile& getDbc();
    quint32 getRecordCount();
    const entry* getRecord(quint32 id, bool realId = false);
}

namespace SpellCastTimes
{
    struct entry
    {
        quint32    id;                                              // 0
        qint32     castTime;                                        // 1
        qint32     castTimePerLevel;                                // 2 unsure / per skill?
        qint32     minCastTime;                                     // 3 unsure
    };

    DBCFile& getDbc();
    quint32 getRecordCount();
    const entry* getRecord(quint32 id, bool realId = false);
}

namespace SpellRadius
{
    struct entry
    {
        quint32    id;                                              // 0
        float      radius;                                          // 1
        float      radiusPerLevel;                                  // 2
        float      maxRadius;                                       // 3
    };

    DBCFile& getDbc();
    quint32 getRecordCount();
    const entry* getRecord(quint32 id, bool realId = false);
}

namespace SpellRange
{
    struct entry
    {
        quint32     id;                                              // 0
        float       minRange;                                        // 1
        float       minRangeFriendly;                                // 2
        float       maxRange;                                        // 3
        float       maxRangeFriendly;                                // 4
        quint32     flags;                                           // 5
        quint32     nameOffset;                                      // 6
        quint32     nameLocalizedOffset[15];                         // 7-21 always empty, not used
        quint32     nameFlags;                                       // 22 not used
        quint32     shortNameOffset;                                 // 23
        quint32     shortNameLocalizedOffset[15];                    // 24-38 always empty, not used
        quint32     shortNameFlags;                                  // 39 not used

        const QString name() const;
        const QString shortName() const;
    };

    DBCFile& getDbc();
    quint32 getRecordCount();
    const entry* getRecord(quint32 id, bool realId = false);
}

namespace SpellIcon
{
    struct entry
    {
        quint32 id;                                     // 0 Id
        quint32 iconPathOffset;                         // 1 Path offset

        const QString iconPath() const;
    };

    DBCFile& getDbc();
    quint32 getRecordCount();
    const entry* getRecord(quint32 id, bool realId = false);
}

namespace Spell
{
    class meta;

    struct entry
    {
        quint32    id;                                              // 0 normally counted from 0 field (but some tools start counting from 1, check this before tool use for data view!)
        quint32    category;                                        // 1
        quint32    dispel;                                          // 2
        quint32    mechanic;                                        // 3
        quint32    attributes;                                      // 4
        quint32    attributesEx1;                                   // 5
        quint32    attributesEx2;                                   // 6
        quint32    attributesEx3;                                   // 7
        quint32    attributesEx4;                                   // 8
        quint32    attributesEx5;                                   // 9
        quint32    attributesEx6;                                   // 10
        quint32    attributesEx7;                                   // 11
        quint64    stances;                                         // 12-13
        quint64    stancesNot;                                      // 14-15
        quint32    targets;                                         // 16
        quint32    targetCreatureType;                              // 17
        quint32    requiresSpellFocus;                              // 18
        quint32    facingCasterFlags;                               // 19
        quint32    casterAuraState;                                 // 20
        quint32    targetAuraState;                                 // 21
        quint32    casterAuraStateNot;                              // 22
        quint32    targetAuraStateNot;                              // 23
        quint32    casterAuraSpell;                                 // 24
        quint32    targetAuraSpell;                                 // 25
        quint32    excludeCasterAuraSpell;                          // 26
        quint32    excludeTargetAuraSpell;                          // 27
        quint32    castingTimeIndex;                                // 28
        quint32    recoveryTime;                                    // 29
        quint32    categoryRecoveryTime;                            // 30
        quint32    interruptFlags;                                  // 31
        quint32    auraInterruptFlags;                              // 32
        quint32    channelInterruptFlags;                           // 33
        quint32    procFlags;                                       // 34
        quint32    procChance;                                      // 35
        quint32    procCharges;                                     // 36
        quint32    maxLevel;                                        // 37
        quint32    baseLevel;                                       // 38
        quint32    spellLevel;                                      // 39
        quint32    durationIndex;                                   // 40
        qint32     powerType;                                       // 41
        quint32    manaCost;                                        // 42
        quint32    manaCostPerlevel;                                // 43
        quint32    manaPerSecond;                                   // 44
        quint32    manaPerSecondPerLevel;                           // 45
        quint32    rangeIndex;                                      // 46
        float      speed;                                           // 47
        quint32    modalNextSpell;                                  // 48 not used
        quint32    stackAmount;                                     // 49
        quint32    totem[MAX_SPELL_TOTEMS];                         // 50-51
        qint32     reagent[MAX_SPELL_REAGENTS];                     // 52-59
        quint32    reagentCount[MAX_SPELL_REAGENTS];                // 60-67
        qint32     equippedItemClass;                               // 68 (value)
        qint32     equippedItemSubClassMask;                        // 69 (mask)
        qint32     equippedItemInventoryTypeMask;                   // 70 (mask)
        quint32    effect[MAX_EFFECT_INDEX];                        // 71-73
        quint32    effectDieSides[MAX_EFFECT_INDEX];                // 74-76
        float      effectRealPointsPerLevel[MAX_EFFECT_INDEX];      // 77-79
        qint32     effectBasePoints[MAX_EFFECT_INDEX];              // 80-82 (don't must be used in spell/auras explicitly, must be used cached Spell::m_currentBasePoints)
        quint32    effectMechanic[MAX_EFFECT_INDEX];                // 83-85
        quint32    effectImplicitTargetA[MAX_EFFECT_INDEX];         // 86-88
        quint32    effectImplicitTargetB[MAX_EFFECT_INDEX];         // 89-91
        quint32    effectRadiusIndex[MAX_EFFECT_INDEX];             // 92-94 - spellradius.dbc
        quint32    effectApplyAuraName[MAX_EFFECT_INDEX];           // 95-97
        quint32    effectAmplitude[MAX_EFFECT_INDEX];               // 98-100
        float      effectMultipleValue[MAX_EFFECT_INDEX];           // 101-103
        quint32    effectChainTarget[MAX_EFFECT_INDEX];             // 104-106
        quint32    effectItemType[MAX_EFFECT_INDEX];                // 107-109
        qint32     effectMiscValueA[MAX_EFFECT_INDEX];              // 110-112
        qint32     effectMiscValueB[MAX_EFFECT_INDEX];              // 113-115
        quint32    effectTriggerSpell[MAX_EFFECT_INDEX];            // 116-118
        float      effectPointsPerComboPoint[MAX_EFFECT_INDEX];     // 119-121
        quint32    effectSpellClassMaskA[3];                        // 122-124  m_effectSpellClassMaskA, effect 0
        quint32    effectSpellClassMaskB[3];                        // 125-127  m_effectSpellClassMaskB, effect 1
        quint32    effectSpellClassMaskC[3];                        // 128-130  m_effectSpellClassMaskC, effect 2
        quint32    spellVisual;                                     // 131
        quint32    spellVisual2;                                    // 132
        quint32    spellIconId;                                     // 133
        quint32    activeIconId;                                    // 134
        quint32    spellPriority;                                   // 135
        quint32    nameOffset;                                      // 136
        quint32    nameLocalizedOffset[15];                         // 137-151 always empty, not used
        quint32    nameFlag;                                        // 152 not used
        quint32    rankOffset;                                      // 153
        quint32    rankLocalizedOffset[15];                         // 154-168 always empty, not used
        quint32    rankFlags;                                       // 169 not used
        quint32    descriptionOffset;                               // 170
        quint32    descriptionLocalizedOffset[15];                  // 171-185 always empty, not used
        quint32    descriptionFlags;                                // 186 not used
        quint32    toolTipOffset;                                   // 187
        quint32    toolTipLocalizedOffset[15];                      // 188-202 always empty, not used
        quint32    toolTipFlags;                                    // 203 not used
        quint32    manaCostPercentage;                              // 204
        quint32    startRecoveryCategory;                           // 205
        quint32    startRecoveryTime;                               // 206
        quint32    maxTargetLevel;                                  // 207
        quint32    spellFamilyName;                                 // 208
        quint32    spellFamilyFlags[3];                             // 209-211
        quint32    maxAffectedTargets;                              // 212
        quint32    damageClass;                                     // 213 defenseType
        quint32    preventionType;                                  // 214
        qint32     stanceBarOrder;                                  // 215 not used
        float      damageMultiplier[MAX_EFFECT_INDEX];              // 216-218
        quint32    minFactionId;                                    // 219 not used, and 0 in 2.4.2
        quint32    minReputation;                                   // 220 not used, and 0 in 2.4.2
        quint32    requiredAuraVision;                              // 221 not used
        quint32    totemCategory[MAX_SPELL_TOTEMS];                 // 222-223
        quint32    areaId;                                          // 224
        quint32    schoolMask;                                      // 225 school mask
        quint32    runeCostId;                                      // 226
        quint32    spellMissileId;                                  // 227
        quint32    powerDisplayId;                                  // 228
        float      effectBonusMultiplier[3];                        // 229-231
        quint32    spellDescriptionVariableId;                      // 232
        quint32    spellDifficultyId;                               // 233

        const QString name() const;
        const QString description() const;
        const QString rank() const;
        const QString toolTip() const;
        const QString nameWithRank() const;

        quint32 getAmplitude() const
        {
            for (quint8 i = 0; i < MAX_EFFECT_INDEX; ++i)
                if (effectAmplitude[i])
                    return quint32(effectAmplitude[i] / 1000);

            return 0;
        }

        quint32 getAmplitude(quint8 index) const
        {
            return quint32(effectAmplitude[index] / 1000);
        }

        qint32 getDuration() const
        {
            const SpellDuration::entry* durationInfo = SpellDuration::getRecord(durationIndex, true);
            if (durationInfo)
                return qint32(durationInfo->duration / 1000);

            return 0;
        }

        float getRadius(quint8 index) const
        {
            if (const SpellRadius::entry* spellRadius = SpellRadius::getRecord(effectRadiusIndex[index], true))
                return spellRadius->radius;

            return 0.0f;
        }

        quint32 getTicks(quint8 index) const
        {
            return quint32(getDuration() / (effectAmplitude[index] ? quint32(effectAmplitude[index] / 1000) : getDuration()));
        }

        qint32 getTriggerDuration(quint8 index) const;
    };

    DBCFile &getDbc();
    quint32 getRecordCount();
    const entry* getRecord(quint32 id, bool realId = false);

    quint32 getMetaSpellCount();
    meta* getMetaSpell(quint32 id, bool realId = false);
    const entry* getMetaRecord(quint32 id, bool realId = false);

    class meta : public QObject
    {
        Q_OBJECT

        public:

            meta(const entry* info) : m_info(info), m_destroyInfo(false) {}

            ~meta()
            {
                if (m_destroyInfo)
                {
                    delete m_info;
                    m_info = nullptr;
                }
            }

            void setSpellInfo(entry* info)
            {
                m_info = info;
                m_destroyInfo = true;
            }

            // Addition properties
            quint8 getServerSide() { return m_serverSide; }
            void setServerSide(quint8 value) { m_serverSide = value; }

            const entry* getInfo() const { Q_ASSERT(m_info); return m_info; }

        public slots:

        quint32 Id() { return m_info->id; }
        quint32 Category() { return m_info->category; }
        quint32 Dispel() { return m_info->dispel; }
        quint32 Mechanic() { return m_info->mechanic; }
        quint32 Attributes() { return m_info->attributes; }
        quint32 AttributesEx1() { return m_info->attributesEx1; }
        quint32 AttributesEx2() { return m_info->attributesEx2; }
        quint32 AttributesEx3() { return m_info->attributesEx3; }
        quint32 AttributesEx4() { return m_info->attributesEx4; }
        quint32 AttributesEx5() { return m_info->attributesEx5; }
        quint32 AttributesEx6() { return m_info->attributesEx6; }
        quint32 AttributesEx7() { return m_info->attributesEx7; }
        quint64 Stances() { return m_info->stances; }
        quint64 StancesNot() { return m_info->stancesNot; }
        quint32 Targets() { return m_info->targets; }
        quint32 TargetCreatureType() { return m_info->targetCreatureType; }
        quint32 RequiresSpellFocus() { return m_info->requiresSpellFocus; }
        quint32 FacingCasterFlags() { return m_info->facingCasterFlags; }
        quint32 CasterAuraState() { return m_info->casterAuraState; }
        quint32 TargetAuraState() { return m_info->targetAuraState; }
        quint32 CasterAuraStateNot() { return m_info->casterAuraStateNot; }
        quint32 TargetAuraStateNot() { return m_info->targetAuraStateNot; }
        quint32 CasterAuraSpell() { return m_info->casterAuraSpell; }
        quint32 TargetAuraSpell() { return m_info->targetAuraSpell; }
        quint32 ExcludeCasterAuraSpell() { return m_info->excludeCasterAuraSpell; }
        quint32 ExcludeTargetAuraSpell() { return m_info->excludeTargetAuraSpell; }
        quint32 CastingTimeIndex() { return m_info->castingTimeIndex; }
        quint32 RecoveryTime() { return m_info->recoveryTime; }
        quint32 CategoryRecoveryTime() { return m_info->categoryRecoveryTime; }
        quint32 InterruptFlags() { return m_info->interruptFlags; }
        quint32 AuraInterruptFlags() { return m_info->auraInterruptFlags; }
        quint32 ChannelInterruptFlags() { return m_info->channelInterruptFlags; }
        quint32 ProcFlags() { return m_info->procFlags; }
        quint32 ProcChance() { return m_info->procChance; }
        quint32 ProcCharges() { return m_info->procCharges; }
        quint32 MaxLevel() { return m_info->maxLevel; }
        quint32 BaseLevel() { return m_info->baseLevel; }
        quint32 SpellLevel() { return m_info->spellLevel; }
        quint32 DurationIndex() { return m_info->durationIndex; }
        qint32 PowerType() { return m_info->powerType; }
        quint32 ManaCost() { return m_info->manaCost; }
        quint32 ManaCostPerlevel() { return m_info->manaCostPerlevel; }
        quint32 ManaPerSecond() { return m_info->manaPerSecond; }
        quint32 ManaPerSecondPerLevel() { return m_info->manaPerSecondPerLevel; }
        quint32 RangeIndex() { return m_info->rangeIndex; }
        float Speed() { return m_info->speed; }
        quint32 ModalNextSpell() { return m_info->modalNextSpell; }
        quint32 StackAmount() { return m_info->stackAmount; }
        quint32 Totem(quint8 index) { return m_info->totem[index]; }
        qint32 Reagent(quint8 index) { return m_info->reagent[index]; }
        quint32 ReagentCount(quint8 index) { return m_info->reagentCount[index]; }
        qint32 EquippedItemClass() { return m_info->equippedItemClass; }
        qint32 EquippedItemSubClassMask() { return m_info->equippedItemSubClassMask; }
        qint32 EquippedItemInventoryTypeMask() { return m_info->equippedItemInventoryTypeMask; }
        quint32 Effect(quint8 index) { return m_info->effect[index]; }
        quint32 EffectDieSides(quint8 index) { return m_info->effectDieSides[index]; }
        float EffectRealPointsPerLevel(quint8 index) { return m_info->effectRealPointsPerLevel[index]; }
        qint32 EffectBasePoints(quint8 index) { return m_info->effectBasePoints[index]; }
        quint32 EffectMechanic(quint8 index) { return m_info->effectMechanic[index]; }
        quint32 EffectImplicitTargetA(quint8 index) { return m_info->effectImplicitTargetA[index]; }
        quint32 EffectImplicitTargetB(quint8 index) { return m_info->effectImplicitTargetB[index]; }
        quint32 EffectRadiusIndex(quint8 index) { return m_info->effectRadiusIndex[index]; }
        quint32 EffectApplyAuraName(quint8 index) { return m_info->effectApplyAuraName[index]; }
        quint32 EffectAmplitude(quint8 index) { return m_info->effectAmplitude[index]; }
        float EffectMultipleValue(quint8 index) { return m_info->effectMultipleValue[index]; }
        quint32 EffectChainTarget(quint8 index) { return m_info->effectChainTarget[index]; }
        quint32 EffectItemType(quint8 index) { return m_info->effectItemType[index]; }
        qint32 EffectMiscValueA(quint8 index) { return m_info->effectMiscValueA[index]; }
        qint32 EffectMiscValueB(quint8 index) { return m_info->effectMiscValueB[index]; }
        quint32 EffectTriggerSpell(quint8 index) { return m_info->effectTriggerSpell[index]; }
        float EffectPointsPerComboPoint(quint8 index) { return m_info->effectPointsPerComboPoint[index]; }
        quint32 EffectSpellClassMaskA(quint8 index) { return m_info->effectSpellClassMaskA[index]; }
        quint32 EffectSpellClassMaskB(quint8 index) { return m_info->effectSpellClassMaskB[index]; }
        quint32 EffectSpellClassMaskC(quint8 index) { return m_info->effectSpellClassMaskC[index]; }
        quint32 SpellVisual() { return m_info->spellVisual; }
        quint32 SpellIconId() { return m_info->spellIconId; }
        quint32 ActiveIconId() { return m_info->activeIconId; }
        quint32 SpellPriority() { return m_info->spellPriority; }
        QString Name() { return m_info->name(); }
        QString Rank() { return m_info->rank(); }
        QString Description() { return m_info->description(); }
        QString ToolTip() { return m_info->toolTip(); }
        quint32 NameFlag() { return m_info->nameFlag; }
        quint32 RankFlags() { return m_info->rankFlags; }
        quint32 DescriptionFlags() { return m_info->descriptionFlags; }
        quint32 ToolTipFlags() { return m_info->toolTipFlags; }
        quint32 ManaCostPercentage() { return m_info->manaCostPercentage; }
        quint32 StartRecoveryCategory() { return m_info->startRecoveryCategory; }
        quint32 StartRecoveryTime() { return m_info->startRecoveryTime; }
        quint32 MaxTargetLevel() { return m_info->maxTargetLevel; }
        quint32 SpellFamilyName() { return m_info->spellFamilyName; }
        quint32 SpellFamilyFlags(quint8 index) { return m_info->spellFamilyFlags[index]; }
        quint32 MaxAffectedTargets() { return m_info->maxAffectedTargets; }
        quint32 DamageClass() { return m_info->damageClass; }
        quint32 PreventionType() { return m_info->preventionType; }
        qint32 StanceBarOrder() { return m_info->stanceBarOrder; }
        float DamageMultiplier(quint8 index) { return m_info->damageMultiplier[index]; }
        quint32 MinFactionId() { return m_info->minFactionId; }
        quint32 MinReputation() { return m_info->minReputation; }
        quint32 RequiredAuraVision() { return m_info->requiredAuraVision; }
        quint32 TotemCategory(quint8 index) { return m_info->totemCategory[index]; }
        quint32 AreaId() { return m_info->areaId; }
        quint32 SchoolMask() { return m_info->schoolMask; }
        quint32 RuneCostId() { return m_info->runeCostId; }
        quint32 SpellMissileId() { return m_info->spellMissileId; }
        quint32 PowerDisplayId() { return m_info->powerDisplayId; }
        float EffectBonusMultiplier(quint8 index) { return m_info->effectBonusMultiplier[index]; }
        quint32 SpellDescriptionVariableId() { return m_info->spellDescriptionVariableId; }
        quint32 SpellDifficultyId() { return m_info->spellDifficultyId; }
        qint32 Duration() { return m_info->getDuration(); }
        qint32 TriggerDuration(quint8 index) { return m_info->getTriggerDuration(index); }
        QString NameWithRank() { return m_info->nameWithRank(); }

        bool hasAura(quint32 auraId)
        {
            for (quint8 i = 0; i < MAX_EFFECT_INDEX; ++i)
                if (m_info->effectApplyAuraName[i] == auraId)
                    return true;
            return false;
        }

        bool hasEffect(quint32 effectId)
        {
            for (quint8 i = 0; i < MAX_EFFECT_INDEX; ++i)
                if (m_info->effect[i] == effectId)
                    return true;
            return false;
        }

        bool hasTargetA(quint32 targetId)
        {
            for (quint8 i = 0; i < MAX_EFFECT_INDEX; ++i)
                if (m_info->effectImplicitTargetA[i] == targetId)
                    return true;
            return false;
        }

        bool hasTargetB(quint32 targetId)
        {
            for (quint8 i = 0; i < MAX_EFFECT_INDEX; ++i)
                if (m_info->effectImplicitTargetB[i] == targetId)
                    return true;
            return false;
        }

        //bool isFitToFamilyMask(quint64 flags) { return !!(m_info->spellFamilyFlags & flags); }

        private:

            const entry* m_info;
            bool m_destroyInfo;
            bool m_serverSide;

        Q_PROPERTY(quint32 Id READ Id)
        Q_PROPERTY(quint32 Category READ Category)
        Q_PROPERTY(quint32 Dispel READ Dispel)
        Q_PROPERTY(quint32 Mechanic READ Mechanic)
        Q_PROPERTY(quint32 Attributes READ Attributes)
        Q_PROPERTY(quint32 AttributesEx1 READ AttributesEx1)
        Q_PROPERTY(quint32 AttributesEx2 READ AttributesEx2)
        Q_PROPERTY(quint32 AttributesEx3 READ AttributesEx3)
        Q_PROPERTY(quint32 AttributesEx4 READ AttributesEx4)
        Q_PROPERTY(quint32 AttributesEx5 READ AttributesEx5)
        Q_PROPERTY(quint32 AttributesEx6 READ AttributesEx6)
        Q_PROPERTY(quint32 AttributesEx7 READ AttributesEx7)
        Q_PROPERTY(quint64 Stances READ Stances)
        Q_PROPERTY(quint64 StancesNot READ StancesNot)
        Q_PROPERTY(quint32 Targets READ Targets)
        Q_PROPERTY(quint32 TargetCreatureType READ TargetCreatureType)
        Q_PROPERTY(quint32 RequiresSpellFocus READ RequiresSpellFocus)
        Q_PROPERTY(quint32 FacingCasterFlags READ FacingCasterFlags)
        Q_PROPERTY(quint32 CasterAuraState READ CasterAuraState)
        Q_PROPERTY(quint32 TargetAuraState READ TargetAuraState)
        Q_PROPERTY(quint32 CasterAuraStateNot READ CasterAuraStateNot)
        Q_PROPERTY(quint32 TargetAuraStateNot READ TargetAuraStateNot)
        Q_PROPERTY(quint32 CasterAuraSpell READ CasterAuraSpell)
        Q_PROPERTY(quint32 TargetAuraSpell READ TargetAuraSpell)
        Q_PROPERTY(quint32 ExcludeCasterAuraSpell READ ExcludeCasterAuraSpell)
        Q_PROPERTY(quint32 ExcludeTargetAuraSpell READ ExcludeTargetAuraSpell)
        Q_PROPERTY(quint32 CastingTimeIndex READ CastingTimeIndex)
        Q_PROPERTY(quint32 RecoveryTime READ RecoveryTime)
        Q_PROPERTY(quint32 CategoryRecoveryTime READ CategoryRecoveryTime)
        Q_PROPERTY(quint32 InterruptFlags READ InterruptFlags)
        Q_PROPERTY(quint32 AuraInterruptFlags READ AuraInterruptFlags)
        Q_PROPERTY(quint32 ChannelInterruptFlags READ ChannelInterruptFlags)
        Q_PROPERTY(quint32 ProcFlags READ ProcFlags)
        Q_PROPERTY(quint32 ProcChance READ ProcChance)
        Q_PROPERTY(quint32 ProcCharges READ ProcCharges)
        Q_PROPERTY(quint32 MaxLevel READ MaxLevel)
        Q_PROPERTY(quint32 BaseLevel READ BaseLevel)
        Q_PROPERTY(quint32 SpellLevel READ SpellLevel)
        Q_PROPERTY(quint32 DurationIndex READ DurationIndex)
        Q_PROPERTY(qint32 PowerType READ PowerType)
        Q_PROPERTY(quint32 ManaCost READ ManaCost)
        Q_PROPERTY(quint32 ManaCostPerlevel READ ManaCostPerlevel)
        Q_PROPERTY(quint32 ManaPerSecond READ ManaPerSecond)
        Q_PROPERTY(quint32 ManaPerSecondPerLevel READ ManaPerSecondPerLevel)
        Q_PROPERTY(quint32 RangeIndex READ RangeIndex)
        Q_PROPERTY(float Speed READ Speed)
        Q_PROPERTY(quint32 ModalNextSpell READ ModalNextSpell)
        Q_PROPERTY(quint32 StackAmount READ StackAmount)
        Q_PROPERTY(qint32 EquippedItemClass READ EquippedItemClass)
        Q_PROPERTY(qint32 EquippedItemSubClassMask READ EquippedItemSubClassMask)
        Q_PROPERTY(qint32 EquippedItemInventoryTypeMask READ EquippedItemInventoryTypeMask)
        Q_PROPERTY(quint32 SpellVisual READ SpellVisual)
        Q_PROPERTY(quint32 SpellIconId READ SpellIconId)
        Q_PROPERTY(quint32 ActiveIconId READ ActiveIconId)
        Q_PROPERTY(quint32 SpellPriority READ SpellPriority)
        Q_PROPERTY(QString Name READ Name)
        Q_PROPERTY(QString Rank READ Rank)
        Q_PROPERTY(QString Description READ Description)
        Q_PROPERTY(QString ToolTip READ ToolTip)
        Q_PROPERTY(quint32 NameFlag READ NameFlag)
        Q_PROPERTY(quint32 RankFlags READ RankFlags)
        Q_PROPERTY(quint32 DescriptionFlags READ DescriptionFlags)
        Q_PROPERTY(quint32 ToolTipFlags READ ToolTipFlags)
        Q_PROPERTY(quint32 ManaCostPercentage READ ManaCostPercentage)
        Q_PROPERTY(quint32 StartRecoveryCategory READ StartRecoveryCategory)
        Q_PROPERTY(quint32 StartRecoveryTime READ StartRecoveryTime)
        Q_PROPERTY(quint32 MaxTargetLevel READ MaxTargetLevel)
        Q_PROPERTY(quint32 SpellFamilyName READ SpellFamilyName)
        Q_PROPERTY(quint32 MaxAffectedTargets READ MaxAffectedTargets)
        Q_PROPERTY(quint32 DamageClass READ DamageClass)
        Q_PROPERTY(quint32 PreventionType READ PreventionType)
        Q_PROPERTY(qint32 StanceBarOrder READ StanceBarOrder)
        Q_PROPERTY(quint32 MinFactionId READ MinFactionId)
        Q_PROPERTY(quint32 MinReputation READ MinReputation)
        Q_PROPERTY(quint32 RequiredAuraVision READ RequiredAuraVision)
        Q_PROPERTY(quint32 AreaId READ AreaId)
        Q_PROPERTY(quint32 SchoolMask READ SchoolMask)
        Q_PROPERTY(quint32 RuneCostId READ RuneCostId)
        Q_PROPERTY(quint32 SpellMissileId READ SpellMissileId)
        Q_PROPERTY(quint32 PowerDisplayId READ PowerDisplayId)
        Q_PROPERTY(quint32 SpellDescriptionVariableId READ SpellDescriptionVariableId)
        Q_PROPERTY(quint32 SpellDifficultyId READ SpellDifficultyId)
        Q_PROPERTY(qint32 Duration READ Duration)
        Q_PROPERTY(QString NameWithRank READ NameWithRank)
        Q_PROPERTY(quint8 ServerSide READ getServerSide WRITE setServerSide)
    };
}

#if defined( __GNUC__ )
#pragma pack()
#else
#pragma pack(pop)
#endif
