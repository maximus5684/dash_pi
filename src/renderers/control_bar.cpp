#include <renderers/control_bar.hpp>

using namespace sf;
using namespace DashPi;

ControlBar::ControlBar(std::shared_ptr<PlaybackController> pc) :
  RenderTexture(),
  _pc(pc),
  _vc(new VolumeController)
{
}

ControlBar::~ControlBar()
{
}

bool ControlBar::create(unsigned int width, unsigned int height, bool depthBuffer)
{
  //We have to initialize everything up-front so we can tell
  //whether a touch event has happened within the bounds of
  //the controls.

  //Create the control bar background.
  controls.create((float)width, (float)height * 0.75);

  controls_sprite.setTexture(controls.getTexture());
  controls_sprite.setPosition(0, (float)height - controls_sprite.getGlobalBounds().height);

  //Create the play/pause button texture.
  play_pause.create((float)height, (float)height);

  Vector2u controls_size = controls.getSize();
  Vector2u play_pause_size = play_pause.getSize();

  //Define the play/pause button.
  play_pause_btn.setRadius((float)play_pause_size.y * 0.5);
  play_pause_btn.setFillColor(Color::Blue);
  play_pause_btn.setOutlineColor(Color::White);
  play_pause_btn.setOutlineThickness(-2.0);

  //Create the sprite to hold the play/pause texture.
  play_pause_sprite.setTexture(play_pause.getTexture());
  play_pause_sprite.setOrigin(play_pause_sprite.getGlobalBounds().width * 0.5, play_pause_sprite.getGlobalBounds().height * 0.5);
  play_pause_sprite.setPosition((float)width * 0.5, (float)height * 0.5);

  //Create the mute/unmute button texture.
  mute_icon.loadFromFile("../icons/mute_128.png");
  unmute_icon.loadFromFile("../icons/unmute_128.png");

  Vector2u mute_size = mute_icon.getSize();

  //Create the sprite to hold the mute button texture.
  mute_sprite.setTexture(mute_icon);
  mute_sprite.setOrigin(mute_sprite.getGlobalBounds().width, mute_sprite.getGlobalBounds().height); //Bottom right
  mute_sprite.setPosition((float)width, (float)height);
  mute_sprite.setScale(((float)controls_size.y / (float)mute_size.x), ((float)controls_size.y / (float)mute_size.y));

  return RenderTexture::create(width, height, depthBuffer);
}

void ControlBar::handleEvent(sf::Event::TouchEvent touch)
{
  Vector2u bar_size = getSize();
  FloatRect pp_bounds = play_pause_sprite.getGlobalBounds();
  FloatRect mute_bounds = mute_sprite.getGlobalBounds();

  // Play/Pause Button
  if (touch.x > pp_bounds.left &&
      touch.x < (pp_bounds.left + pp_bounds.width) &&
      touch.y > pp_bounds.top)
  {
    if (_pc->getPlaybackState() == PlaybackState::PAUSED)
    {
      _pc->resumePlayback();
    }
    else if (_pc->getPlaybackState() == PlaybackState::PLAYING)
    {
      _pc->pausePlayback();
    }
  }

  // Mute Button
  if (touch.x > mute_bounds.left &&
      touch.x < (mute_bounds.left + mute_bounds.width) &&
      touch.y > mute_bounds.top)
  {
    if (_vc->getCurrentVolume() == 0)
    {
      _vc->unmute();
    }
    else
    {
      _vc->mute();
    }
  }
}

void ControlBar::drawElements(PlaybackState current_state)
{
  Vector2u size = getSize();
  Vector2u play_pause_size = play_pause.getSize();

  controls.clear(Color(150, 150, 150, 255));
  controls.display();

  play_pause.draw(play_pause_btn);

  //Create a play or pause icon.
  if (current_state == PlaybackState::PAUSED)
  {
    ConvexShape play_icon;
    play_icon.setPointCount(3);
    play_icon.setPoint(0, Vector2f(0, 0));
    play_icon.setPoint(1, Vector2f((float)play_pause_size.x * 0.5, (float)play_pause_size.y * 0.25));
    play_icon.setPoint(2, Vector2f(0, (float)play_pause_size.y * 0.5));
    play_icon.setFillColor(Color::White);
    play_icon.setOrigin((float)play_icon.getGlobalBounds().width * 0.5, (float)play_icon.getGlobalBounds().height * 0.5);
    play_icon.setPosition((float)play_pause_size.x * 0.5 + (float)play_pause_size.x * 0.05, (float)play_pause_size.y * 0.5);
    play_pause.draw(play_icon);
  }
  else if (current_state == PlaybackState::PLAYING)
  {
    RectangleShape pause_icon(Vector2f(play_pause_size.x * 0.2, play_pause_size.y * 0.5));
    pause_icon.setFillColor(Color::White);
    pause_icon.setOrigin((float)pause_icon.getGlobalBounds().width * 0.5, (float)pause_icon.getGlobalBounds().height * 0.5);

    pause_icon.setPosition((float)play_pause_size.x * 0.5 - (float)play_pause_size.x * 0.15, (float)play_pause_size.y * 0.5);
    play_pause.draw(pause_icon);

    pause_icon.setPosition((float)play_pause_size.x * 0.5 + (float)play_pause_size.x * 0.15, (float)play_pause_size.y * 0.5);
    play_pause.draw(pause_icon);
  }

  //Clear the texture.
  clear();

  controls_sprite.setTexture(controls.getTexture());
  draw(controls_sprite);

  play_pause_sprite.setTexture(play_pause.getTexture());
  draw(play_pause_sprite);

  if (_vc->getCurrentVolume() == 0)
  {
    mute_sprite.setTexture(unmute_icon);
  }
  else
  {
    mute_sprite.setTexture(mute_icon);
  }

  draw(mute_sprite);

  display();
}
