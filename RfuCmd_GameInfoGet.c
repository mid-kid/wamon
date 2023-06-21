#include <Agb.h>

#include "Rfu.h"
extern u32 RfuCmdInit(void);
extern u16 RfuCmdSend(void);
extern u16 RfuCmdRecv(u32 Cmd, u8 VarSize);
extern u8 RfuBufSend[0x120];
extern struct Rfu Rfu;

u16 RfuCmd_GameInfoGet(void)
{
    RfuCmdInit();
    *(u32 *)(RfuBufSend + 0) = 0x9966001d;
    Rfu.field2_0x8 = 0;

    if (RfuCmdSend() == 1) {
        return 5;
    } else {
        return RfuCmdRecv(0x9966009d, TRUE);
    }
}
