#include <controllers/volume_controller.hpp>

using namespace DashPi;
using namespace AlsaPlusPlus;

VolumeController::VolumeController() :
  _current_volume(0)
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
