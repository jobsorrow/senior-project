###########################################################################
## Makefile generated for component 'datalogger_target'. 
## 
## Makefile     : datalogger_target.mk
## Generated on : Sun Feb 13 14:57:01 2022
## Final product: $(RELATIVE_PATH_TO_ANCHOR)/datalogger_target.out
## Product type : executable
## 
###########################################################################

###########################################################################
## MACROS
###########################################################################

# Macro Descriptions:
# PRODUCT_NAME            Name of the system to build
# MAKEFILE                Name of this makefile

PRODUCT_NAME              = datalogger_target
MAKEFILE                  = datalogger_target.mk
MATLAB_ROOT               = C:/PROGRA~1/MATLAB/R2021a
MATLAB_BIN                = C:/PROGRA~1/MATLAB/R2021a/bin
MATLAB_ARCH_BIN           = $(MATLAB_BIN)/win64
START_DIR                 = C:/Users/61301765/SENIOR~1/SOURCE~1/Main
SOLVER                    = 
SOLVER_OBJ                = 
CLASSIC_INTERFACE         = 0
TGT_FCN_LIB               = ISO_C
MODEL_HAS_DYNAMICALLY_LOADED_SFCNS = 0
RELATIVE_PATH_TO_ANCHOR   = ..
C_STANDARD_OPTS           = 
CPP_STANDARD_OPTS         = 

###########################################################################
## TOOLCHAIN SPECIFICATIONS
###########################################################################

# Toolchain Name:          Texas Instruments Code Composer Studio (C2000)
# Supported Version(s):    
# ToolchainInfo Version:   2021a
# Specification Revision:  1.0
# 
#-------------------------------------------
# Macros assumed to be defined elsewhere
#-------------------------------------------

# CCSINSTALLDIR
# CCSSCRIPTINGDIR
# TARGET_LOAD_CMD_ARGS
# TIF28XXXSYSSWDIR

#-----------
# MACROS
#-----------

TARGET_SCRIPTINGTOOLS_INSTALLDIR = $(CCSSCRIPTINGDIR)
TI_C2000_SHARED_DIR              = $(TARGET_PKG_INSTALLDIR)/../../../shared/supportpackages/tic2000
TI_TOOLS                         = $(CCSINSTALLDIR)/bin
TI_INCLUDE                       = $(CCSINSTALLDIR)/include
TI_LIB                           = $(CCSINSTALLDIR)/lib
F28_HEADERS                      = $(TIF28XXXSYSSWDIR)/~SupportFiles/DSP280x_headers
CCOUTPUTFLAG                     = --output_file=
LDOUTPUTFLAG                     = --output_file=
EXE_FILE_EXT                     = $(PROGRAM_FILE_EXT)
PRODUCT_HEX                      = $(RELATIVE_PATH_TO_ANCHOR)/$(PRODUCT_NAME).hex
PRODUCT_DWO                      = $(RELATIVE_PATH_TO_ANCHOR)/$(PRODUCT_NAME).dwo
PRODUCT_ELF                      = $(RELATIVE_PATH_TO_ANCHOR)/$(PRODUCT_NAME).elf
DOWN_EXE_JS                      = $(TARGET_PKG_INSTALLDIR)/tic2000/CCS_Config/runProgram_generic.js
CCS_CONFIG                       = $(TARGET_PKG_INSTALLDIR)/tic2000/CCS_Config/f28x_generic.ccxml
SHELL                            = %SystemRoot%/system32/cmd.exe

TOOLCHAIN_SRCS = 
TOOLCHAIN_INCS = 
TOOLCHAIN_LIBS = 

#------------------------
# BUILD TOOL COMMANDS
#------------------------

# Assembler: C2000 Assembler
AS_PATH = $(TI_TOOLS)
AS = "$(AS_PATH)/cl2000"

# C Compiler: C2000 C Compiler
CC_PATH = $(TI_TOOLS)
CC = "$(CC_PATH)/cl2000"

# Linker: C2000 Linker
LD_PATH = $(TI_TOOLS)
LD = "$(LD_PATH)/cl2000"

# C++ Compiler: C2000 C++ Compiler
CPP_PATH = $(TI_TOOLS)
CPP = "$(CPP_PATH)/cl2000"

# C++ Linker: C2000 C++ Linker
CPP_LD_PATH = $(TI_TOOLS)
CPP_LD = "$(CPP_LD_PATH)/cl2000"

# Archiver: C2000 Archiver
AR_PATH = $(TI_TOOLS)
AR = "$(AR_PATH)/ar2000"

# MEX Tool: MEX Tool
MEX_PATH = $(MATLAB_ARCH_BIN)
MEX = "$(MEX_PATH)/mex"

# Hex Converter: Hex Converter

# DWO Converter: DWO Converter

# Download: Download
DOWNLOAD_PATH = $(TARGET_SCRIPTINGTOOLS_INSTALLDIR)/bin
DOWNLOAD = "$(DOWNLOAD_PATH)/dss.bat"

# Execute: Execute
EXECUTE = $(PRODUCT)

# Builder: GMAKE Utility
MAKE_PATH = %MATLAB%\bin\win64
MAKE = "$(MAKE_PATH)/gmake"


#-------------------------
# Directives/Utilities
#-------------------------

ASDEBUG             = -g
AS_OUTPUT_FLAG      = --output_file=
CDEBUG              = -g
C_OUTPUT_FLAG       = --output_file=
LDDEBUG             =
OUTPUT_FLAG         = --output_file=
CPPDEBUG            = -g
CPP_OUTPUT_FLAG     = --output_file=
CPPLDDEBUG          =
OUTPUT_FLAG         = --output_file=
ARDEBUG             =
STATICLIB_OUTPUT_FLAG =
MEX_DEBUG           = -g
RM                  = @del /F
ECHO                = @echo
MV                  = @move
RUN                 =

#----------------------------------------
# "Faster Builds" Build Configuration
#----------------------------------------

ARFLAGS              = -r
ASFLAGS              = --abi=coffabi \
                       -s \
                       -v28 \
                       -ml \
                       $(ASFLAGS_ADDITIONAL)
CFLAGS               = --abi=coffabi \
                       --compile_only \
                       --preproc_dependency="$(@:%.obj=%.dep)" --preproc_with_compile  \
                       --large_memory_model \
                       --silicon_version=28 \
                       --define="LARGE_MODEL" \
                       -I"$(F28_HEADERS)" \
                       -I"$(F28_HEADERS)/include" \
                       -I"$(TI_INCLUDE)"
CPPFLAGS             =
CPP_LDFLAGS          =
CPP_SHAREDLIB_LDFLAGS  =
OBJCOPYFLAGS_DWO     =  "$<"
DOWNLOAD_FLAGS       = $(TARGET_LOAD_CMD_ARGS) $(PRODUCT)
EXECUTE_FLAGS        =
OBJCOPYFLAGS_HEX     =  -i "$<" -o "$@" -order MS -romwidth 16 -q
LDFLAGS              = --abi=coffabi \
                       -z -I$(TI_LIB) \
                       --stack_size=$(STACK_SIZE) --warn_sections \
                       --heap_size=$(HEAP_SIZE) \
                       --reread_libs --rom_model \
                       --priority \
                       -m"$(PRODUCT_NAME).map"
MEX_CPPFLAGS         =
MEX_CPPLDFLAGS       =
MEX_CFLAGS           =
MEX_LDFLAGS          =
MAKE_FLAGS           = -f $(MAKEFILE)
SHAREDLIB_LDFLAGS    =



###########################################################################
## OUTPUT INFO
###########################################################################

PRODUCT = $(RELATIVE_PATH_TO_ANCHOR)/datalogger_target.out
PRODUCT_TYPE = "executable"
BUILD_TYPE = "Top-Level Standalone Executable"

###########################################################################
## INCLUDE PATHS
###########################################################################

INCLUDES_BUILDINFO = -I$(START_DIR) -I$(START_DIR)/datalogger_target_ert_rtw -I$(MATLAB_ROOT)/extern/include -I$(MATLAB_ROOT)/simulink/include -I$(MATLAB_ROOT)/rtw/c/src -I$(MATLAB_ROOT)/rtw/c/src/ext_mode/common -I$(MATLAB_ROOT)/rtw/c/ert -IC:/PROGRA~3/MATLAB/SUPPOR~1/R2021a/toolbox/target/SUPPOR~1/tic2000/inc -I$(MATLAB_ROOT)/toolbox/shared/can/src/scanutil -IC:/PROGRA~3/MATLAB/SUPPOR~1/R2021a/toolbox/target/SUPPOR~1/tic2000/src -IC:/PROGRA~3/MATLAB/SUPPOR~1/R2021a/toolbox/shared/SUPPOR~1/tic2000/src -IC:/PROGRA~3/MATLAB/SUPPOR~1/R2021a/toolbox/shared/SUPPOR~1/tic2000/inc -IC:/ti/c2000/C2000W~1/DEVICE~1/f28004x/common/include -IC:/ti/c2000/C2000W~1/LIBRAR~1/CALIBR~1/hrpwm/f28004x/include -IC:/ti/c2000/C2000W~1/DRIVER~1/f28004x/DRIVER~1 -IC:/ti/c2000/C2000W~1/DRIVER~1/f28004x/DRIVER~1/inc -IC:/ti/c2000/C2000W~1/DEVICE~1/f28004x/headers/include -IC:/ti/c2000/C2000W~1/DEVICE~1/f28004x/common -IC:/PROGRA~3/MATLAB/SUPPOR~1/R2021a/toolbox/target/shared/EXTERN~1/include -I$(MATLAB_ROOT)/toolbox/rtw/targets/common/can/blocks/tlc_c

INCLUDES = $(INCLUDES_BUILDINFO)

###########################################################################
## DEFINES
###########################################################################

DEFINES_ = -D__MW_TARGET_USE_HARDWARE_RESOURCES_H__
DEFINES_BUILD_ARGS = -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DTERMFCN=1 -DONESTEPFCN=1 -DMAT_FILE=0 -DMULTI_INSTANCE_CODE=0 -DINTEGER_CODE=0 -DMT=1
DEFINES_CUSTOM = 
DEFINES_OPTS = -DTID01EQ=0
DEFINES_SKIPFORSIL = -DDAEMON_MODE=1 -DXCP_CUSTOM_PLATFORM -DEXTMODE_DISABLE_ARGS_PROCESSING=1 -DMW_PIL_SCIFIFOLEN=16 -DCPU1 -DF2837X_REG_FORMAT -DMW_F28004X -DSTACK_SIZE=1024 -DRT -DF280049C -DBOOT_FROM_FLASH=1
DEFINES_STANDARD = -DMODEL=datalogger_target -DNUMST=2 -DNCSTATES=0 -DHAVESTDIO -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0

DEFINES = $(DEFINES_) $(DEFINES_BUILD_ARGS) $(DEFINES_CUSTOM) $(DEFINES_OPTS) $(DEFINES_SKIPFORSIL) $(DEFINES_STANDARD)

###########################################################################
## SOURCE FILES
###########################################################################

SRCS = $(START_DIR)/datalogger_target_ert_rtw/MW_c28xx_csl.c $(START_DIR)/datalogger_target_ert_rtw/MW_c28xx_board.c $(START_DIR)/datalogger_target_ert_rtw/MW_c28xx_xbar.c $(START_DIR)/datalogger_target_ert_rtw/DSP28xx_SciUtil.c $(START_DIR)/datalogger_target_ert_rtw/MW_c28xx_adc.c $(START_DIR)/datalogger_target_ert_rtw/MW_c28xx_pwm.c $(START_DIR)/datalogger_target_ert_rtw/datalogger_target.c $(START_DIR)/datalogger_target_ert_rtw/datalogger_target_data.c C:/ProgramData/MATLAB/SupportPackages/R2021a/toolbox/target/supportpackages/tic2000/src/c28004xBoard_Realtime_Support.c C:/ProgramData/MATLAB/SupportPackages/R2021a/toolbox/shared/supportpackages/tic2000/src/MW_c28xGlobalInterrupts.c C:/ti/c2000/C2000Ware_3_02_00_00/device_support/f28004x/common/source/f28004x_cputimers.c C:/ti/c2000/C2000Ware_3_02_00_00/device_support/f28004x/common/source/f28004x_defaultisr.c C:/ti/c2000/C2000Ware_3_02_00_00/device_support/f28004x/headers/source/f28004x_globalvariabledefs.c C:/ti/c2000/C2000Ware_3_02_00_00/device_support/f28004x/common/source/f28004x_piectrl.c C:/ti/c2000/C2000Ware_3_02_00_00/device_support/f28004x/common/source/f28004x_pievect.c C:/ti/c2000/C2000Ware_3_02_00_00/device_support/f28004x/common/source/f28004x_sysctrl.c C:/ti/c2000/C2000Ware_3_02_00_00/device_support/f28004x/common/source/f28004x_usdelay.asm C:/ti/c2000/C2000Ware_3_02_00_00/device_support/f28004x/common/source/f28004x_codestartbranch.asm C:/ti/c2000/C2000Ware_3_02_00_00/device_support/f28004x/common/source/f28004x_gpio.c C:/ti/c2000/C2000Ware_3_02_00_00/device_support/f28004x/common/source/f28004x_adc.c C:/ti/c2000/C2000Ware_3_02_00_00/driverlib/f28004x/driverlib/sysctl.c C:/ti/c2000/C2000Ware_3_02_00_00/driverlib/f28004x/driverlib/dma.c C:/ProgramData/MATLAB/SupportPackages/R2021a/toolbox/shared/supportpackages/tic2000/src/MW_c28xGPIO.c C:/ProgramData/MATLAB/SupportPackages/R2021a/toolbox/target/supportpackages/tic2000/src/profiler_Support.c C:/ProgramData/MATLAB/SupportPackages/R2021a/toolbox/target/supportpackages/tic2000/src/c28004xSchedulerTimer0.c

MAIN_SRC = $(START_DIR)/datalogger_target_ert_rtw/ert_main.c

ALL_SRCS = $(SRCS) $(MAIN_SRC)

###########################################################################
## OBJECTS
###########################################################################

OBJS = MW_c28xx_csl.obj MW_c28xx_board.obj MW_c28xx_xbar.obj DSP28xx_SciUtil.obj MW_c28xx_adc.obj MW_c28xx_pwm.obj datalogger_target.obj datalogger_target_data.obj c28004xBoard_Realtime_Support.obj MW_c28xGlobalInterrupts.obj f28004x_cputimers.obj f28004x_defaultisr.obj f28004x_globalvariabledefs.obj f28004x_piectrl.obj f28004x_pievect.obj f28004x_sysctrl.obj f28004x_usdelay.obj f28004x_codestartbranch.obj f28004x_gpio.obj f28004x_adc.obj sysctl.obj dma.obj MW_c28xGPIO.obj profiler_Support.obj c28004xSchedulerTimer0.obj

MAIN_OBJ = ert_main.obj

ALL_OBJS = $(OBJS) $(MAIN_OBJ)

###########################################################################
## PREBUILT OBJECT FILES
###########################################################################

PREBUILT_OBJS = 

###########################################################################
## LIBRARIES
###########################################################################

LIBS = C:/ti/c2000/C2000Ware_3_02_00_00/libraries/math/IQmath/c28/lib/IQmath_fpu32.lib C:/ProgramData/MATLAB/SupportPackages/R2021a/toolbox/target/supportpackages/tic2000/src/c28004xPeripherals.cmd C:/ProgramData/MATLAB/SupportPackages/R2021a/toolbox/target/supportpackages/tic2000/src/c280049M.cmd

###########################################################################
## SYSTEM LIBRARIES
###########################################################################

SYSTEM_LIBS = 

###########################################################################
## ADDITIONAL TOOLCHAIN FLAGS
###########################################################################

#---------------
# C Compiler
#---------------

CFLAGS_SKIPFORSIL = -v28 --float_support=fpu32 -ml -DF280049C -DBOOT_FROM_FLASH=1 --tmu_support=tmu0 --fp_mode=relaxed
CFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CFLAGS += $(CFLAGS_SKIPFORSIL) $(CFLAGS_BASIC)

#-----------------
# C++ Compiler
#-----------------

CPPFLAGS_SKIPFORSIL = -v28 --float_support=fpu32 -ml -DF280049C -DBOOT_FROM_FLASH=1 --tmu_support=tmu0 --fp_mode=relaxed
CPPFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CPPFLAGS += $(CPPFLAGS_SKIPFORSIL) $(CPPFLAGS_BASIC)

#---------------
# C++ Linker
#---------------

CPP_LDFLAGS_SKIPFORSIL = -l"rts2800_fpu32.lib" --define F280049C --define BOOT_FROM_FLASH=1 --define BOOT_USING_BL=0

CPP_LDFLAGS += $(CPP_LDFLAGS_SKIPFORSIL)

#------------------------------
# C++ Shared Library Linker
#------------------------------

CPP_SHAREDLIB_LDFLAGS_SKIPFORSIL = -l"rts2800_fpu32.lib" --define F280049C --define BOOT_FROM_FLASH=1 --define BOOT_USING_BL=0

CPP_SHAREDLIB_LDFLAGS += $(CPP_SHAREDLIB_LDFLAGS_SKIPFORSIL)

#-----------
# Linker
#-----------

LDFLAGS_SKIPFORSIL = -l"rts2800_fpu32.lib" --define F280049C --define BOOT_FROM_FLASH=1 --define BOOT_USING_BL=0

LDFLAGS += $(LDFLAGS_SKIPFORSIL)

#--------------------------
# Shared Library Linker
#--------------------------

SHAREDLIB_LDFLAGS_SKIPFORSIL = -l"rts2800_fpu32.lib" --define F280049C --define BOOT_FROM_FLASH=1 --define BOOT_USING_BL=0

SHAREDLIB_LDFLAGS += $(SHAREDLIB_LDFLAGS_SKIPFORSIL)

###########################################################################
## INLINED COMMANDS
###########################################################################


#--------------------------
# ELF to hex converter
#--------------------------
all :

ifeq ($(PRODUCT_TYPE),"executable")
postbuild : $(PRODUCT_HEX)

$(PRODUCT_HEX): $(PRODUCT)
	@echo "### Invoking postbuild tool "Hex Converter" on "$<"..."
	$(CCSINSTALLDIR)/bin/hex2000 $(OBJCOPYFLAGS_HEX)
	@echo "### Done Invoking postbuild tool "Hex Converter" ..."

postbuild : $(PRODUCT_DWO)

$(PRODUCT_DWO): $(PRODUCT)
	@echo "### Invoking postbuild tool "DWO Converter" on "$<"..."
	$(TI_C2000_SHARED_DIR)/tools/bin/win64/extractDWARF.exe $(OBJCOPYFLAGS_DWO)
	@echo "### Done Invoking postbuild tool "DWO Converter" ..."

endif

#--------------------------
# Dependency based build
#--------------------------
ifeq ($(DEPRULES),1) 
ALL_DEPS:=$(patsubst %.obj,%.dep,$(ALL_OBJS))
all:
else
ALL_DEPS:=
endif




-include codertarget_assembly_flags.mk
-include ../codertarget_assembly_flags.mk
-include ../../codertarget_assembly_flags.mk
-include $(ALL_DEPS)


###########################################################################
## PHONY TARGETS
###########################################################################

.PHONY : all build buildobj clean info prebuild postbuild download execute


all : build postbuild
	@echo "### Successfully generated all binary outputs."


build : prebuild $(PRODUCT)


buildobj : prebuild $(OBJS) $(PREBUILT_OBJS) $(LIBS)
	@echo "### Successfully generated all binary outputs."


prebuild : 


postbuild : $(PRODUCT)


download : postbuild
	@echo "### Invoking postbuild tool "Download" ..."
	$(DOWNLOAD) $(DOWNLOAD_FLAGS)
	@echo "### Done invoking postbuild tool."


execute : download
	@echo "### Invoking postbuild tool "Execute" ..."
	$(EXECUTE) $(EXECUTE_FLAGS)
	@echo "### Done invoking postbuild tool."


###########################################################################
## FINAL TARGET
###########################################################################

#-------------------------------------------
# Create a standalone executable            
#-------------------------------------------

$(PRODUCT) : $(OBJS) $(PREBUILT_OBJS) $(LIBS) $(MAIN_OBJ)
	@echo "### Creating standalone executable "$(PRODUCT)" ..."
	$(LD) $(LDFLAGS) --output_file=$(PRODUCT) $(OBJS) $(MAIN_OBJ) $(LIBS) $(SYSTEM_LIBS) $(TOOLCHAIN_LIBS)
	@echo "### Created: $(PRODUCT)"


###########################################################################
## INTERMEDIATE TARGETS
###########################################################################

#---------------------
# SOURCE-TO-OBJECT
#---------------------

%.obj : %.cla
	$(CC) $(CFLAGS) --output_file="$@" "$<"


%.obj : %.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


%.obj : %.asm
	$(AS) $(ASFLAGS) --output_file="$@" "$<"


%.obj : %.cpp
	$(CPP) $(CPPFLAGS) --output_file="$@" "$<"


%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.cla
	$(CC) $(CFLAGS) --output_file="$@" "$<"


%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.asm
	$(AS) $(ASFLAGS) --output_file="$@" "$<"


%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.cpp
	$(CPP) $(CPPFLAGS) --output_file="$@" "$<"


%.obj : $(START_DIR)/%.cla
	$(CC) $(CFLAGS) --output_file="$@" "$<"


%.obj : $(START_DIR)/%.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


%.obj : $(START_DIR)/%.asm
	$(AS) $(ASFLAGS) --output_file="$@" "$<"


%.obj : $(START_DIR)/%.cpp
	$(CPP) $(CPPFLAGS) --output_file="$@" "$<"


%.obj : $(START_DIR)/datalogger_target_ert_rtw/%.cla
	$(CC) $(CFLAGS) --output_file="$@" "$<"


%.obj : $(START_DIR)/datalogger_target_ert_rtw/%.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


%.obj : $(START_DIR)/datalogger_target_ert_rtw/%.asm
	$(AS) $(ASFLAGS) --output_file="$@" "$<"


%.obj : $(START_DIR)/datalogger_target_ert_rtw/%.cpp
	$(CPP) $(CPPFLAGS) --output_file="$@" "$<"


%.obj : $(MATLAB_ROOT)/rtw/c/src/%.cla
	$(CC) $(CFLAGS) --output_file="$@" "$<"


%.obj : $(MATLAB_ROOT)/rtw/c/src/%.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


%.obj : $(MATLAB_ROOT)/rtw/c/src/%.asm
	$(AS) $(ASFLAGS) --output_file="$@" "$<"


%.obj : $(MATLAB_ROOT)/rtw/c/src/%.cpp
	$(CPP) $(CPPFLAGS) --output_file="$@" "$<"


%.obj : $(MATLAB_ROOT)/simulink/src/%.cla
	$(CC) $(CFLAGS) --output_file="$@" "$<"


%.obj : $(MATLAB_ROOT)/simulink/src/%.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


%.obj : $(MATLAB_ROOT)/simulink/src/%.asm
	$(AS) $(ASFLAGS) --output_file="$@" "$<"


%.obj : $(MATLAB_ROOT)/simulink/src/%.cpp
	$(CPP) $(CPPFLAGS) --output_file="$@" "$<"


MW_c28xx_csl.obj : $(START_DIR)/datalogger_target_ert_rtw/MW_c28xx_csl.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


MW_c28xx_board.obj : $(START_DIR)/datalogger_target_ert_rtw/MW_c28xx_board.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


MW_c28xx_xbar.obj : $(START_DIR)/datalogger_target_ert_rtw/MW_c28xx_xbar.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


DSP28xx_SciUtil.obj : $(START_DIR)/datalogger_target_ert_rtw/DSP28xx_SciUtil.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


MW_c28xx_adc.obj : $(START_DIR)/datalogger_target_ert_rtw/MW_c28xx_adc.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


MW_c28xx_pwm.obj : $(START_DIR)/datalogger_target_ert_rtw/MW_c28xx_pwm.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


datalogger_target.obj : $(START_DIR)/datalogger_target_ert_rtw/datalogger_target.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


datalogger_target_data.obj : $(START_DIR)/datalogger_target_ert_rtw/datalogger_target_data.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


ert_main.obj : $(START_DIR)/datalogger_target_ert_rtw/ert_main.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


c28004xBoard_Realtime_Support.obj : C:/ProgramData/MATLAB/SupportPackages/R2021a/toolbox/target/supportpackages/tic2000/src/c28004xBoard_Realtime_Support.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


MW_c28xGlobalInterrupts.obj : C:/ProgramData/MATLAB/SupportPackages/R2021a/toolbox/shared/supportpackages/tic2000/src/MW_c28xGlobalInterrupts.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


f28004x_cputimers.obj : C:/ti/c2000/C2000Ware_3_02_00_00/device_support/f28004x/common/source/f28004x_cputimers.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


f28004x_defaultisr.obj : C:/ti/c2000/C2000Ware_3_02_00_00/device_support/f28004x/common/source/f28004x_defaultisr.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


f28004x_globalvariabledefs.obj : C:/ti/c2000/C2000Ware_3_02_00_00/device_support/f28004x/headers/source/f28004x_globalvariabledefs.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


f28004x_piectrl.obj : C:/ti/c2000/C2000Ware_3_02_00_00/device_support/f28004x/common/source/f28004x_piectrl.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


f28004x_pievect.obj : C:/ti/c2000/C2000Ware_3_02_00_00/device_support/f28004x/common/source/f28004x_pievect.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


f28004x_sysctrl.obj : C:/ti/c2000/C2000Ware_3_02_00_00/device_support/f28004x/common/source/f28004x_sysctrl.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


f28004x_usdelay.obj : C:/ti/c2000/C2000Ware_3_02_00_00/device_support/f28004x/common/source/f28004x_usdelay.asm
	$(AS) $(ASFLAGS) --output_file="$@" "$<"


f28004x_codestartbranch.obj : C:/ti/c2000/C2000Ware_3_02_00_00/device_support/f28004x/common/source/f28004x_codestartbranch.asm
	$(AS) $(ASFLAGS) --output_file="$@" "$<"


f28004x_gpio.obj : C:/ti/c2000/C2000Ware_3_02_00_00/device_support/f28004x/common/source/f28004x_gpio.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


f28004x_adc.obj : C:/ti/c2000/C2000Ware_3_02_00_00/device_support/f28004x/common/source/f28004x_adc.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


sysctl.obj : C:/ti/c2000/C2000Ware_3_02_00_00/driverlib/f28004x/driverlib/sysctl.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


dma.obj : C:/ti/c2000/C2000Ware_3_02_00_00/driverlib/f28004x/driverlib/dma.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


MW_c28xGPIO.obj : C:/ProgramData/MATLAB/SupportPackages/R2021a/toolbox/shared/supportpackages/tic2000/src/MW_c28xGPIO.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


profiler_Support.obj : C:/ProgramData/MATLAB/SupportPackages/R2021a/toolbox/target/supportpackages/tic2000/src/profiler_Support.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


c28004xSchedulerTimer0.obj : C:/ProgramData/MATLAB/SupportPackages/R2021a/toolbox/target/supportpackages/tic2000/src/c28004xSchedulerTimer0.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


###########################################################################
## DEPENDENCIES
###########################################################################

$(ALL_OBJS) : rtw_proj.tmw $(MAKEFILE)


###########################################################################
## MISCELLANEOUS TARGETS
###########################################################################

info : 
	@echo "### PRODUCT = $(PRODUCT)"
	@echo "### PRODUCT_TYPE = $(PRODUCT_TYPE)"
	@echo "### BUILD_TYPE = $(BUILD_TYPE)"
	@echo "### INCLUDES = $(INCLUDES)"
	@echo "### DEFINES = $(DEFINES)"
	@echo "### ALL_SRCS = $(ALL_SRCS)"
	@echo "### ALL_OBJS = $(ALL_OBJS)"
	@echo "### LIBS = $(LIBS)"
	@echo "### MODELREF_LIBS = $(MODELREF_LIBS)"
	@echo "### SYSTEM_LIBS = $(SYSTEM_LIBS)"
	@echo "### TOOLCHAIN_LIBS = $(TOOLCHAIN_LIBS)"
	@echo "### ASFLAGS = $(ASFLAGS)"
	@echo "### CFLAGS = $(CFLAGS)"
	@echo "### LDFLAGS = $(LDFLAGS)"
	@echo "### SHAREDLIB_LDFLAGS = $(SHAREDLIB_LDFLAGS)"
	@echo "### CPPFLAGS = $(CPPFLAGS)"
	@echo "### CPP_LDFLAGS = $(CPP_LDFLAGS)"
	@echo "### CPP_SHAREDLIB_LDFLAGS = $(CPP_SHAREDLIB_LDFLAGS)"
	@echo "### ARFLAGS = $(ARFLAGS)"
	@echo "### MEX_CFLAGS = $(MEX_CFLAGS)"
	@echo "### MEX_CPPFLAGS = $(MEX_CPPFLAGS)"
	@echo "### MEX_LDFLAGS = $(MEX_LDFLAGS)"
	@echo "### MEX_CPPLDFLAGS = $(MEX_CPPLDFLAGS)"
	@echo "### OBJCOPYFLAGS_HEX = $(OBJCOPYFLAGS_HEX)"
	@echo "### OBJCOPYFLAGS_DWO = $(OBJCOPYFLAGS_DWO)"
	@echo "### DOWNLOAD_FLAGS = $(DOWNLOAD_FLAGS)"
	@echo "### EXECUTE_FLAGS = $(EXECUTE_FLAGS)"
	@echo "### MAKE_FLAGS = $(MAKE_FLAGS)"


clean : 
	$(ECHO) "### Deleting all derived files..."
	$(RM) $(subst /,\,$(PRODUCT))
	$(RM) $(subst /,\,$(ALL_OBJS))
	$(RM) *Object
	$(ECHO) "### Deleted all derived files."


