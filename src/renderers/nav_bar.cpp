#include <renderers/nav_bar.hpp>

using namespace sf;
using namespace DashPi;

const unsigned int NavBar::TEXT_CHAR_SIZE = 32;

NavBar::NavBar() :
  RenderTexture(),
  time_initialized(false)
{
  label_font.loadFromFile("/usr/share/fonts/truetype/freefont/FreeSans.ttf");

  for (unsigned int i = 0; i < TABS.size(); i++)
  {
    Text nav_label;
    nav_label.setFont(label_font);
    nav_label.setStyle(Text::Bold);
    nav_label.setCharacterSize(NavBar::TEXT_CHAR_SIZE);
    nav_label.setString(TABS[i]);
    nav_label.setOrigin(nav_label.getLocalBounds().width * 0.5, nav_label.getLocalBounds().height * 0.85);
    nav_labels.push_back(nav_label);
  }

  divider.setOutlineThickness(-1.0);
  divider.setOutlineColor(Color::Black);

  colon_label.setFont(label_font);
  colon_label.setStyle(Text::Bold);
  colon_label.setCharacterSize(NavBar::TEXT_CHAR_SIZE);
  colon_label.setString(":");
  colon_label.setOrigin(colon_label.getLocalBounds().width * 0.5, colon_label.getLocalBounds().height);

  hour_label.setFont(label_font);
  hour_label.setStyle(Text::Bold);
  hour_label.setCharacterSize(NavBar::TEXT_CHAR_SIZE);

  minute_label.setFont(label_font);
  minute_label.setStyle(Text::Bold);
  minute_label.setCharacterSize(NavBar::TEXT_CHAR_SIZE);

  second_label.setFont(label_font);
  second_label.setStyle(Text::Bold);
  second_label.setCharacterSize(NavBar::TEXT_CHAR_SIZE);

  auto now = std::chrono::system_clock::now();
  std::time_t now_tt = std::chrono::system_clock::to_time_t(now);
  struct tm* last_tm = std::localtime(&now_tt);

  last_hour = last_tm->tm_hour;
  last_min = last_tm->tm_min;
  last_sec = last_tm->tm_sec;
}

NavBar::~NavBar()
{
}

void NavBar::drawElements()
{
  size = getSize();
  tab_width = size.x / ((float)TABS.size() + 1.0);

  //Clear the texture.
  clear(Color(150, 150, 150, 255));

  //Draw the dividers.
  divider.setSize(Vector2f(3.0, ((float)size.y - 8.0)));

  //Draw the dividers and labels;
  for (unsigned int i = 0; i < TABS.size(); i++)
  {
    divider.setPosition((tab_width + (tab_width * i)) - 1.5, 4.0);
    draw(divider);

    nav_labels[i].setPosition((tab_width * 0.5 + tab_width * i), size.y * 0.5);
    draw(nav_labels[i]);
  }

  colon_label.setPosition(size.x - tab_width * 0.333, size.y * 0.3);
  draw(colon_label);

  colon_label.setPosition(size.x - tab_width * 0.666, size.y * 0.3);
  draw(colon_label);

  auto now = std::chrono::system_clock::now();
  std::time_t now_tt = std::chrono::system_clock::to_time_t(now);
  struct tm* now_tm = std::localtime(&now_tt);

  if (!time_initialized ||
      now_tm->tm_hour != last_hour)
  {
    hour_label.setString(Utils::toStringWithPadding(now_tm->tm_hour, 2));
    hour_label.setOrigin(hour_label.getLocalBounds().width * 0.5, hour_label.getLocalBounds().height * 0.5);
    hour_label.setPosition(size.x - tab_width * 0.8333, size.y * 0.2);
  }

  if (!time_initialized ||
      now_tm->tm_min != last_min)
  {
    minute_label.setString(Utils::toStringWithPadding(now_tm->tm_min, 2));
    minute_label.setOrigin(minute_label.getLocalBounds().width * 0.5, minute_label.getLocalBounds().height * 0.5);
    minute_label.setPosition(size.x - tab_width * 0.5, size.y * 0.2);
  }

  if (!time_initialized ||
      now_tm->tm_sec != last_sec)
  {
    second_label.setString(Utils::toStringWithPadding(now_tm->tm_sec, 2));
    second_label.setOrigin(second_label.getLocalBounds().width * 0.5, second_label.getLocalBounds().height * 0.5);
    second_label.setPosition(size.x - tab_width * 0.1666, size.y * 0.2);
  }

  draw(hour_label);
  draw(minute_label);
  draw(second_label);

  last_hour = now_tm->tm_hour;
  last_min = now_tm->tm_min;
  last_sec = now_tm->tm_sec;

  if (!time_initialized)
    time_initialized = true;
}
