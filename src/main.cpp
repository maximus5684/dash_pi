#include <dash_pi.hpp>

using namespace sf;
using namespace DashPi;

int main (int argc, char * argv[])
{
  //Get all of the available full-screen modes.
  std::vector<VideoMode> fs_vms = VideoMode::getFullscreenModes();
  //Select the first (best) one.
  VideoMode vm = fs_vms[0];
  std::cout << "Is valid: " << vm.isValid() << " Size: " << vm.width << " x " << vm.height << "." << std::endl;
  
  RenderWindow window(vm, "Dash Pi", sf::Style::Fullscreen);

  while (window.isOpen())
  {
    sf::Event event;

    while (window.pollEvent(event))
    {
      if (event.type == Event::Closed)
        window.close();
    }

    window.clear(Color::Blue);

    window.display();
  }

  return 0;
}
