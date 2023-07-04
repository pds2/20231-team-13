CC=g++
TARGET=sistema_restaurante

BUILD_DIR = ./build
SRC_DIR = ./src
INCLUDE_DIR = ./include
PROGRAM_DIR = ./program

${TARGET}: ${BUILD_DIR}/cadastro.o ${BUILD_DIR}/caixa.o ${BUILD_DIR}/cardapio.o ${BUILD_DIR}/comanda.o ${BUILD_DIR}/conta.o ${BUILD_DIR}/estoque.o ${BUILD_DIR}/menu.o ${BUILD_DIR}/main.o
	${CC} -o ${TARGET} ${BUILD_DIR}/*.o

${BUILD_DIR}/cadastro.o: ${INCLUDE_DIR}/cadastro.h ${SRC_DIR}/cadastro.cpp
	${CC} -I ${INCLUDE_DIR} -c ${SRC_DIR}/cadastro.cpp -o ${BUILD_DIR}/cadastro.o

${BUILD_DIR}/caixa.o: ${INCLUDE_DIR}/caixa.h ${SRC_DIR}/caixa.cpp
	${CC} -I ${INCLUDE_DIR} -c ${SRC_DIR}/caixa.cpp -o ${BUILD_DIR}/caixa.o

${BUILD_DIR}/cardapio.o: ${INCLUDE_DIR}/cardapio.h ${SRC_DIR}/cardapio.cpp
	${CC} -I ${INCLUDE_DIR} -c ${SRC_DIR}/cardapio.cpp -o ${BUILD_DIR}/cardapio.o

${BUILD_DIR}/comanda.o: ${INCLUDE_DIR}/comanda.h ${SRC_DIR}/comanda.cpp
	${CC} -I ${INCLUDE_DIR} -c ${SRC_DIR}/comanda.cpp -o ${BUILD_DIR}/comanda.o

${BUILD_DIR}/conta.o: ${INCLUDE_DIR}/conta.h ${SRC_DIR}/conta.cpp
	${CC} -I ${INCLUDE_DIR} -c ${SRC_DIR}/conta.cpp -o ${BUILD_DIR}/conta.o

${BUILD_DIR}/estoque.o: ${INCLUDE_DIR}/estoque.h ${SRC_DIR}/estoque.cpp
	${CC} -I ${INCLUDE_DIR} -c ${SRC_DIR}/estoque.cpp -o ${BUILD_DIR}/estoque.o

${BUILD_DIR}/menu.o: ${INCLUDE_DIR}/menu.h ${SRC_DIR}/menu.cpp
	${CC} -I ${INCLUDE_DIR} -c ${SRC_DIR}/menu.cpp -o ${BUILD_DIR}/menu.o

${BUILD_DIR}/main.o: ${INCLUDE_DIR}/cadastro.h ${INCLUDE_DIR}/caixa.h ${INCLUDE_DIR}/menu.h ${INCLUDE_DIR}/cardapio.h ${INCLUDE_DIR}/comanda.h ${INCLUDE_DIR}/conta.h ${INCLUDE_DIR}/estoque.h ${PROGRAM_DIR}/main.cpp
	${CC} -I ${INCLUDE_DIR} -c ${PROGRAM_DIR}/main.cpp -o ${BUILD_DIR}/main.o
	

clean:
	rm -f ${BUILD_DIR}/*
