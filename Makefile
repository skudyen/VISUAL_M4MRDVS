SRCS            = src/main.cpp
INC             = include CameraSDK/linux/SDK/include
LDFLAGS         = -LCameraSDK/linux/SDK/lib/linux_x64 -lLxCameraApi -lLxDataProcess

CXX             = g++
CXXFLAGS        = -Wall -Wextra -std=c++17 $(addprefix -I,$(INC))
LDFLAGS         =

SRC_DIR         = src
BUILD_DIR       = build
BIN_DIR         = bin

TARGET          = $(BIN_DIR)/myprogram

OBJS            = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))
DEPS            = $(OBJS:.o=.d)

MKDIR           = mkdir -p
RM              = rm -f
RMDIR           = rm -rf

all: $(TARGET)

$(TARGET): $(OBJS) | $(BIN_DIR)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)
	@echo "Build complete -> $@"

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

$(BUILD_DIR):
	@ $(MKDIR) $(BUILD_DIR)

$(BIN_DIR):
	@ $(MKDIR) $(BIN_DIR)

-include $(DEPS)

run: all
	LD_LIBRARY_PATH=$(LIB_DIR):$$LD_LIBRARY_PATH ./$(TARGET)

#run: all
#	./$(TARGET)

clean:
	@ $(RMDIR) $(BUILD_DIR)

fclean: clean
	@ $(RMDIR) $(BIN_DIR)

re: fclean all

.PHONY: all run clean fclean re