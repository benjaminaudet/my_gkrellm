//
// Created by antoine on 21/01/17.
//

#ifndef SWEGTOP_SYSINFO_HPP
#define SWEGTOP_SYSINFO_HPP

#include <string>
#include <sys/utsname.h>
#include <ctime>

namespace Metrics {

class SysInfo {
  /*
   * Used to make date string
   */
  const std::string months[12] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
  const std::string days[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

  /*
   * Used to make uptime string
   */
  const int seconds_in_minute = 60;
  const int seconds_in_hour = 60 * seconds_in_minute;
  const int seconds_in_day = 24 * seconds_in_hour;
  const int seconds_in_month = (int) (30.5 * seconds_in_day);
  const int seconds_in_year = 12 * seconds_in_month;

  struct utsname m_uname_buf;
  std::string m_username;
  struct tm *getLocaltime() const ;
 public:
  SysInfo();
  std::string getKernelVersion() const;
  std::string getSystemName() const ;
  std::string getHostName() const;
  std::string getArch() const;
  std::string getUsername() const;
  std::string getDate() const;
  std::string getTime() const;
  std::string getUptime() const;
};

};

#endif //SWEGTOP_SYSINFO_HPP
