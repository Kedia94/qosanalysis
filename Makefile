LIBS=file.o \
	 common.o

all: exhaustive worst ours getconvex best random

exhaustive:exhaustive.o $(LIBS)
	g++ $^ -o $@

worst:worst.o $(LIBS)
	g++ $^ -o $@

best:best.o $(LIBS)
	g++ $^ -o $@

getconvex:getconvex.o $(LIBS)
	g++ $^ -o $@

ours:ours.o $(LIBS)
	g++ $^ -o $@

random:random.o $(LIBS)
	g++ $^ -o $@

%.o:%.cpp
	g++ -c $^

clean:
	rm -rf *.o exhaustive worst best getconvex ours random
