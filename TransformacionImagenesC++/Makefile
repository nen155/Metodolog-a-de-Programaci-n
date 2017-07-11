BIN = bin
SRC = src
INC = include
OBJ = obj

CXX = g++
CXXFLAGS = -Wall -g  -I$(INC) -c

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

# ************ Compilación de módulos ************
$(OBJ)/imagenES.o : $(SRC)/imagenES.cpp $(INC)/imagenES.h
	$(CXX) $(CXXFLAGS) $(SRC)/imagenES.cpp -o $(OBJ)/imagenES.o
$(OBJ)/imagen.o : $(SRC)/imagen.cpp $(INC)/imagen.h $(INC)/imagenES.h
	$(CXX) $(CXXFLAGS) $(SRC)/imagen.cpp -o $(OBJ)/imagen.o
$(OBJ)/transformacion.o : $(SRC)/transformacion.cpp $(INC)/transformacion.h $(INC)/imagen.h $(INC)/imagenES.h
	$(CXX) $(CXXFLAGS) $(SRC)/transformacion.cpp -o $(OBJ)/transformacion.o
$(OBJ)/generadores.o : $(SRC)/generadores.cpp $(INC)/generadores.h $(INC)/transformacion.h $(INC)/imagen.h $(INC)/imagenES.h
	$(CXX) $(CXXFLAGS) $(SRC)/generadores.cpp -o $(OBJ)/generadores.o
$(OBJ)/transformar.o : $(SRC)/transformar.cpp $(INC)/imagen.h $(INC)/transformacion.h $(INC)/procesar.h
	$(CXX) $(CXXFLAGS) $(SRC)/transformar.cpp -o $(OBJ)/transformar.o
$(OBJ)/procesar.o : $(SRC)/procesar.cpp $(INC)/imagen.h $(INC)/transformacion.h $(INC)/procesar.h
	$(CXX) $(CXXFLAGS) $(SRC)/procesar.cpp -o $(OBJ)/procesar.o
$(OBJ)/generar.o : $(SRC)/generar.cpp $(INC)/imagen.h $(INC)/transformacion.h $(INC)/generadores.h
	$(CXX) $(CXXFLAGS) $(SRC)/generar.cpp -o $(OBJ)/generar.o
$(OBJ)/ocultar.o : $(SRC)/ocultar.cpp $(INC)/procesar.h $(INC)/imagen.h $(INC)/imagenES.h
	$(CXX) $(CXXFLAGS) $(SRC)/ocultar.cpp -o $(OBJ)/ocultar.o
$(OBJ)/revelar.o : $(SRC)/revelar.cpp $(INC)/procesar.h $(INC)/imagen.h $(INC)/imagenES.h
	$(CXX) $(CXXFLAGS) $(SRC)/revelar.cpp -o $(OBJ)/revelar.o
$(OBJ)/componer.o :  $(SRC)/componer.cpp $(INC)/transformacion.h $(INC)/imagen.h $(INC)/imagenES.h
	$(CXX) $(CXXFLAGS) $(SRC)/componer.cpp -o $(OBJ)/componer.o
$(BIN)/ocultar :  $(OBJ)/ocultar.o $(OBJ)/imagen.o $(OBJ)/procesar.o $(OBJ)/transformacion.o
	$(CXX) -o $(BIN)/ocultar  $(OBJ)/ocultar.o $(OBJ)/imagenES.o $(OBJ)/imagen.o $(OBJ)/procesar.o $(OBJ)/transformacion.o
$(BIN)/revelar :  $(OBJ)/revelar.o $(OBJ)/imagen.o $(OBJ)/procesar.o $(OBJ)/transformacion.o
	$(CXX) -o $(BIN)/revelar  $(OBJ)/revelar.o $(OBJ)/imagenES.o $(OBJ)/imagen.o $(OBJ)/procesar.o $(OBJ)/transformacion.o
$(BIN)/transformar :  $(OBJ)/transformar.o $(OBJ)/imagen.o $(OBJ)/imagenES.o
	$(CXX) -o $(BIN)/transformar $(OBJ)/procesar.o $(OBJ)/transformar.o $(OBJ)/imagenES.o $(OBJ)/imagen.o $(OBJ)/transformacion.o
$(BIN)/generar :  $(OBJ)/generar.o $(OBJ)/imagen.o $(OBJ)/imagenES.o
	$(CXX) -o $(BIN)/generar $(OBJ)/generar.o $(OBJ)/procesar.o $(OBJ)/imagenES.o $(OBJ)/imagen.o $(OBJ)/generadores.o $(OBJ)/transformacion.o
$(BIN)/componer :  $(OBJ)/componer.o $(OBJ)/imagen.o $(OBJ)/imagenES.o
	$(CXX) -o $(BIN)/componer $(OBJ)/componer.o $(OBJ)/imagenES.o $(OBJ)/imagen.o $(OBJ)/transformacion.o
	
# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
