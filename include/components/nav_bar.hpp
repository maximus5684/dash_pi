#ifndef NAV_BAR_HPP
#define NAV_BAR_HPP

#include <common.hpp>
#include <SFML/Graphics.hpp>

namespace DashPi
{
  class NavBar : public sf::RenderTexture
  {
    public:
      NavBar();
      ~NavBar();

      void drawElements();

    private:
  };
}

#endif
