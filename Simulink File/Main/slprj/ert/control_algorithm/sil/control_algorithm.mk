###########################################################################
## Makefile generated for component 'control_algorithm'. 
## 
## Makefile     : control_algorithm.mk
## Generated on : Sun Oct 10 00:34:39 2021
## Final product: .\control_algorithm.exe
## Product type : executable
## 
###########################################################################

###########################################################################
## MACROS
###########################################################################

# Macro Descriptions:
# PRODUCT_NAME            Name of the system to build
# MAKEFILE                Name of this makefile
# MODELREF_LINK_RSPFILE   Linker command listing model reference link objects
# COMPILER_COMMAND_FILE   Compiler command listing model reference header paths
# CMD_FILE                Command file

PRODUCT_NAME              = control_algorithm
MAKEFILE                  = control_algorithm.mk
MATLAB_ROOT               = C:\PROGRA~1\MATLAB\R2021a
MATLAB_BIN                = C:\PROGRA~1\MATLAB\R2021a\bin
MATLAB_ARCH_BIN           = $(MATLAB_BIN)\win64
START_DIR                 = C:\Users\61301765\SENIOR~1\SIMULI~1\Main
SOLVER                    = 
SOLVER_OBJ                = 
CLASSIC_INTERFACE         = 0
TGT_FCN_LIB               = TI C28x
MODEL_HAS_DYNAMICALLY_LOADED_SFCNS = 0
RELATIVE_PATH_TO_ANCHOR   = ..\..\..\..
MODELREF_LINK_RSPFILE     = control_algorithm_ref.rsp
COMPILER_COMMAND_FILE     = control_algorithm_comp.rsp
CMD_FILE                  = control_algorithm.rsp
C_STANDARD_OPTS           = 
CPP_STANDARD_OPTS         = 
NODEBUG                   = 1

###########################################################################
## TOOLCHAIN SPECIFICATIONS
###########################################################################

# Toolchain Name:          Microsoft Visual C++ 2019 v16.0 | nmake (64-bit Windows)
# Supported Version(s):    16.0
# ToolchainInfo Version:   2021a
# Specification Revision:  1.0
# 
#-------------------------------------------
# Macros assumed to be defined elsewhere
#-------------------------------------------

# NODEBUG
# cvarsdll
# cvarsmt
# conlibsmt
# ldebug
# conflags
# cflags

#-----------
# MACROS
#-----------

MW_EXTERNLIB_DIR    = $(MATLAB_ROOT)\extern\lib\win64\microsoft
MW_LIB_DIR          = $(MATLAB_ROOT)\lib\win64
CPU                 = AMD64
APPVER              = 5.02
CVARSFLAG           = $(cvarsmt)
CFLAGS_ADDITIONAL   = -D_CRT_SECURE_NO_WARNINGS
CPPFLAGS_ADDITIONAL = -EHs -D_CRT_SECURE_NO_WARNINGS /wd4251
LIBS_TOOLCHAIN      = $(conlibs)

TOOLCHAIN_SRCS = 
TOOLCHAIN_INCS = 
TOOLCHAIN_LIBS = 

#------------------------
# BUILD TOOL COMMANDS
#------------------------

# C Compiler: Microsoft Visual C Compiler
CC = cl

# Linker: Microsoft Visual C Linker
LD = link

# C++ Compiler: Microsoft Visual C++ Compiler
CPP = cl

# C++ Linker: Microsoft Visual C++ Linker
CPP_LD = link

# Archiver: Microsoft Visual C/C++ Archiver
AR = lib

# MEX Tool: MEX Tool
MEX_PATH = $(MATLAB_ARCH_BIN)
MEX = "$(MEX_PATH)\mex"

# Download: Download
DOWNLOAD =

# Execute: Execute
EXECUTE = $(PRODUCT)

# Builder: NMAKE Utility
MAKE = nmake


#-------------------------
# Directives/Utilities
#-------------------------

CDEBUG              = -Zi
C_OUTPUT_FLAG       = -Fo
LDDEBUG             = /DEBUG
OUTPUT_FLAG         = -out:
CPPDEBUG            = -Zi
CPP_OUTPUT_FLAG     = -Fo
CPPLDDEBUG          = /DEBUG
OUTPUT_FLAG         = -out:
ARDEBUG             =
STATICLIB_OUTPUT_FLAG = -out:
MEX_DEBUG           = -g
RM                  = @del
ECHO                = @echo
MV                  = @ren
RUN                 = @cmd /C

#----------------------------------------
# "Faster Builds" Build Configuration
#----------------------------------------

ARFLAGS              = /nologo
CFLAGS               = $(cflags) $(CVARSFLAG) $(CFLAGS_ADDITIONAL) \
                       /Od /Oy-
CPPFLAGS             = /TP $(cflags) $(CVARSFLAG) $(CPPFLAGS_ADDITIONAL) \
                       /Od /Oy-
CPP_LDFLAGS          = $(ldebug) $(conflags) $(LIBS_TOOLCHAIN)
CPP_SHAREDLIB_LDFLAGS  = $(ldebug) $(conflags) $(LIBS_TOOLCHAIN) \
                         -dll -def:$(DEF_FILE)
DOWNLOAD_FLAGS       =
EXECUTE_FLAGS        =
LDFLAGS              = $(ldebug) $(conflags) $(LIBS_TOOLCHAIN)
MEX_CPPFLAGS         =
MEX_CPPLDFLAGS       =
MEX_CFLAGS           =
MEX_LDFLAGS          =
MAKE_FLAGS           = -f $(MAKEFILE)
SHAREDLIB_LDFLAGS    = $(ldebug) $(conflags) $(LIBS_TOOLCHAIN) \
                       -dll -def:$(DEF_FILE)



###########################################################################
## OUTPUT INFO
###########################################################################

PRODUCT = .\control_algorithm.exe
PRODUCT_TYPE = "executable"
BUILD_TYPE = "Top-Level Standalone Executable"

###########################################################################
## INCLUDE PATHS
###########################################################################

INCLUDES_BUILDINFO = 

INCLUDES = $(INCLUDES_BUILDINFO)

###########################################################################
## DEFINES
###########################################################################

DEFINES_BUILD_ARGS = -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DTERMFCN=1 -DONESTEPFCN=1 -DMAT_FILE=0 -DMULTI_INSTANCE_CODE=0 -DINTEGER_CODE=0 -DMT=0
DEFINES_CUSTOM = 
DEFINES_OPTS = -DTID01EQ=0 -DPORTABLE_WORDSIZES -DXIL_SIGNAL_HANDLER=1 -DSIL_DISABLE_SUBNORMAL_SUPPORT=1 -DCODER_ASSUMPTIONS_ENABLED=1 -DHOST_WORD_ADDRESSABLE_TESTING=1 -DRTIOSTREAM_RX_BUFFER_BYTE_SIZE=50000 -DRTIOSTREAM_TX_BUFFER_BYTE_SIZE=50000 -DMEM_UNIT_BYTES=2 -DMemUnit_T=uint16_T
DEFINES_STANDARD = -DMODEL=control_algorithm -DNUMST=1 -DNCSTATES=0 -DHAVESTDIO -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0

DEFINES = $(DEFINES_BUILD_ARGS) $(DEFINES_CUSTOM) $(DEFINES_OPTS) $(DEFINES_STANDARD)

###########################################################################
## SOURCE FILES
###########################################################################

SRCS = $(MATLAB_ROOT)\toolbox\rtw\targets\pil\c\xil_interface_lib.c $(MATLAB_ROOT)\toolbox\rtw\targets\pil\c\xil_data_stream.c $(MATLAB_ROOT)\toolbox\rtw\targets\pil\c\xil_services.c $(START_DIR)\slprj\ert\control_algorithm\sil\xil_interface.c $(MATLAB_ROOT)\toolbox\rtw\targets\pil\c\xilcomms_rtiostream.c $(MATLAB_ROOT)\toolbox\rtw\targets\pil\c\xil_rtiostream.c $(MATLAB_ROOT)\toolbox\coder\rtiostream\src\utils\rtiostream_utils.c $(MATLAB_ROOT)\toolbox\rtw\targets\pil\c\coder_assumptions_app.c $(MATLAB_ROOT)\toolbox\rtw\targets\pil\c\coder_assumptions_data_stream.c $(MATLAB_ROOT)\toolbox\rtw\targets\pil\c\coder_assumptions_rtiostream.c $(MATLAB_ROOT)\toolbox\rtw\targets\pil\c\sil_main.c $(MATLAB_ROOT)\toolbox\rtw\targets\pil\c\target_io.c $(MATLAB_ROOT)\toolbox\coder\rtiostream\src\rtiostreamtcpip\rtiostream_tcpip.c

ALL_SRCS = $(SRCS)

###########################################################################
## OBJECTS
###########################################################################

OBJS = xil_interface_lib.obj xil_data_stream.obj xil_services.obj xil_interface.obj xilcomms_rtiostream.obj xil_rtiostream.obj rtiostream_utils.obj coder_assumptions_app.obj coder_assumptions_data_stream.obj coder_assumptions_rtiostream.obj sil_main.obj target_io.obj rtiostream_tcpip.obj

ALL_OBJS = $(OBJS)

###########################################################################
## PREBUILT OBJECT FILES
###########################################################################

PREBUILT_OBJS = 

###########################################################################
## LIBRARIES
###########################################################################

MODELREF_LIBS = "C:\Users\61301765\senior-project\Simulink File\Main\slprj\ert\control_algorithm\sil\hostobj\control_algorithm_rtwlib.lib"

LIBS = $(START_DIR)\slprj\ert\_sharedutils\sil\hostobj\rtwshared.lib $(START_DIR)\slprj\ert\control_algorithm\coderassumptions\pwslib\control_algorithm_ca.lib

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

CFLAGS_BASIC = $(DEFINES) @$(COMPILER_COMMAND_FILE)

CFLAGS = $(CFLAGS) $(CFLAGS_BASIC)

#-----------------
# C++ Compiler
#-----------------

CPPFLAGS_BASIC = $(DEFINES) @$(COMPILER_COMMAND_FILE)

CPPFLAGS = $(CPPFLAGS) $(CPPFLAGS_BASIC)

###########################################################################
## INLINED COMMANDS
###########################################################################


!include $(MATLAB_ROOT)\rtw\c\tools\vcdefs.mak


###########################################################################
## PHONY TARGETS
###########################################################################

.PHONY : all build buildobj clean info prebuild download execute set_environment_variables


all : build
	@cmd /C "@echo ### Successfully generated all binary outputs."


build : set_environment_variables prebuild $(PRODUCT)


buildobj : set_environment_variables prebuild $(OBJS) $(PREBUILT_OBJS) $(LIBS)
	@cmd /C "@echo ### Successfully generated all binary outputs."


prebuild : 


download : $(PRODUCT)


execute : download
	@cmd /C "@echo ### Invoking postbuild tool "Execute" ..."
	$(EXECUTE) $(EXECUTE_FLAGS)
	@cmd /C "@echo ### Done invoking postbuild tool."


set_environment_variables : 
	@set INCLUDE=$(INCLUDES);$(INCLUDE)
	@set LIB=$(LIB)


###########################################################################
## FINAL TARGET
###########################################################################

#-------------------------------------------
# Create a standalone executable            
#-------------------------------------------

$(PRODUCT) : $(OBJS) $(PREBUILT_OBJS) $(MODELREF_LIBS) $(LIBS)
	@cmd /C "@echo ### Creating standalone executable "$(PRODUCT)" ..."
	$(LD) $(LDFLAGS) -out:$(PRODUCT) @$(CMD_FILE) @$(MODELREF_LINK_RSPFILE) $(LIBS) $(SYSTEM_LIBS) $(TOOLCHAIN_LIBS)
	@cmd /C "@echo ### Created: $(PRODUCT)"


###########################################################################
## INTERMEDIATE TARGETS
###########################################################################

#---------------------
# SOURCE-TO-OBJECT
#---------------------

.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


.cpp.obj :
	$(CPP) $(CPPFLAGS) -Fo"$@" "$<"


{$(RELATIVE_PATH_TO_ANCHOR)}.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


{$(RELATIVE_PATH_TO_ANCHOR)}.cpp.obj :
	$(CPP) $(CPPFLAGS) -Fo"$@" "$<"


{$(MATLAB_ROOT)\toolbox\rtw\targets\pil\c}.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


{$(MATLAB_ROOT)\toolbox\rtw\targets\pil\c}.cpp.obj :
	$(CPP) $(CPPFLAGS) -Fo"$@" "$<"


{$(MATLAB_ROOT)\toolbox\coder\rtiostream\src\utils}.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


{$(MATLAB_ROOT)\toolbox\coder\rtiostream\src\utils}.cpp.obj :
	$(CPP) $(CPPFLAGS) -Fo"$@" "$<"


{$(MATLAB_ROOT)\toolbox\coder\rtiostream\src\rtiostreamtcpip}.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


{$(MATLAB_ROOT)\toolbox\coder\rtiostream\src\rtiostreamtcpip}.cpp.obj :
	$(CPP) $(CPPFLAGS) -Fo"$@" "$<"


xil_interface_lib.obj : $(MATLAB_ROOT)\toolbox\rtw\targets\pil\c\xil_interface_lib.c
	$(CC) $(CFLAGS) -Fo"$@" $(MATLAB_ROOT)\toolbox\rtw\targets\pil\c\xil_interface_lib.c


xil_data_stream.obj : $(MATLAB_ROOT)\toolbox\rtw\targets\pil\c\xil_data_stream.c
	$(CC) $(CFLAGS) -Fo"$@" $(MATLAB_ROOT)\toolbox\rtw\targets\pil\c\xil_data_stream.c


xil_services.obj : $(MATLAB_ROOT)\toolbox\rtw\targets\pil\c\xil_services.c
	$(CC) $(CFLAGS) -Fo"$@" $(MATLAB_ROOT)\toolbox\rtw\targets\pil\c\xil_services.c


xil_interface.obj : $(START_DIR)\slprj\ert\control_algorithm\sil\xil_interface.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\slprj\ert\control_algorithm\sil\xil_interface.c


xilcomms_rtiostream.obj : $(MATLAB_ROOT)\toolbox\rtw\targets\pil\c\xilcomms_rtiostream.c
	$(CC) $(CFLAGS) -Fo"$@" $(MATLAB_ROOT)\toolbox\rtw\targets\pil\c\xilcomms_rtiostream.c


xil_rtiostream.obj : $(MATLAB_ROOT)\toolbox\rtw\targets\pil\c\xil_rtiostream.c
	$(CC) $(CFLAGS) -Fo"$@" $(MATLAB_ROOT)\toolbox\rtw\targets\pil\c\xil_rtiostream.c


rtiostream_utils.obj : $(MATLAB_ROOT)\toolbox\coder\rtiostream\src\utils\rtiostream_utils.c
	$(CC) $(CFLAGS) -Fo"$@" $(MATLAB_ROOT)\toolbox\coder\rtiostream\src\utils\rtiostream_utils.c


coder_assumptions_app.obj : $(MATLAB_ROOT)\toolbox\rtw\targets\pil\c\coder_assumptions_app.c
	$(CC) $(CFLAGS) -Fo"$@" $(MATLAB_ROOT)\toolbox\rtw\targets\pil\c\coder_assumptions_app.c


coder_assumptions_data_stream.obj : $(MATLAB_ROOT)\toolbox\rtw\targets\pil\c\coder_assumptions_data_stream.c
	$(CC) $(CFLAGS) -Fo"$@" $(MATLAB_ROOT)\toolbox\rtw\targets\pil\c\coder_assumptions_data_stream.c


coder_assumptions_rtiostream.obj : $(MATLAB_ROOT)\toolbox\rtw\targets\pil\c\coder_assumptions_rtiostream.c
	$(CC) $(CFLAGS) -Fo"$@" $(MATLAB_ROOT)\toolbox\rtw\targets\pil\c\coder_assumptions_rtiostream.c


sil_main.obj : $(MATLAB_ROOT)\toolbox\rtw\targets\pil\c\sil_main.c
	$(CC) $(CFLAGS) -Fo"$@" $(MATLAB_ROOT)\toolbox\rtw\targets\pil\c\sil_main.c


target_io.obj : $(MATLAB_ROOT)\toolbox\rtw\targets\pil\c\target_io.c
	$(CC) $(CFLAGS) -Fo"$@" $(MATLAB_ROOT)\toolbox\rtw\targets\pil\c\target_io.c


rtiostream_tcpip.obj : $(MATLAB_ROOT)\toolbox\coder\rtiostream\src\rtiostreamtcpip\rtiostream_tcpip.c
	$(CC) $(CFLAGS) -Fo"$@" $(MATLAB_ROOT)\toolbox\coder\rtiostream\src\rtiostreamtcpip\rtiostream_tcpip.c


###########################################################################
## DEPENDENCIES
###########################################################################

$(ALL_OBJS) : rtw_proj.tmw $(COMPILER_COMMAND_FILE) $(MAKEFILE)


###########################################################################
## MISCELLANEOUS TARGETS
###########################################################################

info : 
	@cmd /C "@echo ### PRODUCT = $(PRODUCT)"
	@cmd /C "@echo ### PRODUCT_TYPE = $(PRODUCT_TYPE)"
	@cmd /C "@echo ### BUILD_TYPE = $(BUILD_TYPE)"
	@cmd /C "@echo ### INCLUDES = $(INCLUDES)"
	@cmd /C "@echo ### DEFINES = $(DEFINES)"
	@cmd /C "@echo ### ALL_SRCS = $(ALL_SRCS)"
	@cmd /C "@echo ### ALL_OBJS = $(ALL_OBJS)"
	@cmd /C "@echo ### LIBS = $(LIBS)"
	@cmd /C "@echo ### MODELREF_LIBS = $(MODELREF_LIBS)"
	@cmd /C "@echo ### SYSTEM_LIBS = $(SYSTEM_LIBS)"
	@cmd /C "@echo ### TOOLCHAIN_LIBS = $(TOOLCHAIN_LIBS)"
	@cmd /C "@echo ### CFLAGS = $(CFLAGS)"
	@cmd /C "@echo ### LDFLAGS = $(LDFLAGS)"
	@cmd /C "@echo ### SHAREDLIB_LDFLAGS = $(SHAREDLIB_LDFLAGS)"
	@cmd /C "@echo ### CPPFLAGS = $(CPPFLAGS)"
	@cmd /C "@echo ### CPP_LDFLAGS = $(CPP_LDFLAGS)"
	@cmd /C "@echo ### CPP_SHAREDLIB_LDFLAGS = $(CPP_SHAREDLIB_LDFLAGS)"
	@cmd /C "@echo ### ARFLAGS = $(ARFLAGS)"
	@cmd /C "@echo ### MEX_CFLAGS = $(MEX_CFLAGS)"
	@cmd /C "@echo ### MEX_CPPFLAGS = $(MEX_CPPFLAGS)"
	@cmd /C "@echo ### MEX_LDFLAGS = $(MEX_LDFLAGS)"
	@cmd /C "@echo ### MEX_CPPLDFLAGS = $(MEX_CPPLDFLAGS)"
	@cmd /C "@echo ### DOWNLOAD_FLAGS = $(DOWNLOAD_FLAGS)"
	@cmd /C "@echo ### EXECUTE_FLAGS = $(EXECUTE_FLAGS)"
	@cmd /C "@echo ### MAKE_FLAGS = $(MAKE_FLAGS)"


clean : 
	$(ECHO) "### Deleting all derived files..."
	@if exist $(PRODUCT) $(RM) $(PRODUCT)
	$(RM) $(ALL_OBJS)
	$(ECHO) "### Deleted all derived files."


