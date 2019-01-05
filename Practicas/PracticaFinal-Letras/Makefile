SRC = src
INC = include
OBJ = obj
BIN = bin
LIB = lib
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c




# **** Compilación de módulos ****

#************* testlista_palabras *****************************
testlista_palabras: $(BIN)/testlista_palabras

$(BIN)/testlista_palabras: $(OBJ)/testlista_palabras.o $(LIB)/libletras.a
	$(CXX) -o $(BIN)/testlista_palabras $(OBJ)/testlista_palabras.o -L$(LIB) -lletras

$(OBJ)/testlista_palabras.o : $(SRC)/testlista_palabras.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/testlista_palabras.o $(SRC)/testlista_palabras.cpp 

#***************** letras *************************************
letras: $(BIN)/letras		

$(BIN)/letras: $(OBJ)/letras.o $(LIB)/libletras.a
	$(CXX) -o $(BIN)/letras $(OBJ)/letras.o -L$(LIB) -lletras

$(OBJ)/letras.o : $(SRC)/letras.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/letras.o $(SRC)/letras.cpp 

#***************** cantidad_de_letras *************************************	
cantidad_de_letras: $(BIN)/cantidad_de_letras			

$(BIN)/cantidad_de_letras: $(OBJ)/cantidad_de_letras.o $(LIB)/libletras.a
	$(CXX) -o $(BIN)/cantidad_de_letras $(OBJ)/cantidad_de_letras.o -L$(LIB) -lletras

$(OBJ)/cantidad_de_letras.o : $(SRC)/cantidad_de_letras.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/cantidad_de_letras.o $(SRC)/cantidad_de_letras.cpp 

#************* testbolsa_letras *****************************

testbolsa_letras: $(BIN)/testbolsa_letras

$(BIN)/testbolsa_letras: $(OBJ)/testbolsa_letras.o $(LIB)/libletras.a
	$(CXX) -o $(BIN)/testbolsa_letras $(OBJ)/testbolsa_letras.o -L$(LIB) -lletras

$(OBJ)/testbolsa_letras.o : $(SRC)/testbolsa_letras.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/testbolsa_letras.o $(SRC)/testbolsa_letras.cpp 


# **** Generación de libreria ******


$(LIB)/libletras.a : $(OBJ)/lista_palabras.o $(OBJ)/letra.o $(OBJ)/conjunto_letras.o $(OBJ)/bolsa_letras.o
	ar rvs $(LIB)/libletras.a $(OBJ)/lista_palabras.o $(OBJ)/letra.o $(OBJ)/conjunto_letras.o $(OBJ)/bolsa_letras.o

$(OBJ)/letra.o : $(SRC)/letra.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/letra.o $(SRC)/letra.cpp 

$(OBJ)/conjunto_letras.o : $(SRC)/conjunto_letras.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/conjunto_letras.o $(SRC)/conjunto_letras.cpp 

$(OBJ)/bolsa_letras.o : $(SRC)/bolsa_letras.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/bolsa_letras.o $(SRC)/bolsa_letras.cpp 

$(OBJ)/lista_palabras.o : $(SRC)/lista_palabras.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/lista_palabras.o $(SRC)/lista_palabras.cpp 



# **** Generación de documentación ******
documentacion:
	doxygen doc/doxys/Doxyfile
	

# **** Ejecutar ****
exec_lista: testlista_palabras
	./$(BIN)/testlista_palabras ./datos/spanish.txt

exec_cantidad: cantidad_de_letras
	./$(BIN)/cantidad_de_letras	datos/spanish.txt datos/letras.txt datos/salida.txt

exec_letras_puntos: letras
	./$(BIN)/letras datos/spanish.txt datos/letras.txt 8 P

exec_letras_long: letras
	./$(BIN)/letras datos/spanish.txt datos/letras.txt 8 L	

exec_bolsa: testbolsa_letras
	./$(BIN)/testbolsa_letras ./datos/letras.txt


# **** Limpieza ****
clean :
	-rm $(OBJ)/* $(BIN)/*~ $(LIB)/*~ 

mrproper : clean
	-rm doc/html/*
