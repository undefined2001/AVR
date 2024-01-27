# Set compiler options
set(CMAKE_C_COMPILER avr-gcc)
set(CMAKE_CXX_COMPILER avr-g++)
set(CMAKE_OBJCOPY avr-objcopy)
set(CMAKE_OBJDUMP avr-objcopy)

# Set MCU flags
set(MCU atmega328p)
set(F_CPU 16000000UL)
set(C_FLAGS "-mmcu=${MCU}" "-Os" "-Wall")

# Source files
set(SRCS ${CMAKE_SOURCE_DIR}/Src)

#usb port for the flash
set(PORT "/dev/ttyUSB0")