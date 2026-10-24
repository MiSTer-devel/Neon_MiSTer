#!/usr/bin/env python3
"""Make a hard disk image for the Neon core.

The image is what the KM1809VG7 (WD1010) controller of the core serves:
image sector 0 is the firmware's home block (the sector numbered 255 on
cylinder 0 head 0 of a disk the firmware formatter laid down), then the
cylinders of 4 heads x 18 sectors of 512 bytes.  The home block holds, at
byte 336, a 7-word header {sectors, heads,
cylinders, total sectors lo, hi, precompensation, gap3}, eight partition
entries of 10 words {flags | start cylinder, cylinders, start head, heads,
w4, sectors, w6, w7, size lo, size hi} and the signature 123456 (octal).
Flags: 040000 on, 010000 cold boot (the firmware boots it), 004000 warm
boot, 100000 the "Spc" flag of the formatter.  w4 is the first sector
number of the partition: the formatter numbers partition p's sectors
32p + 0..17, so a seek into the wrong partition finds no sector; the core
maps the low five bits of a sector number to the track.  w6 and w7 are
zero as the formatter leaves them.

Usage: mkhd.py OUT.img [--cylinders N] [--boot PART] [--part START,COUNT ...]
       --part lists partitions as start cylinder and cylinder count, all
       four heads; default: seven partitions of 85 cylinders, 20 kept free.
"""
import argparse, struct

HEADS, SPT, SECTOR = 4, 18, 512
ON, COLD, WARM, SPC = 0o040000, 0o010000, 0o004000, 0o100000
SIGNATURE = 0o123456
HOME_OFFSET = 0o520

def home_block(cyls, parts, boot):
    total = cyls * HEADS * SPT
    words = [SPT, HEADS, cyls, total & 0xffff, total >> 16, 0, 16]
    for i in range(8):
        if i < len(parts):
            start, count = parts[i]
            flags = ON | (COLD if i == boot else 0) | (WARM if i == boot else 0)
            size = count * HEADS * SPT
            words += [flags | start, count, 0, HEADS, 32 * i, SPT, 0, 0, size & 0xffff, size >> 16]
        else:
            words += [0] * 10
    words.append(SIGNATURE)
    return struct.pack('<%dH' % len(words), *words)

def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('out')
    ap.add_argument('--cylinders', type=int, default=615)
    ap.add_argument('--boot', type=int, default=0)
    ap.add_argument('--part', action='append', default=None)
    a = ap.parse_args()
    parts = [tuple(int(x) for x in p.split(',')) for p in a.part] if a.part else [(i * 85, 85) for i in range(7)]
    hb = home_block(a.cylinders, parts, a.boot)
    sector0 = bytearray(SECTOR)
    sector0[HOME_OFFSET:HOME_OFFSET + len(hb)] = hb
    with open(a.out, 'wb') as f:
        f.write(sector0)
        f.truncate((1 + a.cylinders * HEADS * SPT) * SECTOR)
    print('%s: %d cylinders, %d partitions, boot %d, %d bytes' % (a.out, a.cylinders, len(parts), a.boot, (1 + a.cylinders * HEADS * SPT) * SECTOR))

if __name__ == '__main__':
    main()
