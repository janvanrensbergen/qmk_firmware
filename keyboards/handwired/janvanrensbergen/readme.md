# handwired/janvanrensbergen

![handwired/janvanrensbergen](imgur.com image replace me!)

*A short description of the keyboard/project*

* Keyboard Maintainer: [Jan Van Rensbergen](https://github.com/Jan Van Rensbergen)
* Hardware Supported: *The PCBs, controllers supported*
* Hardware Availability: *Links to where you can find this hardware*

Make example for this keyboard (after setting up your build environment):

    make handwired/janvanrensbergen:default

Flashing example for this keyboard:

    make handwired/janvanrensbergen:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
* **Physical reset button**: Briefly press the button on the back of the PCB - some may have pads you must short instead
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available


![liatris](https://splitkb.com/cdn/shop/files/Liatrisrev1.0PinoutDiagram_1146x964.jpg?v=1716979720)
![KB2040](https://cdn-learn.adafruit.com/assets/assets/000/106/984/medium800/adafruit_products_Adafruit_KB2040_Pinout.png?1638564074)

Right side up side down with thumb cluster in right bottom: 

    col4 | col3 | col2 | col1 | col0
    row0
    row1
    row2
    row3


| Elite-c | Liatris | Mapping |
|:--------|:--------|:--------|
| C6      | 5       | col0    |
| D7      | 6       | col1    |
| E6      | 7       | col2    |
| B4      | 8       | col3    |
| B5      | 9       | col4    |
|         |         |         |
| B1      | 22      | row0    |
| B3      | 20      | row1    |
| B2      | 23      | row2    |
| B6      | 21      | row3    |
