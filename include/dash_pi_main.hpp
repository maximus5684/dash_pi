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
      const float SS_TIMEOUT = 30.0;
      const float SS_FADE_TIME = 5.0;
      bool _debug;
      unsigned int window_width,
                   window_height;
      std::shared_ptr<PlaybackController> _pc;
      sf::Clock ss_clock;
      ScreenSaverState ss_state;
      sf::RectangleShape ss_fade_box;
      sf::Sprite nav_bar_sprite,
                 control_bar_sprite;
  };
}

#endif
