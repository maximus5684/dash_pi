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
  controls_rt.create((float)width, (float)height * 0.75);

  Vector2u controls_size = controls_rt.getSize();

  controls_sprite.setTexture(controls_rt.getTexture());
  controls_sprite.setPosition(0, (float)height - (float)controls_sprite.getGlobalBounds().height);

  //Define the play/pause button.
  play_pause_btn.setRadius((float)height * 0.5);
  play_pause_btn.setFillColor(Color::Blue);
  //play_pause_btn.setOutlineColor(Color::Black);
  //play_pause_btn.setOutlineThickness(-2.0);
  play_pause_btn.setOrigin((float)play_pause_btn.getGlobalBounds().width * 0.5, (float)play_pause_btn.getGlobalBounds().height * 0.5);
  play_pause_btn.setPosition((float)width * 0.5, (float)height * 0.5);

  FloatRect pp_btn_bounds = play_pause_btn.getGlobalBounds();

  //Define the play/pause icons.
  playing_icon.loadFromFile("../icons/playing_128.png");
  paused_icon.loadFromFile("../icons/paused_128.png");

  Vector2u play_icon_size = playing_icon.getSize();

  //Create the sprite to hold the play/pause icon.
  play_pause_icon_sprite.setTexture(playing_icon);
  play_pause_icon_sprite.setScale(((float)height / (float)play_icon_size.x) * 0.75, ((float)height / (float)play_icon_size.y) * 0.75);
  play_pause_icon_sprite.setOrigin((float)play_pause_icon_sprite.getLocalBounds().width * 0.5, (float)play_pause_icon_sprite.getLocalBounds().height * 0.5);
  play_pause_icon_sprite.setPosition((float)width * 0.5, (float)height * 0.5);

  //Create the mute/unmute button texture.
  muted_icon.loadFromFile("../icons/muted_128.png");
  unmuted_icon.loadFromFile("../icons/unmuted_128.png");

  Vector2u mute_size = muted_icon.getSize();

  //Create the sprite to hold the mute button texture.
  mute_sprite.setTexture(muted_icon);
  mute_sprite.setScale(((float)controls_size.y / (float)mute_size.x), ((float)controls_size.y / (float)mute_size.y));
  mute_sprite.setOrigin(mute_sprite.getLocalBounds().width, mute_sprite.getLocalBounds().height); //Bottom right
  mute_sprite.setPosition((float)width, (float)height);

  return RenderTexture::create(width, height, depthBuffer);
}

void ControlBar::handleEvent(sf::Event::TouchEvent touch)
{
  Vector2u bar_size = getSize();
  FloatRect pp_bounds = play_pause_btn.getGlobalBounds();
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
  //Clear the texture.
  clear();

  controls_rt.clear(Color(150, 150, 150, 255));
  controls_rt.display();
  controls_sprite.setTexture(controls_rt.getTexture());

  draw(controls_sprite);
  draw(play_pause_btn);

  //Draw a play or pause icon.
  if (current_state == PlaybackState::PAUSED)
  {
    play_pause_icon_sprite.setTexture(paused_icon);
  }
  else if (current_state == PlaybackState::PLAYING)
  {
    play_pause_icon_sprite.setTexture(playing_icon);
  }

  draw(play_pause_icon_sprite);

  if (_vc->getCurrentVolume() == 0)
  {
    mute_sprite.setTexture(muted_icon);
  }
  else
  {
    mute_sprite.setTexture(unmuted_icon);
  }

  draw(mute_sprite);

  display();
}
