#include <dash_pi.hpp>

using namespace sf;
using namespace DashPi;

int main (int argc, char * argv[])
{
  bool debug = false;
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
