#pragma once

#include "MapObject/MapObject.hpp"
#include "MapObject/MapObjectProfile.hpp"
#include "MapObject/MapObjectUnkSTAT.hpp"
#include "Unknown/UnkStruct_ov094_02177ff8.hpp"
#include "global.h"

class MapObjectUnkWLMS : public UnkStruct_ov094_02177ff8 {
public:
    /* 00 (base) */
    /* 40 */

    MapObjectUnkWLMS();

    /* 30 */ virtual ~MapObjectUnkWLMS() override;

    void func_ov063_0215fe74(void);
    void func_ov063_0215fe88(void);
    void func_ov063_0215feb0(void);
    void func_ov063_0215fff8(void);
    void func_ov063_02160030(void);
    void func_ov063_02160254(void);
    void func_ov063_02160548(void);
    void func_ov063_02160580(void);
    void func_ov063_02160688(void);
    void func_ov063_021606b4(void);
    void func_ov063_02160780(void);
    void func_ov063_02160880(void);
    void func_ov063_021608a8(void);
    void func_ov063_02160918(void);
    void func_ov063_02160938(void);
    void func_ov063_0216095c(void);
};

class MapObjectProfileUnkWLMS : public MapObjectProfileUnkSTAT_Base {
public:
    /* 00 (base) */

    MapObjectProfileUnkWLMS();
    ~MapObjectProfileUnkWLMS();

    /* 0C */ virtual MapObject *Create();

    static MapObjectProfileUnkWLMS *GetProfile();
};
