Soyuz-Neon PK-11/16 software for the Neon MiSTer core
=====================================================

Copy this folder to games/Neon on the MiSTer SD card.

neon_full.img   Hard disk image (1506 cylinders), boots RT-11 (mount it as
                "Hard disk" in the OSD, or copy it to boot2.vhd to have it
                mounted at start).  Partitions:
                  HD0:  RT-11 system (PK1116-system.dsk)
                  HD1:  the 32 MB software volume of xolod79's UNEON core
                        (github.com/xolod79/UNEON, UNEON_HDD.zip): MACRO,
                        LINK, PASCAL, DESS, KED, archivers, the Neon ports
                        of BK games (CASTLN, CATN, COLUMN, DIGER1, GARDNN,
                        LLANDN, R3N, SHERFN), demos NEODE1-3, STM/MOD music,
                        GIF viewer, tests
                  HD2:  games: TETRIS, MINE, PICT, CALCUN (Games.dsk)
                  HD3:  demo: DEMO, music .SND, pictures .ATR (@DEM)
                  HD4:  STM music player and songs
                  HD5:  utilities: KBD.PRC, MINE, PICT, CO, CALCUN, FONT
                  HD6:  SPLAY music player and samples
                  HD7:  documentation of the Aspect window system
                TETRIS: PRUN HD5:KBD.PRC, INST SN, RUN HD2:TETRIS
neon_empty.img  Empty hard disk image with the partition table, for your
                own system (COPY/DEVICE FD0: HD0:, COPY/BOOT HD0:RT11SJ.SYS HD0:)

PK1116-system.dsk, System.dsk   RT-11 system floppies (boot with FD0)
Games.dsk, SOUZ-NEON_DEMO_.dsk  games, demo
Utilities_KBD.dsk, SPLAY_music.dsk, STM_music.dsk, Docs.dsk

The floppies come from the PK11_NEON section of archive.pdp-11.org.ru
(TheGWBV.rar, SFROLOV_neon_disk.rar) and from the NeonBTL emulator.
