################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../backend.c \
../frontend.c \
../juego_vida_allegro.c 

O_SRCS += \
../backend.o \
../frontend.o \
../main.o 

C_DEPS += \
./backend.d \
./frontend.d \
./juego_vida_allegro.d 

OBJS += \
./backend.o \
./frontend.o \
./juego_vida_allegro.o 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean--2e-

clean--2e-:
	-$(RM) ./backend.d ./backend.o ./frontend.d ./frontend.o ./juego_vida_allegro.d ./juego_vida_allegro.o

.PHONY: clean--2e-
