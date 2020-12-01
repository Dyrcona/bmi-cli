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
#include "BMICalculator.h"

BMICalculator::BMICalculator(const BMICalculator::Units u)
  : _units(u) {}

BMICalculator::Units BMICalculator::units() {
  return _units;
}

void BMICalculator::setUnits(BMICalculator::Units u) {
  _units = u;
}

double BMICalculator::calculateBMI(double height, double weight) {
  double value = 0.0;
  if (_units == BMICalculator::Units::US) {
    value = this->calculateBMIUS(height, weight);
  } else {
    value = this->calculateBMISI(height, weight);
  }
  return value;
}

double BMICalculator::calculateBMISI(double height, double weight) {
  return weight / (height  * height);
}

double BMICalculator::calculateBMIUS(double height, double weight) {
  return weight / (height * height) * 703;
}

double BMICalculator::calculateWeightForBMI(double height, double bmi) {
  double value = 0.0;
  if (_units == BMICalculator::Units::US) {
    value = this->calculateWeightForBMIUS(height, bmi);
  } else {
    value = this->calculateWeightForBMISI(height, bmi);
  }
  return value;
}

double BMICalculator::calculateWeightForBMISI(double height, double bmi) {
  return bmi * height * height;
}

double BMICalculator::calculateWeightForBMIUS(double height, double bmi) {
  return bmi * (height * height) / 703;
}
