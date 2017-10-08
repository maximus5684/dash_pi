#ifndef CONTROL_BAR_HPP
#define CONTROL_BAR_HPP

#include <common.hpp>
#include <SFML/Graphics.hpp>

namespace DashPi
{
  class ControlBar : public sf::RenderTexture
  {
    public:
      ControlBar();
      ~ControlBar();

      void setAudioState(AudioState state);
      AudioState getAudioState();
      void drawElements();

    private:
      bool play_pause_enabled;
      AudioState play_pause_state;
  };
}

#endif
