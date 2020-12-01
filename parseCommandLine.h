/*
 * Copyright © 2020 Jason J.A. Stephenson <jason@sigio.com>
 *
 * This file is part of bmi-cli.
 *
 * bmi-cli is free software: you can redistribute it and/or modify it
 * under the terms of version 3 of the GNU General Public License as
 * published by the Free Software Foundation.
 *
 * bmi-cli is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with bmi-cli.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef __parseCommandLine_H
#define __parseCommandLine_H

#include <QCommandLineParser>
#include "BMICalculator.h"

// Setting up for command line parsing our parse function will return one of these values.
enum CommandLineParseResult
{
  CommandLineOk,
  CommandLineError,
  CommandLineVersionRequested,
  CommandLineHelpRequested
};

struct Options {
  Options() : doWeightForBMI(false) {}
  BMICalculator::Units units;
  bool doWeightForBMI;
  double height;
  union {
    double weight;
    double bmi;
  };
};

CommandLineParseResult parseCommandLine(QCommandLineParser&, Options&, QString&);

#endif
