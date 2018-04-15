#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <ctime>
#include <iomanip>

namespace DashPi
{
  enum PlaybackState
  {
    PLAYING,
    PAUSED
  };

  const std::vector<std::string> TABS = {"AUDIO", "NAV", "PHONE", ""};
}

#endif
