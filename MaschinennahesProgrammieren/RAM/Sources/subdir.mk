################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/Events.c" \
"../Sources/Intro.c" \
"../Sources/UE01_strgout.c" \
"../Sources/UE03_hex.c" \
"../Sources/UE04_hexup.c" \
"../Sources/UE05_mymemcopy.c" \
"../Sources/UE06_illegal.c" \
"../Sources/UE07_trap.c" \
"../Sources/console_io.c" \
"../Sources/exceptions.c" \
"../Sources/main.c" \
"../Sources/terminal_wrapper.c" \
"../Sources/uart_support.c" \

C_SRCS += \
../Sources/Events.c \
../Sources/Intro.c \
../Sources/UE01_strgout.c \
../Sources/UE03_hex.c \
../Sources/UE04_hexup.c \
../Sources/UE05_mymemcopy.c \
../Sources/UE06_illegal.c \
../Sources/UE07_trap.c \
../Sources/console_io.c \
../Sources/exceptions.c \
../Sources/main.c \
../Sources/terminal_wrapper.c \
../Sources/uart_support.c \

OBJS += \
./Sources/Events_c.obj \
./Sources/Intro_c.obj \
./Sources/UE01_strgout_c.obj \
./Sources/UE03_hex_c.obj \
./Sources/UE04_hexup_c.obj \
./Sources/UE05_mymemcopy_c.obj \
./Sources/UE06_illegal_c.obj \
./Sources/UE07_trap_c.obj \
./Sources/console_io_c.obj \
./Sources/exceptions_c.obj \
./Sources/main_c.obj \
./Sources/terminal_wrapper_c.obj \
./Sources/uart_support_c.obj \

OBJS_QUOTED += \
"./Sources/Events_c.obj" \
"./Sources/Intro_c.obj" \
"./Sources/UE01_strgout_c.obj" \
"./Sources/UE03_hex_c.obj" \
"./Sources/UE04_hexup_c.obj" \
"./Sources/UE05_mymemcopy_c.obj" \
"./Sources/UE06_illegal_c.obj" \
"./Sources/UE07_trap_c.obj" \
"./Sources/console_io_c.obj" \
"./Sources/exceptions_c.obj" \
"./Sources/main_c.obj" \
"./Sources/terminal_wrapper_c.obj" \
"./Sources/uart_support_c.obj" \

C_DEPS += \
./Sources/Events_c.d \
./Sources/Intro_c.d \
./Sources/UE01_strgout_c.d \
./Sources/UE03_hex_c.d \
./Sources/UE04_hexup_c.d \
./Sources/UE05_mymemcopy_c.d \
./Sources/UE06_illegal_c.d \
./Sources/UE07_trap_c.d \
./Sources/console_io_c.d \
./Sources/exceptions_c.d \
./Sources/main_c.d \
./Sources/terminal_wrapper_c.d \
./Sources/uart_support_c.d \

OBJS_OS_FORMAT += \
./Sources/Events_c.obj \
./Sources/Intro_c.obj \
./Sources/UE01_strgout_c.obj \
./Sources/UE03_hex_c.obj \
./Sources/UE04_hexup_c.obj \
./Sources/UE05_mymemcopy_c.obj \
./Sources/UE06_illegal_c.obj \
./Sources/UE07_trap_c.obj \
./Sources/console_io_c.obj \
./Sources/exceptions_c.obj \
./Sources/main_c.obj \
./Sources/terminal_wrapper_c.obj \
./Sources/uart_support_c.obj \

C_DEPS_QUOTED += \
"./Sources/Events_c.d" \
"./Sources/Intro_c.d" \
"./Sources/UE01_strgout_c.d" \
"./Sources/UE03_hex_c.d" \
"./Sources/UE04_hexup_c.d" \
"./Sources/UE05_mymemcopy_c.d" \
"./Sources/UE06_illegal_c.d" \
"./Sources/UE07_trap_c.d" \
"./Sources/console_io_c.d" \
"./Sources/exceptions_c.d" \
"./Sources/main_c.d" \
"./Sources/terminal_wrapper_c.d" \
"./Sources/uart_support_c.d" \


# Each subdirectory must supply rules for building sources it contributes
Sources/Events_c.obj: ../Sources/Events.c
	@echo 'Building file: $<'
	@echo 'Executing target #1 $<'
	@echo 'Invoking: ColdFire Compiler'
	"$(CF_ToolsDirEnv)/mwccmcf" @@"Sources/Events.args" -o "Sources/Events_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/%.d: ../Sources/%.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

Sources/Intro_c.obj: ../Sources/Intro.c
	@echo 'Building file: $<'
	@echo 'Executing target #2 $<'
	@echo 'Invoking: ColdFire Compiler'
	"$(CF_ToolsDirEnv)/mwccmcf" @@"Sources/Intro.args" -o "Sources/Intro_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/UE01_strgout_c.obj: ../Sources/UE01_strgout.c
	@echo 'Building file: $<'
	@echo 'Executing target #3 $<'
	@echo 'Invoking: ColdFire Compiler'
	"$(CF_ToolsDirEnv)/mwccmcf" @@"Sources/UE01_strgout.args" -o "Sources/UE01_strgout_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/UE03_hex_c.obj: ../Sources/UE03_hex.c
	@echo 'Building file: $<'
	@echo 'Executing target #4 $<'
	@echo 'Invoking: ColdFire Compiler'
	"$(CF_ToolsDirEnv)/mwccmcf" @@"Sources/UE03_hex.args" -o "Sources/UE03_hex_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/UE04_hexup_c.obj: ../Sources/UE04_hexup.c
	@echo 'Building file: $<'
	@echo 'Executing target #5 $<'
	@echo 'Invoking: ColdFire Compiler'
	"$(CF_ToolsDirEnv)/mwccmcf" @@"Sources/UE04_hexup.args" -o "Sources/UE04_hexup_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/UE05_mymemcopy_c.obj: ../Sources/UE05_mymemcopy.c
	@echo 'Building file: $<'
	@echo 'Executing target #6 $<'
	@echo 'Invoking: ColdFire Compiler'
	"$(CF_ToolsDirEnv)/mwccmcf" @@"Sources/UE05_mymemcopy.args" -o "Sources/UE05_mymemcopy_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/UE06_illegal_c.obj: ../Sources/UE06_illegal.c
	@echo 'Building file: $<'
	@echo 'Executing target #7 $<'
	@echo 'Invoking: ColdFire Compiler'
	"$(CF_ToolsDirEnv)/mwccmcf" @@"Sources/UE06_illegal.args" -o "Sources/UE06_illegal_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/UE07_trap_c.obj: ../Sources/UE07_trap.c
	@echo 'Building file: $<'
	@echo 'Executing target #8 $<'
	@echo 'Invoking: ColdFire Compiler'
	"$(CF_ToolsDirEnv)/mwccmcf" @@"Sources/UE07_trap.args" -o "Sources/UE07_trap_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/console_io_c.obj: ../Sources/console_io.c
	@echo 'Building file: $<'
	@echo 'Executing target #9 $<'
	@echo 'Invoking: ColdFire Compiler'
	"$(CF_ToolsDirEnv)/mwccmcf" @@"Sources/console_io.args" -o "Sources/console_io_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/exceptions_c.obj: ../Sources/exceptions.c
	@echo 'Building file: $<'
	@echo 'Executing target #10 $<'
	@echo 'Invoking: ColdFire Compiler'
	"$(CF_ToolsDirEnv)/mwccmcf" @@"Sources/exceptions.args" -o "Sources/exceptions_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/main_c.obj: ../Sources/main.c
	@echo 'Building file: $<'
	@echo 'Executing target #11 $<'
	@echo 'Invoking: ColdFire Compiler'
	"$(CF_ToolsDirEnv)/mwccmcf" @@"Sources/main.args" -o "Sources/main_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/terminal_wrapper_c.obj: ../Sources/terminal_wrapper.c
	@echo 'Building file: $<'
	@echo 'Executing target #12 $<'
	@echo 'Invoking: ColdFire Compiler'
	"$(CF_ToolsDirEnv)/mwccmcf" @@"Sources/terminal_wrapper.args" -o "Sources/terminal_wrapper_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/uart_support_c.obj: ../Sources/uart_support.c
	@echo 'Building file: $<'
	@echo 'Executing target #13 $<'
	@echo 'Invoking: ColdFire Compiler'
	"$(CF_ToolsDirEnv)/mwccmcf" @@"Sources/uart_support.args" -o "Sources/uart_support_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '


