#ifndef CONTROL_BAR_HPP
#define CONTROL_BAR_HPP

#include <common.hpp>
#include <SFML/Graphics.hpp>
#include <controllers/volume_controller.hpp>

namespace DashPi
{
  class ControlBar : public sf::RenderTexture
  {
    public:
      ControlBar();
      ~ControlBar();

      bool create(unsigned int width, unsigned int height, bool depthBuffer=false);
      void handleEvent(sf::Event event);
      void drawElements(PlaybackState current_state);

    private:
      std::unique_ptr<VolumeController> _vc;
      sf::RenderTexture controls,
                        play_pause,
                        mute;
      sf::CircleShape play_pause_btn;
      sf::Sprite controls_sprite,
                 play_pause_sprite,
                 mute_sprite;
  };
}

#endif
