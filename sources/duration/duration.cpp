#include "duration.h"
#include <sstream>

using duration::Time;
using std::string;
using std::stringstream;
using std::to_string;

unsigned getTotalMinutes(Time start, Time end);
string duration::computeDuration(Time start, Time end);

string duration::computeDuration(Time start, Time end) {
  auto total_duration_in_minute =
      getTotalMinutes({start.hour, start.minute}, {end.hour, end.minute});
  return to_string(total_duration_in_minute / 60 % 24) + " " +
         to_string(total_duration_in_minute % 60);
}

unsigned getTotalMinutes(Time start, Time end) {
  auto total_start_minute = start.hour * 60 + start.minute;
  auto total_end_minute = end.hour * 60 + end.minute;
  return total_end_minute > total_start_minute
             ? total_end_minute - total_start_minute
             : total_end_minute + 24 * 60 - total_start_minute;
}
