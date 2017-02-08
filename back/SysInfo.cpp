//
// Created by antoine on 21/01/17.
//

#include "SysInfo.hpp"
#include <unistd.h>
#include <sstream>
#include <fstream>
#include <iomanip>

Metrics::SysInfo::SysInfo() {
  if (uname(&m_uname_buf)) { throw std::exception(); }
  char *login = getlogin();
  if (login) { m_username = login; }
  else { m_username = "can't get username"; }
}

std::string Metrics::SysInfo::getKernelVersion() const {
  return m_uname_buf.release;
}

std::string Metrics::SysInfo::getSystemName() const {
  return m_uname_buf.sysname;
}

std::string Metrics::SysInfo::getHostName() const {
  return m_uname_buf.nodename;
}

std::string Metrics::SysInfo::getArch() const {
  return m_uname_buf.machine;
}

std::string Metrics::SysInfo::getUsername() const {
  return m_username;
}

std::string Metrics::SysInfo::getDate() const {

  struct tm *tm = getLocaltime();
  return Metrics::SysInfo::days[tm->tm_wday]
      + " " + std::to_string(tm->tm_mday)
      + " " + Metrics::SysInfo::months[tm->tm_mon]
      + " " + std::to_string(tm->tm_year + 1900);
}

std::string Metrics::SysInfo::getTime() const {
  struct tm *tm = getLocaltime();
  std::stringstream ss;
  ss << std::setw(2) << std::setfill('0') << tm->tm_hour << ":"
     << std::setw(2) << std::setfill('0') << tm->tm_min << ":"
     << std::setw(2) << std::setfill('0') << tm->tm_sec;
  return ss.str();
}

struct tm *Metrics::SysInfo::getLocaltime() const {
  time_t current_time = time(NULL);
  struct tm *tm = localtime(&current_time);
  if (!tm) { throw std::exception(); }
  return tm;
}

std::string Metrics::SysInfo::getUptime() const {
  int uptime;
  if (!(std::ifstream("/proc/uptime", std::ios::in) >> uptime)) {
    return "invalid uptime";
  }

  std::stringstream uptime_string;
  uptime_string << std::to_string(uptime / seconds_in_year) << " years ";
  uptime %= seconds_in_year;
  uptime_string << std::to_string(uptime / seconds_in_month) << " months ";
  uptime %= seconds_in_month;
  uptime_string << std::to_string(uptime / seconds_in_day) << " days ";
  uptime %= seconds_in_day;
  uptime_string << std::to_string(uptime / seconds_in_hour) << " hours ";
  uptime %= seconds_in_hour;
  uptime_string << std::to_string(uptime / seconds_in_minute) << " minutes ";
  uptime %= seconds_in_minute;
  uptime_string << std::to_string(uptime) << " seconds";
  return uptime_string.str();
}
