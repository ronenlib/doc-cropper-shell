BUILD_DIR = build

TARGET= doc-cropper

CXX = g++
CXXFLAGS = -c -Werror

LIBS = -lopencv_core -lopencv_imgcodecs -lopencv_highgui -lopencv_imgproc
INCLUDE_PATH = -I/usr/include/opencv4

SOURCES= $(wildcard src/*.cpp src/*/*.cpp)
OBJECTS= $(addprefix $(BUILD_DIR)/,$(notdir $(SOURCES:.cpp=.o)))
VPATH= $(dir $(wildcard src/ src/*/))

all: pre-build $(TARGET)

.PHONY: pre-build
pre-build:
	mkdir -p $(BUILD_DIR)
	rm -f $(BUILD_DIR)/$(TARGET)

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) $(INCLUDE_PATH) $(LIBS) -o $(BUILD_DIR)/$@

$(BUILD_DIR)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE_PATH) $< -o $@
