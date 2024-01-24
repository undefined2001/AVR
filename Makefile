BUILD_DIR = build
CPU := atmega328p
F_CPU := 16000000UL
OPT := -Os
FIRMWARE := firmware

# List of source files
SRCS := $(shell find . -name "*.cpp")

# Create a list of object files
OBJS := $(addprefix $(BUILD_DIR)/,$(notdir $(SRCS:.cpp=.o)))

# Compiler config
CXX = avr-g++
OBJCOPY = avr-objcopy
OBJDUMP = avr-objdump
SIZE = avr-size

# Compiler flags
CPPFLAGS = $(OPT) -DF_CPU=$(F_CPU) -mmcu=$(CPU)

$(BUILD_DIR)/$(FIRMWARE).hex: $(BUILD_DIR)/$(FIRMWARE).elf
	$(OBJCOPY) -O ihex -R .eeprom $< $@
	@$(SIZE) $(BUILD_DIR)/$(FIRMWARE).hex

$(BUILD_DIR)/%.o: %.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CPPFLAGS) -c -o $@ $<

$(BUILD_DIR)/$(FIRMWARE).elf: $(OBJS)
	$(CXX) $(CPPFLAGS) -o $@ $^

flash: $(BUILD_DIR)/$(FIRMWARE).hex
	avrdude -F -V -c arduino -p ATMEGA328P -P /dev/ttyUSB0 -b 115200 -U flash:w:$<

clean:
	rm -rf $(BUILD_DIR)

test:
	echo $(SRCS)
