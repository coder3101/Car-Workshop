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

#ifndef CAR_WORKSHOP_UTILS_H
#define CAR_WORKSHOP_UTILS_H

#include <cstring>
#include "datetime.h"
#define CONFIG_FILE_NAME ".config"

namespace helper {
struct utils {

  static bool check_install_status();
  static void initialize_first_time();
  static void start_menu_run();
  static bool validate_password(const std::string &s);
  static bool change_password();
  static void restore_and_delete_config();
  static void re_authenticate();
  static void _exit();
  static void clear_screen();
};

struct config { // NOLINT
  char password[100];
  date::date_time create_time, last_launch;
  char admin_name[80];
  config() = default;
  config(std::string pass) { // NOLINT
    std::strcpy(password, pass.c_str());
  }
};

class data_register {
  data_register() = default;
 public:
  int total_completed = -1, total_pending = -1;
  static data_register get_data_register_instance();
};

struct ui {
  static void show_main_menu(config c);
  static void launch_option(int x);

};
}

#endif //CAR_WORKSHOP_UTILS_H
