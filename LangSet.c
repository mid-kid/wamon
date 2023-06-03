#if 0
__asm__("
.section .text
.type data, function
.thumb_func
data:
.byte 0x03,0x4a,0x04,0x48,0x00,0x78,0xc0,0x00,0x03,0x49,0x40,0x18,0x10,0x60,0x70,0x47,0x5c,0x57,0x00,0x03,0x58,0x57,0x00,0x03,0xf0,0x41,0x00,0x03
.size data, .-data
");
#else

#include <Agb.h>

struct LangMsg {
    const char *const *msg;
    const u16 *pos;
};

extern const struct LangMsg LangMsgInit[];
extern struct LangMsg *LangMsg;
extern u8 Lang;

void LangSet(void)
{
    LangMsg = LangMsgInit + Lang;
}

#endif
