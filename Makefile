LIBS=file.o \
	 common.o

all: exhaustive worst ours

exhaustive:exhaustive.o $(LIBS)
	g++ $^ -o $@

worst:worst.o $(LIBS)
	g++ $^ -o $@

ours:ours.o $(LIBS)
	g++ $^ -o $@

%.o:%.cpp
	g++ -c $^

clean:
	rm -rf *.o exhaustive worst ours
