
############# Target type (Debug/Release) ##################
############################################################
CPPCompileDebug= /Zi /Od /D "_DEBUG" $(LIBCRT_FLAG)d  /Fd"$(TARGET_NAME)" 
CPPCompileRelease= /Ox /D"NDEBUG" $(LIBCRT_FLAG) /Fd"$(TARGET_NAME)" 
LinkDebug=
LinkRelease=
BuildSet=Debug
SUBSYSTEM=/SUBSYSTEM:console
RPFrameWorkDll=False
SimulinkLibName=

ConfigurationCPPCompileSwitches=   /I . /I . /I $(OMROOT)\LangCpp /I $(OMROOT)\LangCpp\oxf /nologo /W3 $(ENABLE_EH) $(CRT_FLAGS) $(CPPCompileDebug) /D "_AFXDLL" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /D "_WINDOWS" $(INST_FLAGS) $(INCLUDE_PATH) $(INST_INCLUDES) /c   

SIMULINK_CONFIG=False
!IF "$(SIMULINK_CONFIG)" == "True"
ConfigurationCPPCompileSwitches=$(ConfigurationCPPCompileSwitches) /D "OM_WITH_CLEANUP"
!ENDIF


!IF "$(RPFrameWorkDll)" == "True"
ConfigurationCPPCompileSwitches=$(ConfigurationCPPCompileSwitches) /D "FRAMEWORK_DLL"
!ENDIF

################### Compilation flags ######################
############################################################
INCLUDE_QUALIFIER=/I
DEFINE_QUALIFIER=/D

!IF "False" == "True"
MT_PREFIX=MT
LIBCRT_FLAG=/MT
!ELSE
MT_PREFIX=
LIBCRT_FLAG=/MD
!ENDIF

LIB_PREFIX=MSVC15x64$(MT_PREFIX)

CRT_FLAGS=$(DEFINE_QUALIFIER)_CRT_SECURE_NO_DEPRECATE $(DEFINE_QUALIFIER)_CRT_SECURE_NO_WARNINGS
ENABLE_EH=/EHa

WINMM_LIB=winmm.lib

################### Commands definition #########################
#################################################################
RMDIR = rmdir
LIB_CMD=link.exe -lib
LINK_CMD=link.exe
LIB_FLAGS=$(LinkDebug)  /NOLOGO   
LINK_FLAGS=$(LinkDebug)  /NOLOGO    $(SUBSYSTEM) /MACHINE:x64 

############### Generated macros #################
##################################################

FLAGSFILE=
RULESFILE=
OMROOT="L:\tests\Rhapsody\Share"
RHPROOT="L:\tests\Rhapsody"
FRAMEWORK_LIB_ROOT="L:\tests\Rhapsody\UserShare"

CPP_EXT=.cpp
H_EXT=.h
OBJ_EXT=.obj
EXE_EXT=.exe
LIB_EXT=.lib

INSTRUMENTATION=None

TIME_MODEL=RealTime

TARGET_TYPE=Library

TARGET_NAME=DefaultComponent

all : $(TARGET_NAME)$(LIB_EXT) DefaultComponent.mak

TARGET_MAIN=MainDefaultComponent

LIBS=

INCLUDE_PATH= \
  $(INCLUDE_QUALIFIER)$(OMROOT)/LangCpp/osconfig/WIN32

ADDITIONAL_OBJS=

OBJS= \
  ModelClass.obj \
  ModelEventType.obj \
  ModelClassAttribute.obj \
  ModelDataType.obj \
  ModelDefine.obj \
  ModelEventArgumentType.obj \
  ModelClassState.obj \
  ModelInstance.obj \
  ModelOperationType.obj \
  Receiver.obj \
  Sender.obj \
  SingleParser.obj \
  TestConductorParser.obj \
  DefaultParser.obj \
  MultiParser.obj \
  IParser.obj \
  ReceivedCommandsLogger.obj \
  XMLReader.obj \
  TargetInformation.obj \
  TargetList.obj \
  MessageLogger.obj \
  MainWindowMessageLogger.obj \
  CommandList.obj \
  ReceivedEventParameter.obj \
  InstanceItemSeqenceDiagram.obj \
  InstanceItemTimingDiagram.obj \
  Command.obj \
  CommandConstructor.obj \
  CommandDestructor.obj \
  CommandEventCreated.obj \
  CommandEventTripletData.obj \
  CommandEventEndDispatch.obj \
  CommandEventStartDispatch.obj \
  CommandTraceEvent.obj \
  CommandOperationCall.obj \
  CommandIntVal.obj \
  CommandListFilter.obj \
  FilterPart.obj \
  AbstractCommandKeyValueAdapter.obj \
  CommandKeyValueAdapterRegistry.obj \
  CommandConstructorKeyValueAdapter.obj \
  CommandTraceEventKeyValueAdapter.obj \
  CommandConstructorStringAdapter.obj \
  CommandEventCreatedStringAdapter.obj \
  CommandEventEndDispatchStringAdapter.obj \
  CommandEventStartDispatchStringAdapter.obj \
  CommandOperationCallStringAdapter.obj \
  CommandStringAdapterRegistry.obj \
  CommandTraceEventStringAdapter.obj \
  AbstractCommandStringAdapter.obj \
  CommandsExporter.obj \
  AbstractExporter.obj \
  CommandListExporter.obj \
  FileExporter.obj \
  CommandXmlWriter.obj \
  AbstractImporter.obj \
  CommandListImporter.obj \
  FileImporter.obj \
  CommandXmlReader.obj \
  MainWindow.obj \
  ConfigurationWindow.obj \
  SequenceDiagram.obj \
  TimingDiagram.obj \
  BreakPoints.obj \
  EventInjection.obj \
  DataViewFilterGeneration.obj \
  DataView.obj \
  Builder.obj \
  PlugInLoader.obj \
  TargetCommunication.obj \
  IdeCommunication.obj \
  PlugInLoaderTC.obj \
  TestConductorAPI.obj \
  SequenceDiagramToRhapsodyExporter.obj \
  RemoteControll.obj \
  LogicLevel.obj \
  DataTransmission.obj \
  DataParser.obj \
  ParserInterface.obj \
  Logging.obj \
  DataContainer.obj \
  ReceivedCommands.obj \
  Filter.obj \
  Adapter.obj \
  KeyValueAdapter.obj \
  StringAdapter.obj \
  Exporter.obj \
  Importer.obj \
  RunTime.obj




OBJ_DIR=

!IF "$(OBJ_DIR)"!=""
CREATE_OBJ_DIR=if not exist $(OBJ_DIR) mkdir $(OBJ_DIR)
CLEAN_OBJ_DIR= if exist $(OBJ_DIR) $(RMDIR) $(OBJ_DIR)
!ELSE
CREATE_OBJ_DIR=
CLEAN_OBJ_DIR=
!ENDIF

######################## Predefined macros ############################
#######################################################################
!IF "$(OBJS)" != ""
$(OBJS) : $(INST_LIBS) $(OXF_LIBS)
!ENDIF

LIB_POSTFIX=
!IF "$(BuildSet)"=="Release"
LIB_POSTFIX=R
!ENDIF

!IF "$(TARGET_TYPE)" == "Executable"
LinkDebug=$(LinkDebug) /DEBUG
LinkRelease=$(LinkRelease) /OPT:NOREF
!ELSEIF "$(TARGET_TYPE)" == "Library"
LinkDebug=$(LinkDebug)
!ENDIF


!IF "$(INSTRUMENTATION)" == "Animation"
INST_FLAGS=/D "OMANIMATOR"
INST_INCLUDES=/I $(OMROOT)\LangCpp\aom /I $(OMROOT)\LangCpp\tom
!IF "$(RPFrameWorkDll)" == "True"
INST_LIBS= 
OXF_LIBS=$(OMROOT)\LangCpp\lib\$(LIB_PREFIX)oxfanimdll$(LIB_POSTFIX)$(LIB_EXT) 
!ELSE
INST_LIBS= $(FRAMEWORK_LIB_ROOT)\LangCpp\lib\$(LIB_PREFIX)aomanim$(LIB_POSTFIX)$(LIB_EXT) $(FRAMEWORK_LIB_ROOT)\LangCpp\lib\$(LIB_PREFIX)oxsiminst$(LIB_POSTFIX)$(LIB_EXT)
OXF_LIBS=$(FRAMEWORK_LIB_ROOT)\LangCpp\lib\$(LIB_PREFIX)oxfinst$(LIB_POSTFIX)$(LIB_EXT) $(FRAMEWORK_LIB_ROOT)\LangCpp\lib\$(LIB_PREFIX)omComAppl$(LIB_POSTFIX)$(LIB_EXT) $(SimulinkLibName)
!ENDIF
SOCK_LIB=wsock32.lib

!ELSEIF "$(INSTRUMENTATION)" == "Tracing"
INST_FLAGS=/D "OMTRACER"
INST_INCLUDES=/I $(OMROOT)\LangCpp\aom /I $(OMROOT)\LangCpp\tom
!IF "$(RPFrameWorkDll)" == "True"
INST_LIBS=
OXF_LIBS= $(FRAMEWORK_LIB_ROOT)\LangCpp\lib\$(LIB_PREFIX)oxftracedll$(LIB_POSTFIX)$(LIB_EXT) 
!ELSE
INST_LIBS=$(FRAMEWORK_LIB_ROOT)\LangCpp\lib\$(LIB_PREFIX)tomtrace$(LIB_POSTFIX)$(LIB_EXT) $(FRAMEWORK_LIB_ROOT)\LangCpp\lib\$(LIB_PREFIX)aomtrace$(LIB_POSTFIX)$(LIB_EXT) $(FRAMEWORK_LIB_ROOT)\LangCpp\lib\$(LIB_PREFIX)oxsiminst$(LIB_POSTFIX)$(LIB_EXT)
OXF_LIBS= $(FRAMEWORK_LIB_ROOT)\LangCpp\lib\$(LIB_PREFIX)oxfinst$(LIB_POSTFIX)$(LIB_EXT) $(FRAMEWORK_LIB_ROOT)\LangCpp\lib\$(LIB_PREFIX)omComAppl$(LIB_POSTFIX)$(LIB_EXT) $(SimulinkLibName)
!ENDIF
SOCK_LIB=wsock32.lib

!ELSEIF "$(INSTRUMENTATION)" == "None" 
INST_FLAGS=
INST_INCLUDES=
INST_LIBS=
!IF "$(RPFrameWorkDll)" == "True"
OXF_LIBS=$(FRAMEWORK_LIB_ROOT)\LangCpp\lib\$(LIB_PREFIX)oxfdll$(LIB_POSTFIX)$(LIB_EXT) $(FRAMEWORK_LIB_ROOT)\LangCpp\lib\$(LIB_PREFIX)oxsim$(LIB_POSTFIX)$(LIB_EXT)
!ELSE
OXF_LIBS=$(FRAMEWORK_LIB_ROOT)\LangCpp\lib\$(LIB_PREFIX)oxf$(LIB_POSTFIX)$(LIB_EXT) $(SimulinkLibName) $(FRAMEWORK_LIB_ROOT)\LangCpp\lib\$(LIB_PREFIX)oxsim$(LIB_POSTFIX)$(LIB_EXT)
!ENDIF
SOCK_LIB=

!ELSE
!ERROR An invalid Instrumentation $(INSTRUMENTATION) is specified.
!ENDIF



################## Generated dependencies ########################
##################################################################






ModelClass.obj : ModelClass.cpp ModelClass.h    ModelClassAttribute.h ModelClassState.h ModelInstance.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"ModelClass.obj" "ModelClass.cpp" 



ModelEventType.obj : ModelEventType.cpp ModelEventType.h    ModelEventArgumentType.h TargetInformation.h ModelDataType.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"ModelEventType.obj" "ModelEventType.cpp" 



ModelClassAttribute.obj : ModelClassAttribute.cpp ModelClassAttribute.h    ModelDataType.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"ModelClassAttribute.obj" "ModelClassAttribute.cpp" 



ModelDataType.obj : ModelDataType.cpp ModelDataType.h    
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"ModelDataType.obj" "ModelDataType.cpp" 



ModelDefine.obj : ModelDefine.cpp ModelDefine.h    
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"ModelDefine.obj" "ModelDefine.cpp" 



ModelEventArgumentType.obj : ModelEventArgumentType.cpp ModelEventArgumentType.h    ModelDataType.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"ModelEventArgumentType.obj" "ModelEventArgumentType.cpp" 



ModelClassState.obj : ModelClassState.cpp ModelClassState.h    
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"ModelClassState.obj" "ModelClassState.cpp" 



ModelInstance.obj : ModelInstance.cpp ModelInstance.h    ModelClass.h TargetInformation.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"ModelInstance.obj" "ModelInstance.cpp" 



ModelOperationType.obj : ModelOperationType.cpp ModelOperationType.h    TargetInformation.h ModelEventType.h ModelEventArgumentType.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"ModelOperationType.obj" "ModelOperationType.cpp" 



Receiver.obj : Receiver.cpp Receiver.h    DataTransmission.h IParser.h SingleParser.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"Receiver.obj" "Receiver.cpp" 



Sender.obj : Sender.cpp Sender.h    DataTransmission.h TargetCommunication.h MainWindow.h ModelInstance.h ModelClassAttribute.h TargetInformation.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"Sender.obj" "Sender.cpp" 



SingleParser.obj : SingleParser.cpp SingleParser.h    DataParser.h TargetInformation.h ReceivedEventParameter.h ModelEventArgumentType.h RemoteControll.h CommandEventEndDispatch.h CommandEventCreated.h CommandEventStartDispatch.h ReceivedCommandsLogger.h CommandOperationCall.h MainWindow.h CommandTraceEvent.h CommandIntVal.h CommandEventTripletData.h ModelEventType.h ModelInstance.h Command.h IParser.h Receiver.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"SingleParser.obj" "SingleParser.cpp" 



TestConductorParser.obj : TestConductorParser.cpp TestConductorParser.h    DataParser.h TestConductorAPI.h MainWindow.h IParser.h Receiver.h ReceivedCommandsLogger.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"TestConductorParser.obj" "TestConductorParser.cpp" 



DefaultParser.obj : DefaultParser.cpp DefaultParser.h    DataParser.h IParser.h Receiver.h ReceivedCommandsLogger.h MainWindow.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"DefaultParser.obj" "DefaultParser.cpp" 



MultiParser.obj : MultiParser.cpp MultiParser.h    DataParser.h ReceivedCommandsLogger.h CommandEventEndDispatch.h CommandEventCreated.h CommandEventStartDispatch.h CommandOperationCall.h TargetInformation.h ModelEventArgumentType.h MainWindow.h TargetList.h SingleParser.h ReceivedEventParameter.h RemoteControll.h IParser.h Receiver.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"MultiParser.obj" "MultiParser.cpp" 



IParser.obj : IParser.cpp IParser.h    ParserInterface.h ReceivedCommandsLogger.h MainWindow.h Receiver.h ModelInstance.h CommandConstructor.h CommandDestructor.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"IParser.obj" "IParser.cpp" 



ReceivedCommandsLogger.obj : ReceivedCommandsLogger.cpp ReceivedCommandsLogger.h    Logging.h CommandList.h MainWindow.h CommandStringAdapterRegistry.h MessageLogger.h CommandKeyValueAdapterRegistry.h RemoteControll.h SequenceDiagram.h CommandConstructor.h CommandTraceEvent.h CommandOperationCall.h CommandDestructor.h CommandEventStartDispatch.h CommandEventEndDispatch.h CommandEventCreated.h CommandsExporter.h TimingDiagram.h CommandListExporter.h CommandListImporter.h TargetList.h ModelInstance.h TargetInformation.h Command.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"ReceivedCommandsLogger.obj" "ReceivedCommandsLogger.cpp" 



XMLReader.obj : XMLReader.cpp XMLReader.h    Logging.h MainWindow.h BreakPoints.h DataViewFilterGeneration.h TargetInformation.h EventInjection.h ModelClass.h ModelClassAttribute.h ModelEventType.h ModelDataType.h SingleParser.h TargetList.h ModelOperationType.h ModelDefine.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"XMLReader.obj" "XMLReader.cpp" 



TargetInformation.obj : TargetInformation.cpp TargetInformation.h    Logging.h ModelDataType.h ModelEventType.h ModelClass.h MainWindow.h ModelClassState.h ModelInstance.h ModelClassAttribute.h LogicLevel.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"TargetInformation.obj" "TargetInformation.cpp" 



TargetList.obj : TargetList.cpp TargetList.h    Logging.h TargetInformation.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"TargetList.obj" "TargetList.cpp" 



MessageLogger.obj : MessageLogger.cpp MessageLogger.h    Logging.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"MessageLogger.obj" "MessageLogger.cpp" 



MainWindowMessageLogger.obj : MainWindowMessageLogger.cpp MainWindowMessageLogger.h    Logging.h MainWindow.h MessageLogger.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"MainWindowMessageLogger.obj" "MainWindowMessageLogger.cpp" 



CommandList.obj : CommandList.cpp CommandList.h    DataContainer.h CommandListFilter.h Command.h TargetList.h CommandEventStartDispatch.h CommandEventEndDispatch.h CommandEventCreated.h TargetInformation.h ModelEventType.h ModelInstance.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"CommandList.obj" "CommandList.cpp" 



ReceivedEventParameter.obj : ReceivedEventParameter.cpp ReceivedEventParameter.h    DataContainer.h ModelEventArgumentType.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"ReceivedEventParameter.obj" "ReceivedEventParameter.cpp" 



InstanceItemSeqenceDiagram.obj : InstanceItemSeqenceDiagram.cpp InstanceItemSeqenceDiagram.h    DataContainer.h ModelInstance.h CommandList.h TargetInformation.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"InstanceItemSeqenceDiagram.obj" "InstanceItemSeqenceDiagram.cpp" 



InstanceItemTimingDiagram.obj : InstanceItemTimingDiagram.cpp InstanceItemTimingDiagram.h    DataContainer.h ModelInstance.h CommandList.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"InstanceItemTimingDiagram.obj" "InstanceItemTimingDiagram.cpp" 



Command.obj : Command.cpp Command.h    ReceivedCommands.h TargetInformation.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"Command.obj" "Command.cpp" 



CommandConstructor.obj : CommandConstructor.cpp CommandConstructor.h    ReceivedCommands.h ModelInstance.h TargetInformation.h Command.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"CommandConstructor.obj" "CommandConstructor.cpp" 



CommandDestructor.obj : CommandDestructor.cpp CommandDestructor.h    ReceivedCommands.h ModelInstance.h TargetInformation.h Command.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"CommandDestructor.obj" "CommandDestructor.cpp" 



CommandEventCreated.obj : CommandEventCreated.cpp CommandEventCreated.h    ReceivedCommands.h ModelInstance.h ReceivedEventParameter.h ModelEventType.h CommandEventStartDispatch.h TargetInformation.h CommandEventTripletData.h Command.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"CommandEventCreated.obj" "CommandEventCreated.cpp" 



CommandEventTripletData.obj : CommandEventTripletData.cpp CommandEventTripletData.h    ReceivedCommands.h TargetInformation.h Command.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"CommandEventTripletData.obj" "CommandEventTripletData.cpp" 



CommandEventEndDispatch.obj : CommandEventEndDispatch.cpp CommandEventEndDispatch.h    ReceivedCommands.h CommandEventStartDispatch.h TargetInformation.h CommandEventTripletData.h Command.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"CommandEventEndDispatch.obj" "CommandEventEndDispatch.cpp" 



CommandEventStartDispatch.obj : CommandEventStartDispatch.cpp CommandEventStartDispatch.h    ReceivedCommands.h CommandEventEndDispatch.h CommandEventCreated.h TargetInformation.h CommandEventTripletData.h Command.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"CommandEventStartDispatch.obj" "CommandEventStartDispatch.cpp" 



CommandTraceEvent.obj : CommandTraceEvent.cpp CommandTraceEvent.h    ReceivedCommands.h ModelInstance.h ModelEventType.h ReceivedEventParameter.h TargetInformation.h Command.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"CommandTraceEvent.obj" "CommandTraceEvent.cpp" 



CommandOperationCall.obj : CommandOperationCall.cpp CommandOperationCall.h    ReceivedCommands.h ModelInstance.h ModelEventType.h ReceivedEventParameter.h TargetInformation.h Command.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"CommandOperationCall.obj" "CommandOperationCall.cpp" 



CommandIntVal.obj : CommandIntVal.cpp CommandIntVal.h    ReceivedCommands.h ModelInstance.h TargetInformation.h Command.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"CommandIntVal.obj" "CommandIntVal.cpp" 



CommandListFilter.obj : CommandListFilter.cpp CommandListFilter.h    Filter.h FilterPart.h CommandEventEndDispatch.h CommandOperationCall.h CommandEventCreated.h CommandTraceEvent.h CommandEventStartDispatch.h CommandConstructor.h CommandDestructor.h CommandIntVal.h Command.h ModelInstance.h ModelEventType.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"CommandListFilter.obj" "CommandListFilter.cpp" 



FilterPart.obj : FilterPart.cpp FilterPart.h    Filter.h ModelInstance.h ModelEventType.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"FilterPart.obj" "FilterPart.cpp" 



AbstractCommandKeyValueAdapter.obj : AbstractCommandKeyValueAdapter.cpp AbstractCommandKeyValueAdapter.h    KeyValueAdapter.h TargetInformation.h Command.h ReceivedEventParameter.h CommandAdapter.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"AbstractCommandKeyValueAdapter.obj" "AbstractCommandKeyValueAdapter.cpp" 



CommandKeyValueAdapterRegistry.obj : CommandKeyValueAdapterRegistry.cpp CommandKeyValueAdapterRegistry.h    KeyValueAdapter.h CommandAdapterRegistry.h CommandAdapter.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"CommandKeyValueAdapterRegistry.obj" "CommandKeyValueAdapterRegistry.cpp" 



CommandConstructorKeyValueAdapter.obj : CommandConstructorKeyValueAdapter.cpp CommandConstructorKeyValueAdapter.h    KeyValueAdapter.h CommandConstructor.h ModelClass.h ModelInstance.h Command.h AbstractCommandKeyValueAdapter.h CommandAdapter.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"CommandConstructorKeyValueAdapter.obj" "CommandConstructorKeyValueAdapter.cpp" 



CommandTraceEventKeyValueAdapter.obj : CommandTraceEventKeyValueAdapter.cpp CommandTraceEventKeyValueAdapter.h    KeyValueAdapter.h CommandTraceEvent.h ReceivedEventParameter.h Command.h AbstractCommandKeyValueAdapter.h CommandAdapter.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"CommandTraceEventKeyValueAdapter.obj" "CommandTraceEventKeyValueAdapter.cpp" 



CommandConstructorStringAdapter.obj : CommandConstructorStringAdapter.cpp CommandConstructorStringAdapter.h    StringAdapter.h CommandConstructor.h ModelInstance.h ModelClass.h Command.h AbstractCommandStringAdapter.h CommandAdapter.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"CommandConstructorStringAdapter.obj" "CommandConstructorStringAdapter.cpp" 



CommandEventCreatedStringAdapter.obj : CommandEventCreatedStringAdapter.cpp CommandEventCreatedStringAdapter.h    StringAdapter.h CommandEventCreated.h ModelInstance.h ModelEventType.h ReceivedEventParameter.h Command.h AbstractCommandStringAdapter.h CommandAdapter.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"CommandEventCreatedStringAdapter.obj" "CommandEventCreatedStringAdapter.cpp" 



CommandEventEndDispatchStringAdapter.obj : CommandEventEndDispatchStringAdapter.cpp CommandEventEndDispatchStringAdapter.h    StringAdapter.h CommandEventEndDispatch.h CommandEventCreated.h ModelEventType.h CommandEventStartDispatch.h Command.h AbstractCommandStringAdapter.h CommandAdapter.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"CommandEventEndDispatchStringAdapter.obj" "CommandEventEndDispatchStringAdapter.cpp" 



CommandEventStartDispatchStringAdapter.obj : CommandEventStartDispatchStringAdapter.cpp CommandEventStartDispatchStringAdapter.h    StringAdapter.h CommandEventStartDispatch.h CommandEventCreated.h ModelEventType.h Command.h AbstractCommandStringAdapter.h CommandAdapter.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"CommandEventStartDispatchStringAdapter.obj" "CommandEventStartDispatchStringAdapter.cpp" 



CommandOperationCallStringAdapter.obj : CommandOperationCallStringAdapter.cpp CommandOperationCallStringAdapter.h    StringAdapter.h CommandOperationCall.h ModelInstance.h ModelEventType.h ReceivedEventParameter.h Command.h AbstractCommandStringAdapter.h CommandAdapter.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"CommandOperationCallStringAdapter.obj" "CommandOperationCallStringAdapter.cpp" 



CommandStringAdapterRegistry.obj : CommandStringAdapterRegistry.cpp CommandStringAdapterRegistry.h    StringAdapter.h CommandAdapterRegistry.h CommandAdapter.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"CommandStringAdapterRegistry.obj" "CommandStringAdapterRegistry.cpp" 



CommandTraceEventStringAdapter.obj : CommandTraceEventStringAdapter.cpp CommandTraceEventStringAdapter.h    StringAdapter.h ModelEventType.h ModelInstance.h CommandTraceEvent.h Command.h AbstractCommandStringAdapter.h CommandAdapter.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"CommandTraceEventStringAdapter.obj" "CommandTraceEventStringAdapter.cpp" 



AbstractCommandStringAdapter.obj : AbstractCommandStringAdapter.cpp AbstractCommandStringAdapter.h    StringAdapter.h TargetInformation.h Command.h CommandAdapter.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"AbstractCommandStringAdapter.obj" "AbstractCommandStringAdapter.cpp" 



CommandsExporter.obj : CommandsExporter.cpp CommandsExporter.h    Exporter.h Command.h CommandStringAdapterRegistry.h FileExporter.h MessageLogger.h AbstractExporter.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"CommandsExporter.obj" "CommandsExporter.cpp" 



AbstractExporter.obj : AbstractExporter.cpp AbstractExporter.h    Exporter.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"AbstractExporter.obj" "AbstractExporter.cpp" 



CommandListExporter.obj : CommandListExporter.cpp CommandListExporter.h    Exporter.h CommandList.h TargetInformation.h ModelClass.h ModelDataType.h ModelInstance.h ModelEventType.h ModelEventArgumentType.h CommandXmlWriter.h FileExporter.h MessageLogger.h AbstractExporter.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"CommandListExporter.obj" "CommandListExporter.cpp" 



FileExporter.obj : FileExporter.cpp FileExporter.h    Exporter.h MessageLogger.h AbstractExporter.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"FileExporter.obj" "FileExporter.cpp" 



CommandXmlWriter.obj : CommandXmlWriter.cpp CommandXmlWriter.h    Exporter.h ReceivedEventParameter.h ModelInstance.h TargetInformation.h Command.h CommandConstructor.h CommandTraceEvent.h CommandEventCreated.h CommandEventStartDispatch.h CommandEventEndDispatch.h CommandOperationCall.h CommandIntVal.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"CommandXmlWriter.obj" "CommandXmlWriter.cpp" 



AbstractImporter.obj : AbstractImporter.cpp AbstractImporter.h    Importer.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"AbstractImporter.obj" "AbstractImporter.cpp" 



CommandListImporter.obj : CommandListImporter.cpp CommandListImporter.h    Importer.h CommandList.h TargetList.h TargetInformation.h ModelClass.h ModelDataType.h ModelInstance.h ModelEventType.h ModelEventArgumentType.h CommandXmlReader.h FileImporter.h MessageLogger.h AbstractImporter.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"CommandListImporter.obj" "CommandListImporter.cpp" 



FileImporter.obj : FileImporter.cpp FileImporter.h    Importer.h MessageLogger.h AbstractImporter.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"FileImporter.obj" "FileImporter.cpp" 



CommandXmlReader.obj : CommandXmlReader.cpp CommandXmlReader.h    Importer.h TargetList.h CommandConstructor.h CommandTraceEvent.h ReceivedEventParameter.h CommandEventTripletData.h CommandDestructor.h Command.h CommandEventCreated.h CommandEventStartDispatch.h CommandEventEndDispatch.h CommandOperationCall.h CommandIntVal.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"CommandXmlReader.obj" "CommandXmlReader.cpp" 



MainWindow.obj : MainWindow.cpp MainWindow.h    SequenceDiagram.h DataViewFilterGeneration.h CommandList.h TimingDiagram.h ModelClass.h ModelClassAttribute.h ModelClassState.h ModelInstance.h ModelEventType.h ModelDataType.h DataView.h TargetInformation.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"MainWindow.obj" "MainWindow.cpp" 



ConfigurationWindow.obj : ConfigurationWindow.cpp ConfigurationWindow.h    PlugInLoader.h XMLReader.h PlugInLoaderTC.h TestConductorParser.h Receiver.h SequenceDiagram.h TimingDiagram.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"ConfigurationWindow.obj" "ConfigurationWindow.cpp" 



SequenceDiagram.obj : SequenceDiagram.cpp SequenceDiagram.h    InstanceItemSeqenceDiagram.h CommandList.h CommandTraceEvent.h CommandConstructor.h CommandDestructor.h CommandEventCreated.h CommandEventEndDispatch.h CommandEventStartDispatch.h CommandOperationCall.h ModelEventType.h ReceivedEventParameter.h ModelEventArgumentType.h ModelInstance.h CommandIntVal.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"SequenceDiagram.obj" "SequenceDiagram.cpp" 



TimingDiagram.obj : TimingDiagram.cpp TimingDiagram.h    CommandList.h InstanceItemTimingDiagram.h ModelEventType.h TargetInformation.h CommandEventStartDispatch.h CommandEventCreated.h CommandEventEndDispatch.h CommandConstructor.h CommandTraceEvent.h CommandOperationCall.h Command.h CommandDestructor.h ModelInstance.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"TimingDiagram.obj" "TimingDiagram.cpp" 



BreakPoints.obj : BreakPoints.cpp BreakPoints.h    Sender.h TargetInformation.h ModelEventType.h ModelClassState.h ModelInstance.h TargetList.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"BreakPoints.obj" "BreakPoints.cpp" 



EventInjection.obj : EventInjection.cpp EventInjection.h    Sender.h MainWindow.h ModelEventType.h ModelEventArgumentType.h TargetList.h ModelInstance.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"EventInjection.obj" "EventInjection.cpp" 



DataViewFilterGeneration.obj : DataViewFilterGeneration.cpp DataViewFilterGeneration.h    TargetInformation.h CommandList.h CommandListFilter.h TargetList.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"DataViewFilterGeneration.obj" "DataViewFilterGeneration.cpp" 



DataView.obj : DataView.cpp DataView.h    SequenceDiagram.h CommandList.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"DataView.obj" "DataView.cpp" 



Builder.obj : Builder.cpp Builder.h    RunTime.h MainWindow.h XMLReader.h PlugInLoader.h Receiver.h Sender.h ConfigurationWindow.h SingleParser.h TestConductorParser.h DefaultParser.h ReceivedCommandsLogger.h SequenceDiagram.h BreakPoints.h EventInjection.h DataViewFilterGeneration.h MultiParser.h PlugInLoaderTC.h TestConductorAPI.h CommandStringAdapterRegistry.h CommandConstructorStringAdapter.h CommandEventCreatedStringAdapter.h CommandEventStartDispatchStringAdapter.h CommandEventEndDispatchStringAdapter.h CommandTraceEventStringAdapter.h CommandOperationCallStringAdapter.h MainWindowMessageLogger.h TimingDiagram.h TargetInformation.h TargetList.h SequenceDiagramToRhapsodyExporter.h CommandKeyValueAdapterRegistry.h CommandConstructorKeyValueAdapter.h CommandTraceEventKeyValueAdapter.h RemoteControll.h IParser.h CommandAdapter.h MessageLogger.h ReceivedEventParameter.h ModelEventArgumentType.h CommandAdapterRegistry.h AbstractCommandStringAdapter.h AbstractCommandKeyValueAdapter.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"Builder.obj" "Builder.cpp" 



PlugInLoader.obj : PlugInLoader.cpp PlugInLoader.h    MainWindow.h Sender.h Receiver.h TargetCommunication.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"PlugInLoader.obj" "PlugInLoader.cpp" 



TargetCommunication.obj : TargetCommunication.cpp     
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"TargetCommunication.obj" "TargetCommunication.cpp" 



IdeCommunication.obj : IdeCommunication.cpp     
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"IdeCommunication.obj" "IdeCommunication.cpp" 



PlugInLoaderTC.obj : PlugInLoaderTC.cpp PlugInLoaderTC.h    MainWindow.h IdeCommunication.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"PlugInLoaderTC.obj" "PlugInLoaderTC.cpp" 



TestConductorAPI.obj : TestConductorAPI.cpp TestConductorAPI.h    MainWindow.h PlugInLoaderTC.h PlugInLoader.h ConfigurationWindow.h Sender.h IParser.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"TestConductorAPI.obj" "TestConductorAPI.cpp" 



SequenceDiagramToRhapsodyExporter.obj : SequenceDiagramToRhapsodyExporter.cpp SequenceDiagramToRhapsodyExporter.h    CommandOperationCall.h CommandEventCreated.h CommandEventEndDispatch.h CommandEventStartDispatch.h CommandTraceEvent.h ModelEventType.h CommandList.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"SequenceDiagramToRhapsodyExporter.obj" "SequenceDiagramToRhapsodyExporter.cpp" 



RemoteControll.obj : RemoteControll.cpp RemoteControll.h    CommandList.h ConfigurationWindow.h MainWindow.h Sender.h CommandConstructor.h CommandDestructor.h CommandEventCreated.h CommandEventEndDispatch.h CommandEventStartDispatch.h CommandIntVal.h CommandOperationCall.h CommandTraceEvent.h ModelEventType.h SingleParser.h TargetInformation.h ModelInstance.h Command.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"RemoteControll.obj" "RemoteControll.cpp" 



LogicLevel.obj : LogicLevel.cpp LogicLevel.h    
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"LogicLevel.obj" "LogicLevel.cpp" 



DataTransmission.obj : DataTransmission.cpp DataTransmission.h    Receiver.h Sender.h LogicLevel.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"DataTransmission.obj" "DataTransmission.cpp" 



DataParser.obj : DataParser.cpp DataParser.h    SingleParser.h TestConductorParser.h DefaultParser.h MultiParser.h DataTransmission.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"DataParser.obj" "DataParser.cpp" 



ParserInterface.obj : ParserInterface.cpp ParserInterface.h    IParser.h DataTransmission.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"ParserInterface.obj" "ParserInterface.cpp" 



Logging.obj : Logging.cpp Logging.h    ReceivedCommandsLogger.h XMLReader.h TargetInformation.h TargetList.h MessageLogger.h MainWindowMessageLogger.h LogicLevel.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"Logging.obj" "Logging.cpp" 



DataContainer.obj : DataContainer.cpp DataContainer.h    CommandList.h ReceivedEventParameter.h InstanceItemSeqenceDiagram.h InstanceItemTimingDiagram.h Logging.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"DataContainer.obj" "DataContainer.cpp" 



ReceivedCommands.obj : ReceivedCommands.cpp ReceivedCommands.h    Command.h CommandConstructor.h CommandDestructor.h CommandEventCreated.h CommandEventTripletData.h CommandEventEndDispatch.h CommandEventStartDispatch.h CommandTraceEvent.h CommandOperationCall.h CommandIntVal.h DataContainer.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"ReceivedCommands.obj" "ReceivedCommands.cpp" 



Filter.obj : Filter.cpp Filter.h    CommandListFilter.h FilterPart.h DataContainer.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"Filter.obj" "Filter.cpp" 



Adapter.obj : Adapter.cpp Adapter.h    CommandAdapter.h CommandAdapterRegistry.h Logging.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"Adapter.obj" "Adapter.cpp" 



KeyValueAdapter.obj : KeyValueAdapter.cpp KeyValueAdapter.h    AbstractCommandKeyValueAdapter.h CommandKeyValueAdapterRegistry.h CommandConstructorKeyValueAdapter.h CommandTraceEventKeyValueAdapter.h Adapter.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"KeyValueAdapter.obj" "KeyValueAdapter.cpp" 



StringAdapter.obj : StringAdapter.cpp StringAdapter.h    CommandConstructorStringAdapter.h CommandEventCreatedStringAdapter.h CommandEventEndDispatchStringAdapter.h CommandEventStartDispatchStringAdapter.h CommandOperationCallStringAdapter.h CommandStringAdapterRegistry.h CommandTraceEventStringAdapter.h AbstractCommandStringAdapter.h Adapter.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"StringAdapter.obj" "StringAdapter.cpp" 



Exporter.obj : Exporter.cpp Exporter.h    CommandsExporter.h AbstractExporter.h CommandListExporter.h FileExporter.h CommandXmlWriter.h LogicLevel.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"Exporter.obj" "Exporter.cpp" 



Importer.obj : Importer.cpp Importer.h    AbstractImporter.h CommandListImporter.h FileImporter.h CommandXmlReader.h LogicLevel.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"Importer.obj" "Importer.cpp" 



RunTime.obj : RunTime.cpp RunTime.h    Builder.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"RunTime.obj" "RunTime.cpp" 






$(TARGET_MAIN)$(OBJ_EXT) : $(TARGET_MAIN)$(CPP_EXT) $(OBJS) 
	$(CPP) $(ConfigurationCPPCompileSwitches) /Fo"$(TARGET_MAIN)$(OBJ_EXT)" $(TARGET_MAIN)$(CPP_EXT)

########################## Linking instructions ###############################
###############################################################################
$(TARGET_NAME)$(EXE_EXT): $(OBJS) $(ADDITIONAL_OBJS) $(TARGET_MAIN)$(OBJ_EXT) DefaultComponent.mak 
	@echo Linking $(TARGET_NAME)$(EXE_EXT)
	$(LINK_CMD)  $(TARGET_MAIN)$(OBJ_EXT) $(OBJS) $(ADDITIONAL_OBJS) \
	$(LIBS) \
	$(INST_LIBS) \
	$(OXF_LIBS) \
	$(SOCK_LIB) \
	$(WINMM_LIB) \
	$(LINK_FLAGS) /out:$(TARGET_NAME)$(EXE_EXT)
	if exist $(TARGET_NAME)$(EXE_EXT).manifest mt.exe -manifest $@.manifest -outputresource:$(TARGET_NAME)$(EXE_EXT);1



$(TARGET_NAME)$(LIB_EXT) : $(OBJS) $(ADDITIONAL_OBJS) DefaultComponent.mak
	@echo Building library $@
	$(LIB_CMD) $(LIB_FLAGS) /out:$(TARGET_NAME)$(LIB_EXT) $(OBJS) $(ADDITIONAL_OBJS) $(LIBS)

clean:
	@echo Cleanup
	if exist ModelClass.obj erase ModelClass.obj
	if exist ModelEventType.obj erase ModelEventType.obj
	if exist ModelClassAttribute.obj erase ModelClassAttribute.obj
	if exist ModelDataType.obj erase ModelDataType.obj
	if exist ModelDefine.obj erase ModelDefine.obj
	if exist ModelEventArgumentType.obj erase ModelEventArgumentType.obj
	if exist ModelClassState.obj erase ModelClassState.obj
	if exist ModelInstance.obj erase ModelInstance.obj
	if exist ModelOperationType.obj erase ModelOperationType.obj
	if exist Receiver.obj erase Receiver.obj
	if exist Sender.obj erase Sender.obj
	if exist SingleParser.obj erase SingleParser.obj
	if exist TestConductorParser.obj erase TestConductorParser.obj
	if exist DefaultParser.obj erase DefaultParser.obj
	if exist MultiParser.obj erase MultiParser.obj
	if exist IParser.obj erase IParser.obj
	if exist ReceivedCommandsLogger.obj erase ReceivedCommandsLogger.obj
	if exist XMLReader.obj erase XMLReader.obj
	if exist TargetInformation.obj erase TargetInformation.obj
	if exist TargetList.obj erase TargetList.obj
	if exist MessageLogger.obj erase MessageLogger.obj
	if exist MainWindowMessageLogger.obj erase MainWindowMessageLogger.obj
	if exist CommandList.obj erase CommandList.obj
	if exist ReceivedEventParameter.obj erase ReceivedEventParameter.obj
	if exist InstanceItemSeqenceDiagram.obj erase InstanceItemSeqenceDiagram.obj
	if exist InstanceItemTimingDiagram.obj erase InstanceItemTimingDiagram.obj
	if exist Command.obj erase Command.obj
	if exist CommandConstructor.obj erase CommandConstructor.obj
	if exist CommandDestructor.obj erase CommandDestructor.obj
	if exist CommandEventCreated.obj erase CommandEventCreated.obj
	if exist CommandEventTripletData.obj erase CommandEventTripletData.obj
	if exist CommandEventEndDispatch.obj erase CommandEventEndDispatch.obj
	if exist CommandEventStartDispatch.obj erase CommandEventStartDispatch.obj
	if exist CommandTraceEvent.obj erase CommandTraceEvent.obj
	if exist CommandOperationCall.obj erase CommandOperationCall.obj
	if exist CommandIntVal.obj erase CommandIntVal.obj
	if exist CommandListFilter.obj erase CommandListFilter.obj
	if exist FilterPart.obj erase FilterPart.obj
	if exist AbstractCommandKeyValueAdapter.obj erase AbstractCommandKeyValueAdapter.obj
	if exist CommandKeyValueAdapterRegistry.obj erase CommandKeyValueAdapterRegistry.obj
	if exist CommandConstructorKeyValueAdapter.obj erase CommandConstructorKeyValueAdapter.obj
	if exist CommandTraceEventKeyValueAdapter.obj erase CommandTraceEventKeyValueAdapter.obj
	if exist CommandConstructorStringAdapter.obj erase CommandConstructorStringAdapter.obj
	if exist CommandEventCreatedStringAdapter.obj erase CommandEventCreatedStringAdapter.obj
	if exist CommandEventEndDispatchStringAdapter.obj erase CommandEventEndDispatchStringAdapter.obj
	if exist CommandEventStartDispatchStringAdapter.obj erase CommandEventStartDispatchStringAdapter.obj
	if exist CommandOperationCallStringAdapter.obj erase CommandOperationCallStringAdapter.obj
	if exist CommandStringAdapterRegistry.obj erase CommandStringAdapterRegistry.obj
	if exist CommandTraceEventStringAdapter.obj erase CommandTraceEventStringAdapter.obj
	if exist AbstractCommandStringAdapter.obj erase AbstractCommandStringAdapter.obj
	if exist CommandsExporter.obj erase CommandsExporter.obj
	if exist AbstractExporter.obj erase AbstractExporter.obj
	if exist CommandListExporter.obj erase CommandListExporter.obj
	if exist FileExporter.obj erase FileExporter.obj
	if exist CommandXmlWriter.obj erase CommandXmlWriter.obj
	if exist AbstractImporter.obj erase AbstractImporter.obj
	if exist CommandListImporter.obj erase CommandListImporter.obj
	if exist FileImporter.obj erase FileImporter.obj
	if exist CommandXmlReader.obj erase CommandXmlReader.obj
	if exist MainWindow.obj erase MainWindow.obj
	if exist ConfigurationWindow.obj erase ConfigurationWindow.obj
	if exist SequenceDiagram.obj erase SequenceDiagram.obj
	if exist TimingDiagram.obj erase TimingDiagram.obj
	if exist BreakPoints.obj erase BreakPoints.obj
	if exist EventInjection.obj erase EventInjection.obj
	if exist DataViewFilterGeneration.obj erase DataViewFilterGeneration.obj
	if exist DataView.obj erase DataView.obj
	if exist Builder.obj erase Builder.obj
	if exist PlugInLoader.obj erase PlugInLoader.obj
	if exist TargetCommunication.obj erase TargetCommunication.obj
	if exist IdeCommunication.obj erase IdeCommunication.obj
	if exist PlugInLoaderTC.obj erase PlugInLoaderTC.obj
	if exist TestConductorAPI.obj erase TestConductorAPI.obj
	if exist SequenceDiagramToRhapsodyExporter.obj erase SequenceDiagramToRhapsodyExporter.obj
	if exist RemoteControll.obj erase RemoteControll.obj
	if exist LogicLevel.obj erase LogicLevel.obj
	if exist DataTransmission.obj erase DataTransmission.obj
	if exist DataParser.obj erase DataParser.obj
	if exist ParserInterface.obj erase ParserInterface.obj
	if exist Logging.obj erase Logging.obj
	if exist DataContainer.obj erase DataContainer.obj
	if exist ReceivedCommands.obj erase ReceivedCommands.obj
	if exist Filter.obj erase Filter.obj
	if exist Adapter.obj erase Adapter.obj
	if exist KeyValueAdapter.obj erase KeyValueAdapter.obj
	if exist StringAdapter.obj erase StringAdapter.obj
	if exist Exporter.obj erase Exporter.obj
	if exist Importer.obj erase Importer.obj
	if exist RunTime.obj erase RunTime.obj
	if exist $(TARGET_MAIN)$(OBJ_EXT) erase $(TARGET_MAIN)$(OBJ_EXT)
	if exist *$(OBJ_EXT) erase *$(OBJ_EXT)
	if exist $(TARGET_NAME).pdb erase $(TARGET_NAME).pdb
	if exist $(TARGET_NAME)$(LIB_EXT) erase $(TARGET_NAME)$(LIB_EXT)
	if exist $(TARGET_NAME).ilk erase $(TARGET_NAME).ilk
	if exist $(TARGET_NAME)$(EXE_EXT) erase $(TARGET_NAME)$(EXE_EXT)
	if exist $(TARGET_NAME)$(EXE_EXT).manifest erase $(TARGET_NAME)$(EXE_EXT).manifest
	$(CLEAN_OBJ_DIR)
	
