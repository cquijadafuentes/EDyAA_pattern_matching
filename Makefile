CXX=g++

CXXFLAGS=-Wall -g -O2 

OBJECTS=text_search.o 

BINS=text_search_prueba text_search_time text_search_muestra_rabin_karp

all: clean $(OBJECTS) $(BINS)

text_search_prueba:
	$(CXX) $(CXXFLAGS) text_search_prueba.cpp $(OBJECTS) -o text_search_prueba 

text_search_time:
	$(CXX) $(CXXFLAGS) text_search_time.cpp $(OBJECTS) -o text_search_time 

text_search_muestra_rabin_karp:
	$(CXX) $(CXXFLAGS) text_search_muestra_rabin_karp.cpp $(OBJECTS) -o text_search_muestra_rabin_karp 

clean :
	rm -f $(OBJECTS) $(BINS)