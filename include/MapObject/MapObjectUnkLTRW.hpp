//! TODO: This file was generated automatically and might contain errors

#pragma once

#include "MapObject/MapObject.hpp"
#include "MapObject/MapObjectProfile.hpp"
#include "Render/ModelRender.hpp"
#include "global.h"

class UnkStruct_ov063_021639e4 {
public:
    /* 00 */

    UnkStruct_ov063_021639e4() {};

    /* 04 */ virtual void vfunc_04() override;
};

class MapObjectUnkLTRW : public MapObject {
public:
    /* 00 (base) */
    /* 40 */ ModelRender mUnk_40;
    /* A0 */ unk32 mUnk_A0;
    /* A4 */ unk16 mUnk_A4;
    /* A6 */ unk16 mUnk_A6;
    /* A8 */ UnkStruct_ov063_021639e4 mUnk_A8;
    /* AC */ unk16 mUnk_AC; // Both members are probably part of mUnk_A8
    /* AE */ unk16 mUnk_AE;

    MapObjectUnkLTRW();

    /* 30 */ virtual ~MapObjectUnkLTRW() override;

    void func_ov063_02160c6c(void);
    void func_ov063_02160cc8(void);
    void func_ov063_02160ce4(void);
    void func_ov063_02160d18(void);
    void func_ov063_02160d34(void);
    void func_ov063_02160df8(void);
    void func_ov063_02160e18(void);
};

class MapObjectProfileUnkLTRW_Base_D4 : public MapObject_10 {
public:
};

class MapObjectProfileUnkLTRW_Base : public MapObjectProfile_Derived2 {
public:
    /* 00 (base) */
    /* D4 */ MapObjectProfileUnkLTRW_Base_D4 mUnk_D4;
    /* F8 */

    MapObjectProfileUnkLTRW_Base(MapObjectId mapObjId1, MapObjectId mapObjId2) :
        MapObjectProfile_Derived2(mapObjId1, mapObjId2),
        mUnk_D4() {};
};

class MapObjectProfileUnkLTRW : public MapObjectProfileUnkLTRW_Base {
public:
    /* 00 (base) */

    MapObjectProfileUnkLTRW();
    ~MapObjectProfileUnkLTRW();

    /* 0C */ virtual MapObject *Create();

    static MapObjectProfileUnkLTRW *GetProfile();
};
