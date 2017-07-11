
SRC = src
INC = include
OBJ = obj
LIB = lib
BIN = bin

CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c
LIBDO = ar rvs

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

# ************ Compilación de módulos ************
$(OBJ)/imagenES.o : $(SRC)/imagenES.cpp $(INC)/imagenES.h
	$(CXX) $(CPPFLAGS) $(SRC)/imagenES.cpp -o $(OBJ)/imagenES.o
$(OBJ)/imagen.o : $(SRC)/imagen.cpp $(INC)/imagen.h $(INC)/imagenES.h
	$(CXX) $(CPPFLAGS) $(SRC)/imagen.cpp -o $(OBJ)/imagen.o
$(OBJ)/transformar.o : $(SRC)/transformar.cpp $(INC)/transformar.h $(INC)/imagen.h
	$(CXX) $(CPPFLAGS) $(SRC)/transformar.cpp -o $(OBJ)/transformar.o
$(LIB)/libimagen.a : $(OBJ)/imagenES.o $(OBJ)/imagen.o $(OBJ)/transformar.o 
	$(LIBDO) $(LIB)/libimagen.a $(OBJ)/imagenES.o $(OBJ)/imagen.o $(OBJ)/transformar.o
$(OBJ)/negativo.o : $(SRC)/negativo.cpp $(INC)/transformar.h $(INC)/imagen.h
	$(CXX) $(CPPFLAGS) $(SRC)/negativo.cpp -o $(OBJ)/negativo.o
$(OBJ)/desplazar.o : $(SRC)/desplazar.cpp $(INC)/transformar.h $(INC)/imagen.h
	$(CXX) $(CPPFLAGS) $(SRC)/desplazar.cpp -o $(OBJ)/desplazar.o
$(BIN)/negativo :  $(OBJ)/negativo.o $(OBJ)/imagen.o $(OBJ)/transformar.o
	$(CXX) -o $(BIN)/negativo  $(OBJ)/negativo.o $(OBJ)/imagenES.o $(OBJ)/imagen.o $(OBJ)/transformar.o
$(BIN)/desplazar :  $(OBJ)/desplazar.o $(OBJ)/imagen.o $(OBJ)/transformar.o
	$(CXX) -o $(BIN)/desplazar  $(OBJ)/desplazar.o $(OBJ)/imagenES.o $(OBJ)/imagen.o $(OBJ)/transformar.o


# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
