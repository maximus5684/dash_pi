#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <ctime>
#include <iomanip>

#define ENABLE_SS 1

namespace DashPi
{
  enum PlaybackState
  {
    PLAYING,
    PAUSED
  };

  enum ScreenSaverState
  {
    INACTIVE,
    FADING,
    ACTIVE
  };

  const std::vector<std::string> TABS = {"AUDIO", "NAV", "PHONE", ""};
}

#endif
