#include <iostream>
#include <cxxopts.hpp>
#include <dash_pi_main.hpp>

using namespace DashPi;

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

  DashPiMain dash(debug);
  dash.run();

  return 0;
}
