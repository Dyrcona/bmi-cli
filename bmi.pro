# ---------------------------------------------------------------
# Copyright © 2020 Jason J.A. Stephenson <jason@sigio.com>
#
# This file is part of bmi-cli.
#
# bmi-cli is free software; you can redistribute it and/or modify it
# under the terms of version 3 of the GNU General Public License as
# published by the Free Software Foundation.
#
# bmi-cli is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# ---------------------------------------------------------------
QT += core
CONFIG += c++14
TARGET = bmi
TEMPLATE = app
SOURCES += main.cpp BMICalculator.cpp parseCommandLine.cpp
HEADERS += BMICalculator.h parseCommandLine.h
