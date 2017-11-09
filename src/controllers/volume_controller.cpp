#include <controllers/volume_controller.hpp>

using namespace DashPi;
using namespace AlsaPlusPlus;

VolumeController::VolumeController() :
  _mx(new Mixer("default", "Digital")),
  _current_volume(0)
{
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
