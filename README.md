This is a [PlatformIO](https://platformio.org/) project that coordinates
devices across networks. Put differently, this project is attempting to
coordinate blabbing devices.

## Get Hardware

Use the following links to purchase the hardware needed for this project.

1. [ESP32 LoRa 32 (V2)](https://www.amazon.com/gp/product/B076MSLFC9/ref=ppx_yo_dt_b_asin_title_o01_s00?ie=UTF8&psc=1)
1. [Micro USB Cable](https://www.amazon.com/gp/product/B01JPDTZXK/ref=ppx_od_dt_b_asin_title_s00?ie=UTF8&psc=1)

## Install Dependencies

This project assumes that macOS is the development Operating System (OS).
This may change over time but macOS is the expected devlopment OS.

1. [Install homebrew](https://brew.sh/)
1. Install pyenv - `brew install pyenv`
1. Install python 3.9 - `pyenv install 3.9.0`
1. [Install poetry to manage python project dependencies](https://python-poetry.org/docs/#installation)
1. Clone the project - `git clone git@github.com:collinwat/blab.git`
1. Go to the project - `cd blab`
1. Install dependencies - `poetry install`

## Build

1. All Environments - `poetry run platformio run`
1. Main Environment - `poetry run platformio run -e main`
1. Example Environment - `poetry run platformio run -e example`

## Upload

Make sure the ESP32 LoRa 32 (V2) is plugged into a USB port. PlatformIO will
detect the device once it is plugged in.

1. Main Environment - `poetry run platformio run -e main -t upload`
1. Example Environment - `poetry run platformio run -e example -t upload`
