#include <signal.h>
//#include <stdio.h>
#include <physfs.hpp>
#include <boost/filesystem.hpp>
#include <boost/program_options.hpp>

#include "engine.hpp"
#include "curses.hpp"
#include "fileutils.hpp"

#include "map.hpp"
#include "introstate.hpp"
#include "mapeditorstate.hpp"

#include "util.hpp"

namespace ADWIF
{
  boost::program_options::variables_map options;
}

using namespace ADWIF;
namespace po = boost::program_options;

/* void sig_handler(int code)
{

} */

int main(int argc, char ** argv)
{
  //signal(SIGINT, sig_handler);      /* arrange interrupts to terminate */

  setlocale(LC_CTYPE, "");

  PhysFS::init(argv[0]);

  po::options_description odesc("Usage");

  odesc.add_options()
    ("help", "show this help message")
    ("editor", "start in map editor mode")
    ("unicode", "start in Unicode mode (only use this if your terminal and font support it)");

  po::store(po::parse_command_line(argc, argv, odesc), options);
  po::notify(options);

  if (options.count("help")) {
    std::cout << odesc << "\n";
    return 1;
  }

  dirSep = PhysFS::getDirSeparator();
  writeDir = PhysFS::getUserDir() + dirSep + ".adwif";
  dataDir = PhysFS::getBaseDir() + dirSep + "data";
  dataFile = PhysFS::getBaseDir() + dirSep + "data.dat";
  saveDir = writeDir + dirSep + "save";

  boost::filesystem::create_directory(writeDir);
  boost::filesystem::create_directory(saveDir);

  PhysFS::setWriteDir(writeDir);
  PhysFS::mount(dataDir, "/", false);
  PhysFS::mount(dataFile, "/", true);

  std::shared_ptr<Renderer> renderer;
  std::shared_ptr<Input> input;
  std::shared_ptr<Engine> engine;

  renderer.reset(new CursesRenderer());
  input.reset(new CursesInput(renderer));

  if (!renderer->init())
  {
    std::cerr << "Error initialising the display system." << std::endl;
    return 1;
  }

  if (!input->init())
  {
    std::cerr << "Error initialising the input system." << std::endl;
    return 1;
  }

  engine.reset(new Engine(renderer, input));

  std::shared_ptr<GameState> state;

  if(options.count("editor"))
    state.reset(new MapEditorState(engine));
  else
    state.reset(new IntroState(engine));

  engine->addState(state);

  int ret = engine->start();

  PhysFS::deinit();

  return ret;
}
