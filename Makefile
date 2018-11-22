all: exhaustive

exhaustive:exhaustive.o file.o
	g++ $^ -o $@

%.o:%.cpp
	g++ -c $^

clean:
	rm -rf *.o exhaustive
