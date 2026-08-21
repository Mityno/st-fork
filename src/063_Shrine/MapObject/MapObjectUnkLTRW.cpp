#include "MapObject/MapObjectUnkLTRW.hpp"
#include "MapObject/MapObjectProfile.hpp"
#include "System/SysNew.hpp"
#include "global.h"
#include "nitro/fx.h"
#include "nitro/math.h"
#include "nns/g3d/g3d.h"
#include "profile.hpp"

struct UnkStruct_data_ov063_021639c4 {
    /* 00 */ STRUCT_PAD(0x0, 0x0C);
    /* 0C */ VecFx32 vec;
};

extern UnkStruct_data_ov063_021639c4 data_ov063_021639c4;

DECL_PROFILE(MapObjectProfileUnkLTRW);

MapObject *MapObjectProfileUnkLTRW::Create() {
    return new(HeapIndex_ITCM) MapObjectUnkLTRW();
}

MapObjectProfileUnkLTRW::MapObjectProfileUnkLTRW() :
    MapObjectProfileUnkLTRW_Base(MapObjectId_LTRW, MapObjectId_LTRW) {
    mUnk_D4.mUnk_08 = 0x04007007;
    VecFx32_Init(data_ov063_021639c4.vec.x - 0x99A, data_ov063_021639c4.vec.y, data_ov063_021639c4.vec.z - 0x666,
                 &mUnk_D4.mUnk_0C);
    VecFx32_Init(data_ov063_021639c4.vec.x + 0x99A, data_ov063_021639c4.vec.y + 0x1333, data_ov063_021639c4.vec.z + 0x666,
                 &mUnk_D4.mUnk_18);
    mUnk_06 = 1;
    mUnk_0C = 0x1333;
}

MapObjectUnkLTRW::MapObjectUnkLTRW() :
    mUnk_40(G3d_GetModelPtr(GET_PROFILE(MapObjectProfileUnkLTRW)->mUnk_20.mUnk_50)),
    mUnk_A0(1),
    mUnk_A4(0),
    mUnk_A6(0),
    mUnk_A8(),
    mUnk_AC(0),
    mUnk_AE(0) {}

void MapObjectUnkLTRW::func_ov063_02160c6c(void) {}
void MapObjectUnkLTRW::func_ov063_02160cc8(void) {}
void MapObjectUnkLTRW::func_ov063_02160ce4(void) {}
void MapObjectUnkLTRW::func_ov063_02160d18(void) {}
void MapObjectUnkLTRW::func_ov063_02160d34(void) {}
void MapObjectUnkLTRW::func_ov063_02160df8(void) {}
void MapObjectUnkLTRW::func_ov063_02160e18(void) {}

MapObjectUnkLTRW::~MapObjectUnkLTRW() {}
MapObjectProfileUnkLTRW::~MapObjectProfileUnkLTRW() {}
