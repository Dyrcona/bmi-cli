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
#ifndef __BMICALCULATOR_H
#define __BMICALCULATOR_H

class BMICalculator {
public:
  enum Units{ SI, US };
  explicit BMICalculator(const BMICalculator::Units u = BMICalculator::Units::SI);
  BMICalculator::Units units();
  void setUnits(BMICalculator::Units u);
  double calculateBMI(double height, double weight);
  double calculateWeightForBMI(double height, double bmi);
private:
  BMICalculator::Units _units;
  double calculateBMISI(double height, double weight);
  double calculateBMIUS(double height, double weight);
  double calculateWeightForBMISI(double height, double bmi);
  double calculateWeightForBMIUS(double height, double bmi);
};

#endif
