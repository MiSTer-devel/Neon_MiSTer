Soyuz-Neon PK-11/16 software for the Neon MiSTer core
=====================================================

Copy this folder to games/Neon on the MiSTer SD card.

neon_full.img   Hard disk image, boots RT-11 (mount it as "Hard disk" in
                the OSD, or copy it to boot2.vhd to have it mounted at
                start).  Partitions:
                  HD0:  RT-11 system (PK1116-system.dsk)
                  HD1:  games: TETRIS, MINE, PICT, CALCUN (Games.dsk)
                  HD2:  demo: DEMO, music .SND, pictures .ATR (@DEM)
                  HD3:  STM music player and songs
                  HD4:  SPLAY music player and samples
                  HD5:  utilities: KBD.PRC, MINE, PICT, CO, CALCUN, FONT
                  HD6:  documentation of the Aspect window system
                TETRIS: PRUN HD5:KBD.PRC, INST SN, RUN HD1:TETRIS
neon_empty.img  Empty hard disk image with the partition table, for your
                own system (COPY/DEVICE FD0: HD0:, COPY/BOOT HD0:RT11SJ.SYS HD0:)

PK1116-system.dsk, System.dsk   RT-11 system floppies (boot with FD0)
Games.dsk, SOUZ-NEON_DEMO_.dsk  games, demo
Utilities_KBD.dsk, SPLAY_music.dsk, STM_music.dsk, Docs.dsk

The floppies come from the PK11_NEON section of archive.pdp-11.org.ru
(TheGWBV.rar, SFROLOV_neon_disk.rar) and from the NeonBTL emulator.
