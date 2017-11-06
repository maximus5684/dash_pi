#ifndef PLAYBACK_CONTROLLER_HPP
#define PLAYBACK_CONTROLLER_HPP

#include <common.hpp>

namespace DashPi
{
  class PlaybackController
  {
    public:
      PlaybackController();

      PlaybackState getPlaybackState();
      void pausePlayback();
      void resumePlayback();

    private:
      PlaybackState _ps;
  };
}

#endif
