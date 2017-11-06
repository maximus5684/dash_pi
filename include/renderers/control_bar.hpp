#ifndef CONTROL_BAR_HPP
#define CONTROL_BAR_HPP

#include <common.hpp>
#include <SFML/Graphics.hpp>

namespace DashPi
{
  class ControlBar : public sf::RenderTexture
  {
    public:
      ControlBar();
      ~ControlBar();

      void drawElements(bool is_playing);
  };
}

#endif
