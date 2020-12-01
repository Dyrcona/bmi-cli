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
#include <QCoreApplication>
#include <QCommandLineParser>
#include <QTextStream>
#include <math.h>
#include "BMICalculator.h"
#include "parseCommandLine.h"

int main(int argc, char *argv[]) {
  // Set up our application object
  QCoreApplication app(argc, argv);
  QCoreApplication::setApplicationName("bmi");
  QCoreApplication::setApplicationVersion("0.1");

  // Get an output stream to stdout.
  QTextStream cout(stdout);
  // Ditto for stderr.
  QTextStream cerr(stderr);

  // Prepare to parse the command line.
  QCommandLineParser parser;
  Options options;
  QString errorMessage;
  switch (parseCommandLine(parser, options, errorMessage)) {
  case CommandLineOk:
    break;
  case CommandLineError:
    cerr << errorMessage << "\n\n";
    cerr << parser.helpText() << '\n';
    return 1;
  case CommandLineVersionRequested:
    cout << QCoreApplication::applicationName() << " " << QCoreApplication::applicationVersion() << '\n';
    return 0;
  case CommandLineHelpRequested:
    parser.showHelp();
    return 0;
  }

  // Set up the BMI calculator object.
  BMICalculator calc(options.units);
  double value;
  if (options.doWeightForBMI)
    value = calc.calculateWeightForBMI(options.height, options.bmi);
  else
    value = calc.calculateBMI(options.height, options.weight);
  cout << roundf(value * 10) / 10 << '\n';

  return 0;
}

