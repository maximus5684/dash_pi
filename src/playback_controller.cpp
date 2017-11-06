#include <controllers/playback_controller.hpp>

using namespace DashPi;

PlaybackController::PlaybackController() :
  _ps()
{
}

PlaybackState PlaybackController::getPlaybackState()
{
  return _ps;
}

void PlaybackController::pausePlayback()
{
  _ps = PlaybackState::PAUSED;
}

void PlaybackController::resumePlayback()
{
  _ps = PlaybackState::PLAYING;
}
