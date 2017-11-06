#include <controllers/audio_controller.hpp>

using namespace DashPi;
using namespace AlsaPlusPlus;

AudioController::AudioController() :
  _mx(new Mixer("default")),
  _current_volume(0)
{
}

void AudioController::decreaseVolume()
{
  _current_volume = _mx->dec_vol_pct(1.0);
}

void AudioController::increaseVolume()
{
  _current_volume = _mx->inc_vol_pct(1.0);
}

void AudioController::muteVolume()
{
  _current_volume = _mx->mute();
}

void AudioController::unmuteVolume()
{
  _current_volume = _mx->unmute();
}
