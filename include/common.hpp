#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

#include <vector>
#include <string>
#include <chrono>

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
