
SRC = src
INC = include
OBJ = obj

CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

# ************ Compilación de módulos ************
$(OBJ)/imagenES.o : $(SRC)/imagenES.cpp $(INC)/imagenES.h
	$(CXX) $(CPPFLAGS) $(SRC)/imagenES.cpp -o $(OBJ)/imagenES.o
$(OBJ)/codificar.o : $(SRC)/codificar.cpp $(INC)/codificar.h
	$(CXX) $(CPPFLAGS) $(SRC)/codificar.cpp -o $(OBJ)/codificar.o


# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
