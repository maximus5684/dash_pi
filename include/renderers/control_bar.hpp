#ifndef CONTROL_BAR_HPP
#define CONTROL_BAR_HPP

#include <common.hpp>
#include <SFML/Graphics.hpp>
#include <controllers/playback_controller.hpp>
#include <controllers/volume_controller.hpp>

namespace DashPi
{
  class ControlBar : public sf::RenderTexture
  {
    public:
      ControlBar(std::shared_ptr<PlaybackController> pc);
      ~ControlBar();

      bool create(unsigned int width, unsigned int height, bool depthBuffer=false);
      void handleEvent(sf::Event::TouchEvent touch);
      void drawElements(PlaybackState current_state);

    private:
      std::shared_ptr<PlaybackController> _pc;
      std::unique_ptr<VolumeController> _vc;
      sf::Texture mute_icon,
                  unmute_icon;
      sf::RenderTexture controls,
                        play_pause;
      sf::CircleShape play_pause_btn;
      sf::Sprite controls_sprite,
                 play_pause_sprite,
                 mute_sprite;
  };
}

#endif
