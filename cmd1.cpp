#include <iostream>
#include <map>
#include <functional>

namespace poly
{
  void cmd1(const int &, std::istream &, std::ostream & out)
  {
    out << "CMD1 dispatched\n";
  }
  void cmd2(const int &, std::istream &, std::ostream & out)
  {
    out << "CMD2 dispatched\n";
  }
  void cmd3(int &, std::istream &, std::ostream & out)
  {
    out << "CMD3 dispatched\n";
  }
}

int main()
{
  std::string cmd;
  int context = 0;
  std::map< std::string, std::function< void(const int &, std::istream &, std::ostream &) > > const_cmds;
  const_cmds["CMD1"] = poly::cmd1;
  const_cmds["CMD2"] = poly::cmd2;

  std::map< std::string, std::function< void(int &, std::istream &, std::ostream &) > > cmds;
  cmds["CMD3"] = poly::cmd3;

  while (std::cin >> cmd)
  {
    try
    {
      const_cmds.at(cmd)(context, std::cin, std::cout);
    }
    catch (const std::out_of_range &)
    {}
    try
    {
      cmds.at(cmd)(context, std::cin, std::cout);
    }
    catch (const std::out_of_range &)
    {
      std::cout << "<INVALID COMMAND>\n";
    }
  }
}
