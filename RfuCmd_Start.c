#if 1
__asm__("
.section .text
@.global RfuCmd_Start
.type RfuCmd_Start, function
.thumb_func
RfuCmd_Start:
.2byte 0xb500,0xf7ff,0xff09,0x4909,0x4809,0x6008,0x4909,0x2000,0x7208,0xf7ff,0xff3d,0x0400,0x0c00,0x2801,0xd00e,0x4806,0x2100,0xf7ff,0xff99,0x0400,0x0c00,0xe008,0x5cc0,0x0300,0x0010,0x9966,0x5ca0,0x0300,0x0090,0x9966,0x2005,0xbc02,0x4708,0x0000
.size RfuCmd_Start, .-RfuCmd_Start
");
#else
#endif
