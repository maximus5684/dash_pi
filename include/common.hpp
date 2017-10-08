#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

#include <vector>
#include <string>

namespace DashPi
{
  enum AudioState
  {
    PLAYING,
    PAUSED
  };

  const std::vector<std::string> TABS = {"AUDIO", "VIDEO", "NAV", "PHONE"};
}

#endif
