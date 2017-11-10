#include <controllers/volume_controller.hpp>

using namespace DashPi;
using namespace AlsaPlusPlus;

VolumeController::VolumeController()
{
  if (Mixer::element_exists("default", "Digital"))
  {
    _mx = std::unique_ptr<Mixer>(new Mixer("default", "Digital"));
  }
  else if (Mixer::element_exists("default", "Master"))
  {
    _mx = std::unique_ptr<Mixer>(new Mixer("default", "Master"));
  }
  else
  {
    _mx = NULL;
  }

  _current_volume = _mx->get_cur_vol_pct();
}

void VolumeController::down()
{
  _current_volume = _mx->dec_vol_pct(0.05);
}

void VolumeController::up()
{
  _current_volume = _mx->inc_vol_pct(0.05);
}

void VolumeController::mute()
{
  _current_volume = _mx->mute();
}

void VolumeController::unmute()
{
  _current_volume = _mx->unmute();
}

float VolumeController::getCurrentVolume()
{
  return _current_volume;
}
