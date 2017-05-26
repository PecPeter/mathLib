CC = g++
DEBUG_FLAGS = -g -O0
COMP_FLAGS = -Wall -c -std=c++14 -I ./include
LINK_FLAGS = -Wall -std=c++14 -I ./include

LIB_NAME = mathLib

SRC_DIR = ./src/
OBJ_DIR = ./obj/
SOURCES := $(shell find $(SRC_DIR) -name *.cpp)
VAR = $(SOURCES:${SRC_DIR}%=%)
DEBUG_OBJ = $(VAR:.cpp=_d_src.o)
REL_OBJ = $(VAR:.cpp=_src.o)

LIB_SRC_DIR = ./libsrc/
LIB_OBJ_DIR = ./lib_obj/
LIB_SOURCES := $(shell find $(LIB_SRC_DIR) -name *.cpp)
LIB_VAR = $(LIB_SOURCES:${LIB_SRC_DIR}%=%)
DEBUG_LIB_OBJ = $(LIB_VAR:.cpp=_d_lib.o)
REL_LIB_OBJ = $(LIB_VAR:.cpp=_lib.o)

DEBUG_LIB_FLAGS = -L ./lib -l${LIB_NAME}_debug
RELEASE_LIB_FLAGS = -L ./lib  -l${LIB_NAME}_release

vpath %.hpp ${SRC_DIR} ${LIB_SRC_DIR}
vpath %.cpp ${SRC_DIR} ${LIB_SRC_DIR}
vpath %.o ${OBJ_DIR} ${LIB_OBJ_DIR}

all: debug

libs: dlib rlib

debug: dlib dsrc

release: rlib rsrc

dlib: ${DEBUG_LIB_OBJ}
	ar crv lib${LIB_NAME}_debug.a $(shell find ${LIB_OBJ_DIR} -name *.o)
	mv lib${LIB_NAME}_debug.a ./lib/
	rm -r -f ./include/*
	cp --parents $(shell find $(LIB_SRC_DIR) -name *.hpp) ./include
	mv ./include/$(LIB_SRC_DIR) ./include/${LIB_NAME}

rlib: ${REL_LIB_OBJ}
	ar crv lib${LIB_NAME}_release.a $(shell find ${LIB_OBJ_DIR} -name *.o)
	mv lib${LIB_NAME}_release.a ./lib/
	rm -r -f ./include/*
	cp --parents $(shell find $(LIB_SRC_DIR) -name *.hpp) ./include
	mv ./include/$(LIB_SRC_DIR) ./include/${LIB_NAME}

%_d_lib.o: %.cpp %.hpp
	${CC} ${DEBUG_FLAGS} ${COMP_FLAGS} $< -o ${LIB_OBJ_DIR}$@

%_d_lib.o: %.cpp
	${CC} ${DEBUG_FLAGS} ${COMP_FLAGS} $< -o ${LIB_OBJ_DIR}$@

%_lib.o: %.cpp %.hpp
	${CC} ${COMP_FLAGS} $< -o ${LIB_OBJ_DIR}$@

%_lib.o: %.cpp
	${CC} ${COMP_FLAGS} $< -o ${LIB_OBJ_DIR}$@

dsrc: ${DEBUG_OBJ}
	${CC} $(addprefix ${OBJ_DIR},${DEBUG_OBJ}) -o debug ${DEBUG_LIB_FLAGS}

rsrc: ${REL_OBJ}
	${CC} $(addprefix ${OBJ_DIR},${REL_OBJ}) -o release ${RELEASE_LIB_FLAGS}

%_d_src.o: %.cpp %.hpp
	${CC} ${DEBUG_FLAGS} ${COMP_FLAGS} $< -o ${OBJ_DIR}$@

%_d_src.o: %.cpp
	${CC} ${DEBUG_FLAGS} ${COMP_FLAGS} $< -o ${OBJ_DIR}$@

%_src.o: %.cpp %.hpp
	${CC} ${COMP_FLAGS} $< -o ${OBJ_DIR}$@

%_src.o: %.cpp
	${CC} ${COMP_FLAGS} $< -o ${OBJ_DIR}$@

clean:
	rm -r -f $(shell find ${OBJ_DIR} -name *.o) $(shell find ${LIB_OBJ_DIR} -name *.o) ./include/* ./lib/* release debug
