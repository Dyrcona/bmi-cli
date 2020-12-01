# bmi-cli

A simple, command line BMI calculator, written in C++ with Qt.

## Installation

### Prerequisites

bmi-cli requires a C++ compiler, conforming to the C++14 standard, and
the [Qt Core Libraries](https://doc.qt.io/qt-5/qtcore-index.html).
Any version of Qt greater than or equal to version 5.4 should work.

You can usually install Qt using your operating system's distribution
packages.  If not, follow [these
directions](https://doc.qt.io/qt-5/gettingstarted.html).

### Configuring

Once you have installed Qt, you should be able to run the `qmake`
command to generate a Makefile to build bmi-cli:

`qmake`

You can also change the default units used in BMI calculations from SI
(metric) to US standard measurements at this step by adding
`DEFAULT_UNITS=1` to the `DEFINES` used when `qmake` generates the
Makefile:

`qmake "DEFINES += DEFAULT_UNITS=1"`

### Compiling

If the above step succeeded in creating a `Makefile`, then you should
be able to compile the `bmi` program by running `make` or your
operating system's equivalent:

`make`

### Installing

After that, you should have a smallish binary named `bmi` in the same
directory as the sources, Makefile, and object files.  You can copy
that binary to wherever you like in order to install it, or just run
it from the current directory if your configuration allows it.

## Usage

<p><code>
Usage: bmi [options]

Options:
  -h, --help                 Displays this help.
  -v, --version              Displays version information.
  --units <units>            Set units of measure, either US (for US Customary
                             Units) or SI (for Metric units).
  --height <height>          Set height in inches for US or centimeters for SI.
  --weight, --mass <weight>  Set weight in pounds for US or mass in kilograms
                             for SI.
  --bmi <bmi>                Indicate the goal BMI for your height.--Mutually
                             exclusive with weight.
</code></p>

Play with it.  You'll figure it out.

## Credits

bmi-cli was written by **Jason Stephenson** - [Sigio](http://www.sigio.com/).

## License

bmi-cli is free software: you can redistribute it and/or modify it
under the terms of version 3 of the GNU General Public License as
published by the Free Software Foundation.

bmi-cli is distributed in the hope that it will be useful, but WITHOUT
ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
for more details.

See the file, `LICENSE.md`, for a copy of the GNU General Public
License or <http://www.gnu.org/licenses/>.
