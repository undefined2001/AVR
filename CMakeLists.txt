cmake_minimum_required(VERSION 3.28.1)

include(avr-gcc.cmake)

project(blink)

# Create an executable
add_executable(${PROJECT_NAME} ${SRCS}/main.cpp)

# Compiler options and definitions
target_compile_definitions(${PROJECT_NAME} PRIVATE
  F_CPU=${F_CPU}
  __AVR_ATmega328P__
)
target_compile_options(${PROJECT_NAME} PRIVATE ${C_FLAGS})

# Include directories
include_directories("/usr/avr/include")
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Inc)

# Set target properties
set_target_properties(${PROJECT_NAME} PROPERTIES
  SUFFIX ".elf"
  OUTPUT_NAME "${PROJECT_NAME}"
)

# Generate hex file
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
  COMMAND ${CMAKE_OBJCOPY} -O ihex -R .eeprom ${PROJECT_NAME}.elf ${PROJECT_NAME}.hex
  COMMAND avrdude -F -V -c arduino -p ATMEGA328P -P ${PORT} -b 115200 -U flash:w:${PROJECT_NAME}.hex
)
