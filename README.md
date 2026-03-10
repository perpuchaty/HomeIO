# HomeIOv2

> ⚠️ **This project is no longer maintained.**
>
> If you are looking to build a home automation controller, consider using **[ESPHome](https://esphome.io/)** instead. It is actively maintained, has a huge ecosystem, supports hundreds of devices out of the box, integrates natively with Home Assistant, and requires almost no custom firmware code.
>
> This repository is kept publicly available as a **reference example** for anyone who wants to run **LwIP + MQTT on an STM32 microcontroller**. It may also be useful as a starting point for other bare-metal Ethernet projects on STM32.

---

## What is it?

HomeIOv2 is a custom home automation I/O controller built around the **STM32L433CC** microcontroller. It connects to a local network via an **ENC28J60 SPI Ethernet** module, uses **LwIP** as the TCP/IP stack, and communicates through **MQTT**. Outputs and inputs can be controlled and monitored by any MQTT-capable platform (e.g. Home Assistant with a generic MQTT integration, Node-RED, etc.).

The firmware was generated with **STM32CubeMX** and built with **CMake + arm-none-eabi-gcc**.

---

## Hardware

| Resource | Details |
|---|---|
| MCU | STM32L433CCUX (Cortex-M4, 80 MHz, 256 KB flash, 64 KB RAM) |
| Ethernet | ENC28J60 via SPI1 |
| ADC | External SPI ADC via SPI2 — 3 channels (ADC1–ADC3) |
| Digital outputs | 3 × GPIO (DOUT1–DOUT3) + LED status via 8-bit shift register |
| PWM outputs | 4 channels — TIM2 CH1/2/3 (PWM1–PWM3), TIM1 CH4 (PWM4) — with software dimming ramp |
| Digital inputs | 3 × GPIO interrupt inputs (IN1–IN3) with debounce — toggle paired output on press |
| RGB LEDs | WS2812B strip via SPI3 DMA |
| Flash storage | Settings persisted in internal STM32 flash (last page) |

---

## Features

- **MQTT subscribe/publish** — all I/O is controlled and reported over MQTT
- **4 PWM channels** with configurable prescaler and smooth dimming ramp length
- **3 digital outputs** (ON / OFF / TOGGLE)
- **3 digital inputs** with debounce that can directly toggle outputs
- **3 ADC channels** — published on change
- **WS2812B RGB strip** control (per-LED color or broadcast, brightness)
- **Configurable settings** stored in flash: IP, gateway, netmask, MQTT broker IP, DHCP, PWM parameters, device name
- **DHCP** optional
- **Serial console** for debug output

---

## MQTT API

The device subscribes to two topics on connect. Replace `<name>` with the configured device name (default: `STM32`).

### Command topic — `<name>/COMMAND`

#### Digital outputs

| Payload | Effect |
|---|---|
| `OUT1=ON` | Turn DOUT1 on |
| `OUT1=OFF` | Turn DOUT1 off |
| `OUT1=TOGGLE` | Toggle DOUT1 |
| `OUT2=…` / `OUT3=…` | Same for DOUT2 / DOUT3 |

#### PWM outputs

| Payload | Effect |
|---|---|
| `PWM1=OFF` or `PWM1=0` | Disable PWM channel 1 (0 % duty) |
| `PWM1=ON` | Set PWM channel 1 to 100 % |
| `PWM1=75` | Set PWM channel 1 to 75 % (0–100) |
| `PWM2=…` … `PWM4=…` | Same for channels 2–4 |

#### RGB LED strip

| Payload | Effect |
|---|---|
| `RGB=0xff,R,G,B` | Set all LEDs to colour R,G,B |
| `RGB=<n>,R,G,B` | Set LED index `n` to colour R,G,B |
| `RGB_BRIGHTNESS=<0-100>` | Set global strip brightness |

### Setting topic — `<name>/SETTING`

| Payload | Effect |
|---|---|
| `IP=192.168.1.x` | Change device IP |
| `GATEWAY=192.168.1.x` | Change gateway |
| `NETMASK=255.255.255.0` | Change netmask |
| `SERVER=192.168.1.x` | Change MQTT broker IP |
| `DHCP=1` / `DHCP=0` | Enable / disable DHCP |
| `NAME=<name>` | Change device name (used as MQTT topic prefix) |
| `PWM_PSC=<value>` | Set PWM timer prescaler |
| `DIMMING=<value>` | Set PWM dimming ramp length (ms steps) |
| `SAVE` | Write current settings to flash |
| `RESET` | Reboot device |
| `SHOW` | Publish all current settings to `<name>/SETTINGS/…` |

### Published output topics

The device publishes state changes automatically:

| Topic | Content |
|---|---|
| `<name>/OUTPUT/DOUT1/` … `DOUT3/` | `ON` or `OFF` |
| `<name>/OUTPUT/PWM1/` … `PWM4/` | Duty cycle `0–100` |
| `<name>/OUTPUT/ADC1/` … `ADC3/` | Raw ADC value |
| `<name>/SETTINGS/…` | IP, GATEWAY, NETMASK, SERVER, DHCP, PWM_PSC, PWM_DIMM, NAME, MAC (on `SHOW` command) |

---

## Default settings

| Parameter | Default value |
|---|---|
| Device IP | `192.168.1.32` |
| Gateway | `192.168.1.1` |
| Netmask | `255.255.255.0` |
| MQTT broker | `192.168.1.2` |
| MQTT port | `1883` |
| DHCP | Disabled |
| Device name | `STM32` |
| PWM prescaler | `0x10` |
| Dimming length | `8` |

---

## Building

Requirements: `arm-none-eabi-gcc`, `cmake ≥ 3.20`, `ninja` (or make).

```bash
cmake --preset debug
cmake --build build/debug/build
```

The output ELF is `build/debug/build/HomeIOv2.elf`. Flash it with OpenOCD, ST-Link, or your preferred programmer.

---

## Caveats and known issues

- The project was started in **late 2023** and uses library snapshots from that time. No dependency updates have been applied since.
- **LwIP** is vendored in the repository at the version pulled by CubeMX — it is not the latest release.
- **STM32 HAL** drivers are also vendored from the CubeMX generation and are not up to date.
- The ENC28J60 driver (`ethernet/`) is a community port and is not officially supported by STMicroelectronics.
- The firmware runs without an RTOS — everything is polled in the main loop. This makes timing sensitive and may cause issues under heavy network load.
- There is no TLS support for MQTT. All traffic is plain-text on port 1883.
- Settings are stored in the last flash page with no wear levelling.
- Error handling is minimal throughout the codebase.

---

## Why ESPHome instead?

If you need a home automation I/O node today, [ESPHome](https://esphome.io/) running on an **ESP32** or **ESP8266** is a significantly better choice:

- Actively maintained with frequent releases
- Native Home Assistant integration via the native API or MQTT
- Hundreds of supported sensors, outputs, and protocols out of the box
- Configuration is a simple YAML file — no C code needed
- OTA firmware updates
- TLS/encrypted MQTT supported
- Much cheaper and more widely available hardware

This repository remains useful only as a **LwIP + ENC28J60 + MQTT bare-metal example** for STM32.
