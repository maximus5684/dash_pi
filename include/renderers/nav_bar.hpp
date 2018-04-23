#ifndef NAV_BAR_HPP
#define NAV_BAR_HPP

#include <utils.hpp>
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
      static const unsigned int TEXT_CHAR_SIZE;
      sf::Vector2u size;
      float tab_width;
      sf::Font label_font;
      sf::RectangleShape divider;
      std::vector<sf::Text> nav_labels;
      sf::Text colon_label,
               hour_label,
               minute_label,
               second_label;
      bool time_initialized;
      int last_hour, last_min, last_sec;
  };
}

#endif
