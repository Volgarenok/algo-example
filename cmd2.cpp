#include <iostream>
#include <map>
#include <limits>
#include <functional>

namespace poly
{
  void cmd1(const int &, std::istream &, std::ostream & out)
  {
    //...
    out << "CMD1 dispatched\n";
  }
  void cmd2(const int &, std::istream &, std::ostream & out)
  {
    //...
    out << "CMD2 dispatched\n";
  }
  void cmd3(int &, std::istream &, std::ostream & out)
  {
    //...
    out << "CMD3 dispatched\n";
  }
  void cmd4(std::istream &, std::ostream & out)
  {
    //...
    out << "Hahahaha\n";
    throw std::overflow_error{"overflow cmd4"};
  }
}

int main()
{
  int context = 0;
  std::map< std::string, std::function< void(std::istream &, std::ostream &) > > cmds;
  {
    using namespace std::placeholders;
    cmds["CMD1"] = std::bind(poly::cmd1, context, _1, _2);
    cmds["CMD2"] = std::bind(poly::cmd2, context, _1, _2);
    cmds["CMD3"] = std::bind(poly::cmd3, context, _1, _2);
  }

  std::string cmd;
  while (std::cin >> cmd)
  {
    try
    {
      cmds.at(cmd)(std::cin, std::cout);
    }
    catch (const std::overflow_error & e)
    {
      std::cerr << "<ERROR: " << e.what() << ">\n";
    }
    catch (const std::out_of_range &)
    {
      std::cerr << "<INVALID COMMAND>\n";
      std::cin.ignore(std::numeric_limits< std::streamsize >::max(), '\n');
    }
  }
}
