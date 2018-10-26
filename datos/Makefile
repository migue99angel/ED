SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -c -I$(INC)

	
# ************ Compilación de módulos ************
$(BIN)/pruebadiccionario: $(OBJ)/pruebadiccionario.o $(OBJ)/Termino.o $(OBJ)/Diccionario.o
	$(CXX)  -o $(BIN)/pruebadiccionario  $(OBJ)/Termino.o $(OBJ)/Diccionario.o  $(OBJ)/pruebadiccionario.o  -I/include

$(OBJ)/Termino.o: $(SRC)/Termino.cpp  
	$(CXX) $(CPPFLAGS) -o $(OBJ)/Termino.o $(SRC)/Termino.cpp  

$(OBJ)/Diccionario.o: $(SRC)/Diccionario.cpp  
	$(CXX) $(CPPFLAGS) -o $(OBJ)/Diccionario.o $(SRC)/Diccionario.cpp 

$(OBJ)/pruebadiccionario.o: $(SRC)/pruebadiccionario.cpp 
	$(CXX) $(CPPFLAGS) -o $(OBJ)/pruebadiccionario.o $(SRC)/pruebadiccionario.cpp  

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(BIN)/* $(SRC)/* $(INC)/* 

mrproper : clean
	-rm $(BIN)/* doc/html/*
