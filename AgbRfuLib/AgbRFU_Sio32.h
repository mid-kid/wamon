#ifndef _SIO32_H
#define _SIO32_H

#define SIO32_BLOCK_SIZE 32
#define SIO32_SYNC_DATA 0xfefefefe
#define SIO32_DI_FUNC_FAST 
#define SIO32_INTR_DELAY_MAX 2048
#define SIO32_INTR_CLOCK_MAX 256
#define SIO32_SHIFT_CLOCK (256 * 1024)
#define SIO32_TIMER_NO 3
#define SIO32_TIMER_INTR_FLAG (TIMER0_INTR_FLAG << SIO32_TIMER_NO)
#define REG_SIO32_TIMER (REG_TM0CNT + SIO32_TIMER_NO * 4)
#define REG_SIO32_TIMER_L REG_SIO32_TIMER
#define REG_SIO32_TIMER_H (REG_SIO32_TIMER + 2)
#define SIO32_TIMER_COUNT_TMP (SYSTEM_CLOCK/60/((4 + 4 + SIO32_BLOCK_SIZE + 32)/(32/8)))
#define SIO32_TIMER_COUNT_MIN (SYSTEM_CLOCK/SIO32_SHIFT_CLOCK*32 + SIO32_INTR_DELAY_MAX + SIO32_INTR_CLOCK_MAX)
#define SIO32_TIMER_COUNT_MAX 0x10000
#define SIO32_TIMER_COUNT (SIO32_TIMER_COUNT_MAX - SIO32_TIMER_COUNT_TMP)
#define SIO32_RECV_FLAG 0x0001
#define SIO32_TYPE 0x0080
#define SIO32_PARENT 0x0080
#define SIO32_CHILD 0x0000
#define SIO32_CONNECTED_FLAG 0x0100

// ---- pubnames:
// Sio32Packet
// Sio32Area
// RecvFuncBuf
// IntrFuncBuf
// S32a
// Sio32Return

#endif