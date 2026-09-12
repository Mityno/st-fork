#include "LinkList.hpp"

struct UnkStruct_ov000_020b1c10_10 {
    /* 00 */ unk32 mUnk_00;
    /* 04 */ unk32 mUnk_04;
    /* 08 */ unk32 mUnk_08;
};

class UnkStruct_ov000_020b1c10 {
public:
    /* 00 (vtable) */
    /* 04 */ LinkListImpl mUnk_04;
    /* 0C */ unk32 mUnk_0C;
    /* 10 */ UnkStruct_ov000_020b1c10_10 mUnk_10;
    /* 1C */ unk32 mUnk_1C;
    /* 20 */ unk32 mUnk_20;
    /* 24 */

    UnkStruct_ov000_020b1c10(unk32 *param1, unk32 param2);

    /* 00 */ virtual void vfunc_00(void);
};
