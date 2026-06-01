
all: graph2 getRand


graph2: graph2.cpp 
	g++ graph2.cpp  -o graph2 `root-config --cflags --libs`

getRand: getRand.cpp 
	g++ getRand.cpp  -o getRand `root-config --cflags --libs`
clean:
	rm -f graph2 getRand *.d *.pcm *.so



