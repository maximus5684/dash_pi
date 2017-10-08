#include <dash_pi.hpp>

using namespace sf;
using namespace DashPi;

AudioState audio_state = AudioState::PAUSED;

void toggle_audio_state()
{
  if (audio_state == AudioState::PAUSED)
    audio_state = AudioState::PLAYING;
  else if (audio_state == AudioState::PLAYING)
    audio_state = AudioState::PAUSED;
}

int main (int argc, char * argv[])
{
  bool debug = false;
  float window_width, window_height;
  cxxopts::Options options("dash_pi", "A full media center for your vehicle dash running on a Raspberry Pi!");

  //Try to parse the command-line arguments.
  try
  {
    options.add_options()
      ("d,debug", "Enable debugging output.")
      ("h,help", "Show the help screen and exit.");
    options.parse(argc, argv);
  }
  catch (const cxxopts::OptionException& e)
  {
    std::cerr << "Error parsing command-line options: " << e.what() << std::endl << std::endl;
    std::cout << options.help() << std::endl;
    return -1;
  }

  if (options.count("help"))
  {
    //Output the help screen and exit.
    std::cout << options.help() << std::endl;
    return 0;
  }
  else if (options.count("debug"))
  {
    //Enable debugging.
    debug = true;
  }
  
  //Get all of the available full-screen modes.
  std::vector<VideoMode> fs_vms = VideoMode::getFullscreenModes();
  //Select the first (best) one.
  VideoMode vm = fs_vms[0];

  if (debug)
    std::cout << "Screen mode is valid: " << vm.isValid() << " Size: " << vm.width << " x " << vm.height << "." << std::endl;

  window_width = vm.width;
  window_height = vm.height;
  
  RenderWindow window(vm, "Dash Pi", sf::Style::Fullscreen);

  //Set up the UI elements.
  NavBar nav_bar;
  nav_bar.create(window_width, (window_height * 0.075));

  ControlBar control_bar;
  control_bar.create(window_width, (window_height * 0.15));

  while (window.isOpen())
  {
    sf::Event event;

    //Check for window events.
    while (window.pollEvent(event))
    {
      if (event.type == Event::Closed)
        window.close();

      if (event.type == Event::KeyPressed && event.key.code == Keyboard::Space)
        toggle_audio_state();
    }

    //Render the nav bar.
    nav_bar.drawElements();
    nav_bar.display();

    //Render the control bar.
    control_bar.setAudioState(audio_state);
    control_bar.drawElements();
    control_bar.display();

    window.clear();

    //Draw the basic UI elements.
    Sprite nav_bar_sprite(nav_bar.getTexture());
    window.draw(nav_bar_sprite);

    Sprite control_bar_sprite(control_bar.getTexture());
    control_bar_sprite.setPosition(0, (window_height - control_bar_sprite.getGlobalBounds().height));
    window.draw(control_bar_sprite);

    window.display();
  }

  return 0;
}
