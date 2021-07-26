CXX := g++
CXXFLAGS := -std=c++17 -g
LDFLAGS := -lsfml-graphics -lsfml-window -lsfml-system

OBJS := main.o

build: $(OBJS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o snake $(OBJS)

clean:
	rm -f $(OBJS) snake
