#ifndef DASH_PI_MAIN_HPP
#define DASH_PI_MAIN_HPP

#include <iostream>

#include <controllers/playback_controller.hpp>
#include <renderers/nav_bar.hpp>
#include <renderers/control_bar.hpp>

#include <SFML/Graphics.hpp>

namespace DashPi
{
  class DashPiMain
  {
    public:
      DashPiMain(bool debug_enabled);
      ~DashPiMain();

      void run();

    private:
      bool _debug;
      unsigned int window_width,
                   window_height;
      std::unique_ptr<PlaybackController> _pc;
  };
}

#endif
