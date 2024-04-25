CXXFLAGS += -MMD --std=c++14 -Wall -Wextra

-include bind.d
-include cmd.d

bind-example: bind.o
	$(CXX) -o $@ $^

cmd-example: cmd.o
	$(CXX) -o $@ $^
