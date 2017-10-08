#include <components/control_bar.hpp>

using namespace DashPi;
using sf::Vector2u;
using sf::Vector2f;
using sf::Color;
using sf::Font;
using sf::Text;
using sf::CircleShape;
using sf::RectangleShape;
using sf::ConvexShape;
using sf::RenderTexture;
using sf::Sprite;

ControlBar::ControlBar() :
  RenderTexture(),
  play_pause_enabled(true),
  play_pause_state(AudioState::PAUSED)
{
}

ControlBar::~ControlBar()
{
}

void ControlBar::setAudioState(AudioState state)
{
  play_pause_state = state;
}

AudioState ControlBar::getAudioState()
{
  return play_pause_state;
}

void ControlBar::drawElements()
{
  Vector2u size = getSize();
  float text_vert_offset = size.y * 0.1;
  RenderTexture controls, play_pause;

  //Create the control buttons.
  controls.create((float)size.x, (float)size.y * 0.75);
  controls.clear(Color(150, 150, 150, 255));
  controls.display();

  //Create the play/pause button.
  play_pause.create((float)size.y, (float)size.y);

  Vector2u play_pause_size = play_pause.getSize();

  CircleShape play_pause_btn((float)play_pause_size.y / 2.0);
  play_pause_btn.setFillColor(Color::Blue);
  play_pause_btn.setOutlineColor(Color::White);
  play_pause_btn.setOutlineThickness(-2.0);

  play_pause.draw(play_pause_btn);

  //Create a play or pause icon.
  if (play_pause_state == AudioState::PAUSED)
  {
    ConvexShape play_icon;
    play_icon.setPointCount(3);
    play_icon.setPoint(0, Vector2f(0, 0));
    play_icon.setPoint(1, Vector2f((float)play_pause_size.x / 2.0, (float)play_pause_size.y / 4.0));
    play_icon.setPoint(2, Vector2f(0, (float)play_pause_size.y / 2.0));
    play_icon.setFillColor(Color::White);
    play_icon.setOrigin((float)play_icon.getGlobalBounds().width / 2.0, (float)play_icon.getGlobalBounds().height / 2.0);
    play_icon.setPosition((float)play_pause_size.x / 2.0 + (float)play_pause_size.x * 0.05, (float)play_pause_size.y / 2.0);
    play_pause.draw(play_icon);
  }
  else if (play_pause_state == AudioState::PLAYING)
  {
    RectangleShape pause_icon(Vector2f(play_pause_size.x * 0.2, play_pause_size.y * 0.5));
    pause_icon.setFillColor(Color::White);
    pause_icon.setOrigin((float)pause_icon.getGlobalBounds().width / 2.0, (float)pause_icon.getGlobalBounds().height / 2.0);

    pause_icon.setPosition((float)play_pause_size.x / 2.0 - (float)play_pause_size.x * 0.15, (float)play_pause_size.y / 2.0);
    play_pause.draw(pause_icon);

    pause_icon.setPosition((float)play_pause_size.x / 2.0 + (float)play_pause_size.x * 0.15, (float)play_pause_size.y / 2.0);
    play_pause.draw(pause_icon);
  }

  //Clear the texture.
  clear();

  Sprite controls_sprite(controls.getTexture());
  controls_sprite.setPosition(0, (float)size.y - controls_sprite.getGlobalBounds().height);

  draw(controls_sprite);

  Sprite play_pause_sprite(play_pause.getTexture());
  play_pause_sprite.setOrigin(play_pause_sprite.getGlobalBounds().width / 2.0, play_pause_sprite.getGlobalBounds().height / 2.0);
  play_pause_sprite.setPosition((float)size.x / 2.0, (float)size.y / 2.0);
  draw(play_pause_sprite);

  display();
}
