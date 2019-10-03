#ifndef DURATION_H
#define DURATION_H

#include <string>

namespace duration {
struct Time {
  unsigned hour;
  unsigned minute;
};
std::string computeDuration(Time start, Time end);
} // namespace duration

#endif
