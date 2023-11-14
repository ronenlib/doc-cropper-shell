BUILD_DIR = build

TARGET= doc-scanner

CXX = g++
CXXFLAGS = -c -Wall

SOURCES= $(wildcard src/*.cpp src/*/*.cpp)
OBJECTS= $(addprefix $(BUILD_DIR)/,$(notdir $(SOURCES:.cpp=.o)))
VPATH= $(dir $(wildcard src/ src/*/))

all: prepare $(TARGET)

prepare:
	mkdir -p $(BUILD_DIR)
	rm -f $(BUILD_DIR)/$(TARGET)

clean:
	rm -rf $(BUILD_DIR)

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(BUILD_DIR)/$@

$(BUILD_DIR)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@
