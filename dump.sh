#!/bin/sh
set -e
dd if=baserom.bin bs=1 skip=672 2>/dev/null | ./dump_lz77.py > baserom_demo.bin

rm -rf dump
mkdir -p dump

# Dump libraries
mkdir -p dump/libagbsyscall
( cd dump/libagbsyscall
    thumb-elf-ar x "$AGBDIR/lib/libagbsyscall.a"
)
mkdir -p dump/libgcc
( cd dump/libgcc
    thumb-elf-ar x "$(thumb-elf-gcc -print-libgcc-file-name)"
)

off=256
split() {
    skip=$(expr $off - 256 || true)
    size=$(expr $(printf %d $2) - $off)
    name="$3"
    if [ -z "$name" ]; then
        name="baserom_demo_$(printf "%04x" $off)"
    fi
    dd if=baserom_demo.bin bs=1 skip=$skip count=$size 2>/dev/null | \
        ./dump_bin2c.py $1 $3 > dump/"$name.c"
    off=$(expr $off + $size)
}

split .text 0x02a0
split .text 0x03bc
split .text 0x04a8 MainMenuInit
split .text 0x04c4 MenuMsgInit
split .text 0x1158
split .text 0x1190 GameListInit
split .text 0x12b8
split .text 0x1310 MenuMsgSet
split .text 0x131c FrameCountReset
split .text 0x1370 MenuMsgBlink
split .text 0x13f0 GameNameInit
split .text 0x1410 KeyRead
split .text 0x1464 KeyRepeatHold
split .text 0x148c BgScClearGame
split .text 0x14f0 VramDrawBg2_MainMenu
split .text 0x1528 VramDrawBg2_SearchMenu
split .text 0x1548 VramClearBg2
split .text 0x157c BgScSet
split .text 0x15c4 BgScClear
split .text 0x15dc Delay3s
split .text 0x1614 WinInit
split .text 0x1670 WinFade
split .text 0x16a0 SoundInit
split .text 0x1728 SoundMain
split .text 0x1758 SoundPlaySfx
split .text 0x1768 SoundStop
split .text 0x2664
split .text 0x26d0 Sio32Init
split .text 0x3ed0 # Library start
split .text 0x3f38
split .rodata 0x3fb8
split .rodata 0x4200 MenuMsgInitial
split .rodata 0x5684
