CXXFLAGS += -MMD --std=c++14 -Wall -Wextra

-include bind.d
-include cmd1.d
-include cmd2.d

bind-example: bind.o
	$(CXX) -o $@ $^

cmd1-example: cmd1.o
	$(CXX) -o $@ $^

cmd2-example: cmd2.o
	$(CXX) -o $@ $^
