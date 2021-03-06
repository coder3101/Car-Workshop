/*
*   Copyright (c) Ashar Khan 2018. <ashar786khan@gmail.com>
*    This file is part of CSE202 Car Workshop Project.
*   Car Workshop is free software : you can redistribute it and/or modify
*    it under the terms of GNU General Public License as published by the Free Software Foundation,
*   either version 3 of the License, or (at your option) any later version.
*
*   This Application is distributed in the hope that it will be useful
*    but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
*   or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General  Public License for more details.
*
*   You should have received a copy of the GNU General Public License along with this Source File.
*   If not, see <http:www.gnu.org/licenses/>.
*/

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"

#include <cstring>
#include <iostream>
#include <iomanip>
#include "problem_map.h"

using namespace problem;

void problem_map::describe() const {
  using namespace std;
  cout << "\n\n";
  for (int i = 0; i < problem_count; ++i) {
    cout.width(45);
    cout << std::right << "Problem " << i + 1 << " is : " << problems[i];
    cout.width(30);
    cout << std::right << "Cost of Repair : " << costINR[i] << endl;
  }
}
bool problem_map::assign_problem(const char *d, int cost) {
  if (problem_count > 49)
    return false;
  else {
    strcpy(problems[problem_count], d);
    costINR[problem_count] = cost;
    problem_count++;
    return true;
  }
}
void problem_map::undo_last_problem() {
  --problem_count;
}
bool problem_map::remove_problem_named(const char *d) {
  bool found = false;
  for (int t = 0; t < problem_count; t++) {
    if (strcmp(d, problems[t]) == 0) {
      __delete_entry(t);
      found = true;
      break;
    }
  }
  return found;

}
problem_map::problem_map(const char *t) {
  strcpy(type, t);
}
void problem_map::__delete_entry(int t) {
  strcpy(problems[t], problems[problem_count - 1]);
  costINR[t] = costINR[problem_count - 1];
  problem_count--;
}
