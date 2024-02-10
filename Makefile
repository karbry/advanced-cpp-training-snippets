BOOST_INC := "C:/Program Files/boost/include/boost-1_63"
GPP_EXE := "C:/msys64/mingw64/bin/g++.exe"
CONWAY_INC_DIR := ConwayGameOfLife/include
CONWAY_SRC_DIR := ConwayGameOfLife/src
BUILD_DIR := build


OBJECTS := $(BUILD_DIR)/main.o $(BUILD_DIR)/conway.o $(BUILD_DIR)/grid.o $(BUILD_DIR)/cell.o


TARGET := $(BUILD_DIR)/main_program


$(TARGET): $(OBJECTS)
	$(GPP_EXE) $(OBJECTS) -o $(TARGET)


$(BUILD_DIR)/main.o : main.cpp
	$(GPP_EXE) -c -I $(BOOST_INC) -I $(CONWAY_INC_DIR) main.cpp -o $(BUILD_DIR)/main.o


$(BUILD_DIR)/conway.o : $(CONWAY_SRC_DIR)/ConwayGameOfLife.cpp $(CONWAY_INC_DIR)/ConwayGameOfLife.hpp
	$(GPP_EXE) -c $(CONWAY_SRC_DIR)/ConwayGameOfLife.cpp -I $(CONWAY_INC_DIR) -o $(BUILD_DIR)/conway.o


$(BUILD_DIR)/grid.o : $(CONWAY_SRC_DIR)/Grid.cpp $(CONWAY_INC_DIR)/Grid.hpp
	$(GPP_EXE) -c $(CONWAY_SRC_DIR)/Grid.cpp -I $(CONWAY_INC_DIR) -o $(BUILD_DIR)/grid.o


$(BUILD_DIR)/cell.o : $(CONWAY_SRC_DIR)/Cell.cpp $(CONWAY_INC_DIR)/Cell.hpp
	$(GPP_EXE) -c $(CONWAY_SRC_DIR)/Cell.cpp -I $(CONWAY_INC_DIR) -o $(BUILD_DIR)/cell.o