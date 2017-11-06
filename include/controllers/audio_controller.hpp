#ifndef AUDIO_CONTROLLER_HPP
#define AUDIO_CONTROLLER_HPP

#include <common.hpp>
#include <alsaplusplus/mixer.hpp>

namespace DashPi
{
  class AudioController
  {
    public:
      AudioController();

      void decreaseVolume();
      void increaseVolume();
      void muteVolume();
      void unmuteVolume();

    private:
      std::unique_ptr<AlsaPlusPlus::Mixer> _mx;
      float _current_volume;
  };
}

#endif
