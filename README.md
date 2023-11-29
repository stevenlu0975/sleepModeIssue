# sleepModeIssue


<h2> IDF version</h2>
5.0.3
<h2>How did you build your project?</h2>
VS Code IDE
<h2>device</h2>
esp32s3-lcd-ev-board2
<h2>What is the expected behavior?</h2>

When the `sleep_mode_task` task is suspended,
the `esp_light_sleep_start` method is executed.
Every two seconds, it will wake up 
due to the `esp_sleep_enable_timer_wakeup` method. 
After waking up, it will enter "light sleep" again.
This cycle will continue repeatedly.

<h2>What is the actual behavior</h2>

During the execution of this cycle, 
there is a chance of an automatic system restart due to 
the `RTCWDT_RTC_RST` error. 
When I comment out the code releated to lvgl in  `app_main()`,
the issue does not occur. How can I resolve this problem?

<h2>Debug Logs</h2>

```c
ESP-ROM:esp32s3-20210327
Build:Mar 27 2021
rst:0x1 (POWERON),boot:0x8 (SPI_FAST_FLASH_BOOT)
SPIWP:0xee
mode:DIO, clock div:1
load:0x3fce3810,len:0x18ac
load:0x403c9700,len:0xdf4 
load:0x403cc700,len:0x3494
entry 0x403c99a4
I (25) boot: ESP-IDF v5.0.3-dirty 2nd stage bootloader
I (25) boot: compile time 11:03:28
I (26) boot: Multicore bootloader
I (28) boot: chip revision: v0.2
I (32) qio_mode: Enabling default flash chip QIO      
I (37) boot.esp32s3: Boot SPI Speed : 80MHz
I (42) boot.esp32s3: SPI Mode       : QIO
I (47) boot.esp32s3: SPI Flash Size : 16MB
I (51) boot: Enabling RNG early entropy source...
I (57) boot: Partition Table:
I (60) boot: ## Label            Usage          Type ST Offset   Length
I (68) boot:  0 nvs              WiFi data        01 02 00009000 00006000
I (75) boot:  1 phy_init         RF data          01 01 0000f000 00001000
I (83) boot:  2 factory          factory app      00 00 00010000 0036b000
I (90) boot:  3 storage          Unknown data     01 82 0037b000 006d6000
I (98) boot: End of partition table
I (102) esp_image: segment 0: paddr=00010020 vaddr=3c060020 size=14010h ( 81936) map
I (122) esp_image: segment 1: paddr=00024038 vaddr=3fc96b00 size=03114h ( 12564) load
I (124) esp_image: segment 2: paddr=00027154 vaddr=40374000 size=08ec4h ( 36548) load   
I (134) esp_image: segment 3: paddr=00030020 vaddr=42000020 size=53c74h (343156) map
I (185) esp_image: segment 4: paddr=00083c9c vaddr=4037cec4 size=09bc4h ( 39876) load
I (193) esp_image: segment 5: paddr=0008d868 vaddr=600fe000 size=00034h (    52) load   
I (200) boot: Loaded app from partition at offset 0x10000
I (200) boot: Disabling RNG early entropy source...
I (214) cpu_start: Multicore app
I (214) octal_psram: vendor id    : 0x0d (AP)
I (214) octal_psram: dev id       : 0x02 (generation 3)
I (217) octal_psram: density      : 0x03 (64 Mbit)
I (223) octal_psram: good-die     : 0x01 (Pass)
I (228) octal_psram: Latency      : 0x01 (Fixed)
I (233) octal_psram: VCC          : 0x01 (3V)
I (238) octal_psram: SRF          : 0x01 (Fast Refresh)
I (244) octal_psram: BurstType    : 0x01 (Hybrid Wrap)
I (250) octal_psram: BurstLen     : 0x01 (32 Byte)
I (255) octal_psram: Readlatency  : 0x02 (10 cycles@Fixed)
I (262) octal_psram: DriveStrength: 0x00 (1/1)
I (267) MSPI Timing: PSRAM timing tuning index: 5
I (272) esp_psram: Found 8MB PSRAM device
I (277) esp_psram: Speed: 80MHz
I (314) mmu_psram: Instructions copied and mapped to SPIRAM
I (324) mmu_psram: Read only data copied and mapped to SPIRAM
I (324) cpu_start: Pro cpu up.
I (324) cpu_start: Starting app cpu, entry point is 0x403756e8
0x403756e8: call_start_cpu1 at C:/Espressif/frameworks/esp-idf-v5.0.3/components/esp_system/port/cpu_start.c:143

I (0) cpu_start: App cpu up.
I (753) esp_psram: SPI SRAM memory test OK
I (762) cpu_start: Pro cpu start user code
I (762) cpu_start: cpu freq: 240000000 Hz
I (762) cpu_start: Application information:
I (765) cpu_start: Project name:     SquareLine_Project
I (771) cpu_start: App version:      1
I (775) cpu_start: Compile time:     Nov 29 2023 11:03:11
I (781) cpu_start: ELF file SHA256:  92a1a8e02366318b...
I (787) cpu_start: ESP-IDF:          v5.0.3-dirty
I (793) cpu_start: Min chip rev:     v0.0
I (797) cpu_start: Max chip rev:     v0.99 
I (802) cpu_start: Chip rev:         v0.2
I (807) heap_init: Initializing. RAM available for dynamic allocation:
I (814) heap_init: At 3FC9AC78 len 0004EA98 (314 KiB): DRAM
I (820) heap_init: At 3FCE9710 len 00005724 (21 KiB): STACK/DRAM
I (827) heap_init: At 600FE034 len 00001FCC (7 KiB): RTCRAM
I (833) esp_psram: Adding pool of 7680K of PSRAM memory to heap allocator
I (841) spi_flash: detected chip: gd
I (845) spi_flash: flash io: qio
I (850) sleep: Configure to isolate all GPIO pins in sleep state
I (856) sleep: Enable automatic switching of GPIO sleep configuration
I (863) cpu_start: Starting scheduler on PRO CPU.
I (0) cpu_start: Starting scheduler on APP CPU.
I (878) esp_psram: Reserving pool of 32K of internal memory for DMA/internal allocationsI (887) bsp_sub_board: Detect sub_board3 with 800x480 LCD (ST7262), Touch (GT1151)
I (895) bsp_sub_board: Initialize RGB panel
I (922) gt1151: IC version: GT1158_000101(Patch)_0102(Mask)_00(SensorID)
I (922) bsp_lvgl_port: LVGL buffer size: 156KB
I (926) bsp_lvgl_port: Create LVGL task
W (928) S3-LCD-EV-BOARD: This board doesn't support to change brightness of LCD
I (928) bsp_lvgl_port: Starting LVGL task
Hello world!
Enabling timer wakeup on 60S
W (981) sleep: go to sleep mode
ESP-ROM:esp32s3-20210327
Build:Mar 27 2021
rst:0x10 (RTCWDT_RTC_RST),boot:0x8 (SPI_FAST_FLASH_BOOT)
SPIWP:0xee
mode:DIO, clock div:1
load:0x3fce3810,len:0x18ac
load:0x403c9700,len:0xdf4
load:0x403cc700,len:0x3494
entry 0x403c99a4
I (25) boot: ESP-IDF v5.0.3-dirty 2nd stage bootloader
I (25) boot: compile time 11:03:28
I (26) boot: Multicore bootloader
I (28) boot: chip revision: v0.2
I (32) qio_mode: Enabling default flash chip QIO
I (37) boot.esp32s3: Boot SPI Speed : 80MHz
I (42) boot.esp32s3: SPI Mode       : QIO
I (47) boot.esp32s3: SPI Flash Size : 16MB
I (52) boot: Enabling RNG early entropy source...
I (57) boot: Partition Table:
I (61) boot: ## Label            Usage          Type ST Offset   Length
I (68) boot:  0 nvs              WiFi data        01 02 00009000 00006000
I (75) boot:  1 phy_init         RF data          01 01 0000f000 00001000
I (83) boot:  2 factory          factory app      00 00 00010000 0036b000
I (90) boot:  3 storage          Unknown data     01 82 0037b000 006d6000
I (98) boot: End of partition table
I (102) esp_image: segment 0: paddr=00010020 vaddr=3c060020 size=14010h ( 81936) map
I (122) esp_image: segment 1: paddr=00024038 vaddr=3fc96b00 size=03114h ( 12564) load   
I (125) esp_image: segment 2: paddr=00027154 vaddr=40374000 size=08ec4h ( 36548) load
I (134) esp_image: segment 3: paddr=00030020 vaddr=42000020 size=53c74h (343156) map    
I (185) esp_image: segment 4: paddr=00083c9c vaddr=4037cec4 size=09bc4h ( 39876) load
I (193) esp_image: segment 5: paddr=0008d868 vaddr=600fe000 size=00034h (    52) load   
I (200) boot: Loaded app from partition at offset 0x10000
I (200) boot: Disabling RNG early entropy source...
I (214) cpu_start: Multicore app
I (214) octal_psram: vendor id    : 0x0d (AP)
I (214) octal_psram: dev id       : 0x02 (generation 3)
I (217) octal_psram: density      : 0x03 (64 Mbit)
I (223) octal_psram: good-die     : 0x01 (Pass)
I (228) octal_psram: Latency      : 0x01 (Fixed)
I (233) octal_psram: VCC          : 0x01 (3V)
I (238) octal_psram: SRF          : 0x01 (Fast Refresh)
I (244) octal_psram: BurstType    : 0x01 (Hybrid Wrap)
I (250) octal_psram: BurstLen     : 0x01 (32 Byte)
I (256) octal_psram: Readlatency  : 0x02 (10 cycles@Fixed)
I (262) octal_psram: DriveStrength: 0x00 (1/1)
I (268) MSPI Timing: PSRAM timing tuning index: 5
I (272) esp_psram: Found 8MB PSRAM device
I (277) esp_psram: Speed: 80MHz
I (314) mmu_psram: Instructions copied and mapped to SPIRAM
I (324) mmu_psram: Read only data copied and mapped to SPIRAM
I (324) cpu_start: Pro cpu up.
I (324) cpu_start: Starting app cpu, entry point is 0x403756e8
0x403756e8: call_start_cpu1 at C:/Espressif/frameworks/esp-idf-v5.0.3/components/esp_system/port/cpu_start.c:143

I (0) cpu_start: App cpu up.
I (753) esp_psram: SPI SRAM memory test OK
I (762) cpu_start: Pro cpu start user code
I (762) cpu_start: cpu freq: 240000000 Hz
I (762) cpu_start: Application information:
I (765) cpu_start: Project name:     SquareLine_Project
I (771) cpu_start: App version:      1
I (775) cpu_start: Compile time:     Nov 29 2023 11:03:11
I (781) cpu_start: ELF file SHA256:  92a1a8e02366318b...
I (787) cpu_start: ESP-IDF:          v5.0.3-dirty
I (793) cpu_start: Min chip rev:     v0.0
I (797) cpu_start: Max chip rev:     v0.99 
I (802) cpu_start: Chip rev:         v0.2
I (807) heap_init: Initializing. RAM available for dynamic allocation:
I (814) heap_init: At 3FC9AC78 len 0004EA98 (314 KiB): DRAM
I (820) heap_init: At 3FCE9710 len 00005724 (21 KiB): STACK/DRAM
I (827) heap_init: At 600FE034 len 00001FCC (7 KiB): RTCRAM
I (833) esp_psram: Adding pool of 7680K of PSRAM memory to heap allocator
I (841) spi_flash: detected chip: gd
I (845) spi_flash: flash io: qio
I (850) sleep: Configure to isolate all GPIO pins in sleep state
I (856) sleep: Enable automatic switching of GPIO sleep configuration
I (863) cpu_start: Starting scheduler on PRO CPU.
I (0) cpu_start: Starting scheduler on APP CPU.
I (879) esp_psram: Reserving pool of 32K of internal memory for DMA/internal allocationsI (888) bsp_sub_board: Detect sub_board3 with 800x480 LCD (ST7262), Touch (GT1151)
I (896) bsp_sub_board: Initialize RGB panel
I (923) gt1151: IC version: GT1158_000101(Patch)_0102(Mask)_00(SensorID)
I (923) bsp_lvgl_port: LVGL buffer size: 156KB
I (927) bsp_lvgl_port: Create LVGL task
W (929) S3-LCD-EV-BOARD: This board doesn't support to change brightness of LCD
I (929) bsp_lvgl_port: Starting LVGL task
Hello world!
```
