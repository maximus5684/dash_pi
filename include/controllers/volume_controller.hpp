#ifndef AUDIO_CONTROLLER_HPP
#define AUDIO_CONTROLLER_HPP

#include <common.hpp>
#include <alsaplusplus/mixer.hpp>

namespace DashPi
{
  class VolumeController
  {
    public:
      VolumeController();

      void down();
      void up();
      void mute();
      void unmute();
      float getCurrentVolume();

    private:
      std::unique_ptr<AlsaPlusPlus::Mixer> _mx;
      float _current_volume;
  };
}

#endif
