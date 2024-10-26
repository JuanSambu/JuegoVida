################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../pruebas/Input.c 

C_DEPS += \
./pruebas/Input.d 

OBJS += \
./pruebas/Input.o 


# Each subdirectory must supply rules for building sources it contributes
pruebas/%.o: ../pruebas/%.c pruebas/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-pruebas

clean-pruebas:
	-$(RM) ./pruebas/Input.d ./pruebas/Input.o

.PHONY: clean-pruebas

