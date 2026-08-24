//! TODO: This file was generated automatically and might contain errors

#include "MapObject/MapObjectUnkWLMS.hpp"
#include "System/SysNew.hpp"
#include "flags.h"
#include "nitro/math.h"

DECL_PROFILE(MapObjectProfileUnkWLMS);

MapObject *MapObjectProfileUnkWLMS::Create() {
    return new(HeapIndex_ITCM) MapObjectUnkWLMS();
}

MapObjectProfileUnkWLMS::MapObjectProfileUnkWLMS() :
    MapObjectProfileUnkSTAT_Base(MapObjectId_WLMS, MapObjectId_WLMS) {
    mUnk_D4.mUnk_08 = 0x2bc07006;
    VecFx32_Init(0, 0, 0, &mUnk_D4.mUnk_0C);
    mUnk_D4.mUnk_18.x = 0x800;
    mUnk_D4.mUnk_18.y = 0x1000;
    UNSET_FLAG2(mUnk_D4.mUnk_04, 1);
    mUnk_14 = 0x574c4d50;
    mUnk_0C = 0x1B33;
    mUnk_06 = -1;
    SET_FLAG2(mUnk_1E, 0);
}

MapObjectUnkWLMS::MapObjectUnkWLMS() {}

void MapObjectUnkWLMS::vfunc_38(void) {}

void MapObjectUnkWLMS::func_ov063_0215fe74(void) {}
void MapObjectUnkWLMS::func_ov063_0215fe88(void) {}
void MapObjectUnkWLMS::func_ov063_0215feb0(void) {}
void MapObjectUnkWLMS::func_ov063_0215fff8(void) {}
void MapObjectUnkWLMS::func_ov063_02160030(void) {}
void MapObjectUnkWLMS::func_ov063_02160254(void) {}
void MapObjectUnkWLMS::func_ov063_02160548(void) {}
void MapObjectUnkWLMS::func_ov063_02160580(void) {}
void MapObjectUnkWLMS::func_ov063_02160688(void) {}
void MapObjectUnkWLMS::func_ov063_021606b4(void) {}
void MapObjectUnkWLMS::func_ov063_02160780(void) {}
void MapObjectUnkWLMS::func_ov063_02160880(void) {}
void MapObjectUnkWLMS::func_ov063_021608a8(void) {}
void MapObjectUnkWLMS::func_ov063_02160918(void) {}
void MapObjectUnkWLMS::func_ov063_02160938(void) {}
void MapObjectUnkWLMS::func_ov063_0216095c(void) {}
