#include "MapObject/MapObjectUnkWLMS.hpp"
#include "Animation/CellAnimObject.hpp"
#include "MapObject/MapObject.hpp"
#include "Player/TouchControl.hpp"
#include "System/SysNew.hpp"
#include "flags.h"
#include "nitro/math.h"
#include "nitro/mi.h"
#include "nns/g3d/g3d.h"
#include "profile.hpp"

extern MapObject_10 data_ov063_021646d8;
extern CellAnimObject data_ov063_02164514;
extern CellAnimObject data_ov063_0216458c;

DECL_PROFILE(MapObjectProfileUnkWLMS);

UnkStruct_ov063_02163910::UnkStruct_ov063_02163910(void *param1) {
    mUnk_04 = (uintptr_t) param1;
}

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

MapObjectUnkWLMS::MapObjectUnkWLMS() :
    mUnk_070(G3d_GetModelPtr(GET_PROFILE(MapObjectProfileUnkWLMS)->mUnk_20.mUnk_50)),
    mUnk_0D0(&mUnk_0F4, 0x80),
    mUnk_2F4(),
    mUnk_31C(0),
    mUnk_31E(0),
    mUnk_320(this) {
    mUnk_10          = &data_ov063_021646d8;
    mUnk_0D0.mUnk_1C = 0x2000;
    mUnk_316         = -1;
    mUnk_318         = -1;
    mUnk_31A         = -1;

    _MI_CpuFill(0, &mUnk_0F4, 0x200);

    data_ov063_02164514.func_ov000_0206082c(0x2e, 1);
    data_ov063_02164514.func_ov000_02060bac();
    data_ov063_0216458c.func_ov000_0206082c(0x2e, 1);
    data_ov063_0216458c.func_ov000_02060bac();
}

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
