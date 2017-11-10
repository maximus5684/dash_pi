#include <dash_pi_main.hpp>

using namespace sf;
using namespace DashPi;

DashPiMain::DashPiMain(bool debug_enabled) :
  _debug(debug_enabled),
  _pc(new PlaybackController())
{
}

DashPiMain::~DashPiMain()
{
}

void DashPiMain::run()
{
  //Get all of the available full-screen modes.
  std::vector<VideoMode> fs_vms = VideoMode::getFullscreenModes();
  //Select the first (best) one.
  VideoMode vm = fs_vms[0];

  if (_debug)
    std::cout << "Screen mode is valid: " << vm.isValid() << " Size: " << vm.width << " x " << vm.height << "." << std::endl;

  window_width = vm.width;
  window_height = vm.height;

  RenderWindow window(vm, "Dash Pi", sf::Style::Fullscreen);
  window.setFramerateLimit(60);

  //Set up the UI elements.
  NavBar nav_bar;
  nav_bar.create(window_width, (window_height * 0.075));

  ControlBar control_bar(_pc);
  control_bar.create(window_width, (window_height * 0.15));

  while (window.isOpen())
  {
    //Render the nav bar.
    nav_bar.drawElements();
    nav_bar.display();

    //Render the control bar.
    PlaybackState current_state = _pc->getPlaybackState();
    control_bar.drawElements(current_state);
    control_bar.display();

    window.clear();

    //Draw the basic UI elements.
    Sprite nav_bar_sprite(nav_bar.getTexture());
    window.draw(nav_bar_sprite);

    Sprite control_bar_sprite(control_bar.getTexture());
    control_bar_sprite.setPosition(0, (window_height - control_bar_sprite.getGlobalBounds().height));
    window.draw(control_bar_sprite);

    window.display();

    sf::Event event;

    //Check for window events last.
    while (window.pollEvent(event))
    {
      if (event.type == Event::Closed)
        window.close();

      if (event.type == Event::TouchBegan)
      {
        //Change to control_bar-local coordinates.
        sf::Event::TouchEvent te = event.touch;
        te.y -= control_bar_sprite.getGlobalBounds().top;
        control_bar.handleEvent(te);
      }
    }
  }
}
