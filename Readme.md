# Soyuz-Neon PK-11/16 for MiSTer

[Soyuz-Neon PK-11/16](https://ru.wikipedia.org/wiki/%D0%A1%D0%BE%D1%8E%D0%B7-%D0%9D%D0%B5%D0%BE%D0%BD_%D0%9F%D0%9A-11/16)
is a Soviet computer of 1991 on the N1806VM2, a PDP-11 compatible CPU
(the K1801VM2 family, as in the UKNC and the DVK), with up to 4 MB of RAM
behind a page dispatcher, a display-list video controller (832 x 300,
up to 8 bits a pixel from a 16-bit palette), two floppy drives and
an 8-bit I/O block of Intel-compatible chips.  About 200 were made.

The core follows the [NeonBTL](https://github.com/nzeemin/neonbtl)
emulator; the CPU is the K1801VM2 core from
[1801BM1/cpu11](https://github.com/1801BM1/cpu11).

## Status
Work in progress.  The firmware boots, RT-11 boots from a floppy image.

* CPU at 8 MHz, the memory dispatcher with its HR/UR registers, the
  emulated-register trap area, the 16 KB firmware ROM (built in; a
  `boot.rom` in `games/Neon` replaces it).
* RAM on the SDRAM board: 512 KB, 1, 2 or 4 MB from the OSD, with the
  2 and 4 bits-per-pixel write masking.
* Video: the display list with all the modes NeonBTL renders, 15 kHz
  output; the scaler takes it as it is, `forced_scandoubler=1` in
  `MiSTer.ini` doubles it to 31 kHz.
* Interrupt controller, the two sound timers (three-voice beeper),
  keyboard (PS/2 mapped as in NeonBTL), mouse, real-time clock from the
  MiSTer's clock.
* Two floppy drives on `.dsk` images (800 KB: 80 tracks, 2 sides, 10
  sectors of 512 bytes) in `games/Neon`, read and write.
* Not yet: the IDE hard disk, the serial port, the printer.

## Keyboard

| PC              | Neon        |
|-----------------|-------------|
| F1-F5           | К1-К5       |
| F6, F7, F8      | ПОМ УСТ ИСП |
| F11             | СБРОС       |
| F12             | СТОП        |
| Esc             | АР2         |
| Backspace       | ЗБ          |
| Tab             | ТАБ         |
| Enter           | ВВОД        |
| Left Shift      | НР          |
| Left Ctrl       | УПР         |
| Right Shift     | АЛФ         |
| Right Ctrl      | ГРАФ        |

## Simulation
`sim/` holds a Verilator model of the core: `make` there, then from the
project root `sim/obj_dir/Vsim_top FRAMES EVERY [options]` writes frames
as PPM files.  The options are listed in `sim/sim_main.cpp`.

## Licences
* The framework (`sys/`) and this core's own files: GPL v2 or later, see `LICENSE`.
* `rtl/vm2/`: K1801VM2 by 1801BM1, CC BY 3.0.
* `rtl/vm_reset.v`: from tang-uknc, MIT.
* `rtl/rom/pk11_rom.hex`: the machine's firmware, from NeonBTL.
