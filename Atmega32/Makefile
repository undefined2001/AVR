BUILD_DIR = build
CPU := atmega32
F_CPU := 16000000UL
OPT := -Os
FIRMWARE := firmware
SRC_DIR := ./src
INC_DIRS := ./inc

# List of source files
SRCS := $(shell find $(SRC_DIR) -name "*.cpp")
INC_DIRS := $(addprefix -I, $(INC_DIRS))

# Create a list of object files
OBJS := $(addprefix $(BUILD_DIR)/,$(notdir $(SRCS:.cpp=.o)))

# Compiler config
CXX = avr-g++
OBJCOPY = avr-objcopy
OBJDUMP = avr-objdump
SIZE = avr-size

# Compiler flags
CPPFLAGS = $(OPT) -DF_CPU=$(F_CPU) -mmcu=$(CPU) $(INC_DIRS)
CPPFLAGS += -fno-tree-loop-distribution -fno-rtti -ffunction-sections
CPPFLAGS += -fdata-sections -Werror -Wall 

$(BUILD_DIR)/$(FIRMWARE).hex: $(BUILD_DIR)/$(FIRMWARE).elf
	@$(OBJCOPY) -O ihex -R .eeprom $< $@
	@echo "   ------------------------Size------------------------"
	@$(SIZE) $(BUILD_DIR)/$(FIRMWARE).hex

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	@$(CXX) -c $(CPPFLAGS) -o $@ $<
	@echo "BUilding " $<

$(BUILD_DIR)/$(FIRMWARE).elf: $(OBJS)
	@echo "Generating Execultable"
	@$(CXX) $(CPPFLAGS)  -o $@ $^ -Wl,-Map=$(BUILD_DIR)/blink.map -Wl,--gc-sections
flash: $(BUILD_DIR)/$(FIRMWARE).hex
	avrdude -cstk500v1 -p$(CPU) -P /dev/ttyUSB0 -b19200 -U flash:w:$<

clean:
	rm -rf $(BUILD_DIR)

test:
	echo $(SRCS)
	echo $(OBJS)
