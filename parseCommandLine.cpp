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
#include "parseCommandLine.h"
// Allow the builder to specify the default units via define.
#ifndef DEFAULT_UNITS
#define DEFAULT_UNITS 0
#endif

CommandLineParseResult parseCommandLine(QCommandLineParser &parser, Options &options, QString &errorMessage) {
  const QCommandLineOption helpOption = parser.addHelpOption();
  const QCommandLineOption versionOption = parser.addVersionOption();
  parser.addOptions({
      {"units",
        QCoreApplication::translate("main", "Set units of measure, either US (for US Customary Units) or SI (for Metric units)."),
        QCoreApplication::translate("main", "units"),
#if DEFAULT_UNITS==1
        "US"
#else
        "SI"
#endif
        },
      {"height",
        QCoreApplication::translate("main", "Set height in inches for US or centimeters for SI."),
        QCoreApplication::translate("main", "height")},
      {{"weight","mass"},
        QCoreApplication::translate("main", "Set weight in pounds for US or mass in kilograms for SI."),
        QCoreApplication::translate("main", "weight")},
      {"bmi",
        QCoreApplication::translate("main", "Indicate the goal BMI for your height.--Mutually exclusive with weight."),
        QCoreApplication::translate("main", "bmi")}
    });

  if (!parser.parse(QCoreApplication::arguments())) {
    errorMessage = parser.errorText();
    return CommandLineError;
  }

  if (parser.isSet(helpOption))
    return CommandLineHelpRequested;

  if (parser.isSet(versionOption))
    return CommandLineVersionRequested;

  QString value = parser.value("units");
  if (value.toUpper() == "US")
    options.units = BMICalculator::Units::US;
  else {
    if (value.toUpper() == "SI") options.units = BMICalculator::Units::SI;
    else {
      errorMessage = QCoreApplication::translate("main", "Bad value for --units: %1").arg(value);
      return CommandLineError;
    }
  }

  // Used in the following conversions
  bool convertOk;

  // Height is always required.
  if (parser.isSet("height")) {
    value = parser.value("height");
    options.height = value.toDouble(&convertOk);
    if (options.height <= 0.0 || !convertOk) {
      errorMessage = QCoreApplication::translate("main", "Bad value for --height, %1, must be a positive number.").arg(value);
      return CommandLineError;
    }
    // Convert cm to m.
    if (options.units == BMICalculator::Units::SI)
      options.height /= 100.0;
  } else {
    errorMessage = QCoreApplication::translate("main", "--height option is required.");
    return CommandLineError;
  }

  // Check for BMI.
  if (parser.isSet("bmi")) {
    value = parser.value("bmi");
    options.bmi = value.toDouble(&convertOk);
    if (options.bmi <= 0.0 || !convertOk) {
      errorMessage = QCoreApplication::translate("main", "Bad value for --bmi, %1, must be a positive number.").arg(value);
      return CommandLineError;
    } else {
      options.doWeightForBMI = true;
    }
  }

  if (parser.isSet("weight")) {
    if (options.doWeightForBMI) {
      errorMessage = QCoreApplication::translate("main", "--weight and --bmi are exclusive. Use one or other, not both.");
      return CommandLineError;
    }
    value = parser.value("weight");
    options.weight = value.toDouble(&convertOk);
    if (options.weight <= 0.0 || !convertOk) {
      errorMessage = QCoreApplication::translate("main", "Bad value for --weight, %1, must be a positive number.").arg(value);
      return CommandLineError;
    }
  } else {
    if (!options.doWeightForBMI) {
      errorMessage = QCoreApplication::translate("main", "Either one of --weight or --bmi is required.");
      return CommandLineError;
    }
  }

  return CommandLineOk;
}
