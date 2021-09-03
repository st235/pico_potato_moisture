# Soil Moisture Sensor

SMS or Soil Moisture Sensor is a small firmware for your raspberry pi pico board that helps you to keep track of moisture in plants' pots.

### Setup

First of all, you need to build binary for your `pi pico`. Just follow the instructions below to assemble executable for your board:

```bash
mkdir build
cd build
cmake ..
make .
```

If this step is over then congratulations 🥳 Now you need to connect your board to pc and copy the `potato_moisture.uf2` file from `build` folder.

### FAQ

**Q**: Why potato?<br>
**A**: [potato mode](https://www.urbandictionary.com/define.php?term=potato%20mode). Long story short: it is a pretty simple DIY receipt and you can literally assemble it from pico, led board, moisture sensor, and scotch


### Screens

<img src="./assets/sms_demo.jpeg" width="480" height="640"></img>

### License

```
MIT License

Copyright (c) 2021 Alexander Dadukin

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
```




