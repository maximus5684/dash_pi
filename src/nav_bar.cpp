#include <components/nav_bar.hpp>

using namespace DashPi;
using sf::Color;
using sf::Font;
using sf::Text;
using sf::Vector2f;
using sf::Vector2u;
using sf::RectangleShape;

NavBar::NavBar() :
  RenderTexture()
{
}

NavBar::~NavBar()
{
}

void NavBar::drawElements()
{
  Vector2u size = getSize();
  float tab_width = size.x / (float)TABS.size();
  float text_vert_offset = size.y * 0.1;

  Font label_font;
  label_font.loadFromFile("/usr/share/fonts/truetype/freefont/FreeSans.ttf");

  //Clear the texture.
  clear(Color(150, 150, 150, 255));

  //Draw the dividers.
  RectangleShape divider(Vector2f(3.0, ((float)size.y - 8.0)));
  divider.setOutlineThickness(-1.0);
  divider.setOutlineColor(Color::Black);
  divider.setPosition(tab_width - 1.5, 2.0);

  for (unsigned int i = 0; i < TABS.size() - 1; i++)
  {
    divider.setPosition((tab_width + (tab_width * i)) - 1.5, 4.0);
    draw(divider);
  }

  //Draw the labels.
  float nav_label_x;
  float nav_label_y;

  Text nav_label;
  nav_label.setFont(label_font);
  nav_label.setStyle(Text::Bold);

  for (unsigned int i = 0; i < TABS.size(); i++)
  {
    nav_label.setString(TABS[i]);
    nav_label_x = (tab_width / 2.0 + tab_width * i) - (nav_label.getLocalBounds().width / 2.0);
    nav_label_y = (size.y / 2.0) - (nav_label.getLocalBounds().height / 2.0) - text_vert_offset;
    nav_label.setPosition(nav_label_x, nav_label_y);
    draw(nav_label);
  }
}
