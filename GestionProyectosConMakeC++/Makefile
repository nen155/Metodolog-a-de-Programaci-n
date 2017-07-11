Make con Macro:
AR= ar
CXX = g++
CXXFLAGS= -Wall -g
LDFLAGS= -L. -lformas
punto.o : include/punto.h src/punto.cpp
	$(CXX) -c $(CXXFLAGS) -o obj/punto.o src/punto.cpp
circulo.o : include/circulo.h src/circulo.cpp
	$(CXX) -c $(CXXFLAGS) -o obj/circulo.o src/circulo.cpp
central.o : include/central.h src/central.cpp
	$(CXX) -c $(CXXFLAGS) -o obj/central.o src/central.cpp
libformas.a : include/punto.o src/circulo.o
	$(AR) rvs lib/libformas.a obj/punto.o obj/circulo.o
