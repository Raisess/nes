CXX = g++

BUILD_DIR = ./build

SOURCE_DIR = ./src
COMPUTER_NAMESPACE_DIR = $(SOURCE_DIR)/Computer
FILES = $(COMPUTER_NAMESPACE_DIR)/Cpu.cpp \
				$(COMPUTER_NAMESPACE_DIR)/Bus.cpp \
				$(COMPUTER_NAMESPACE_DIR)/Ram.cpp

build:
	mkdir -p $(BUILD_DIR)
	$(CXX) $(FILES) $(SOURCE_DIR)/main.cpp -o $(BUILD_DIR)/main

clean:
	rm -r $(BUILD_DIR)
