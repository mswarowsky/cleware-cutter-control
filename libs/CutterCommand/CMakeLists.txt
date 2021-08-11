set(LIB_SOURCES CutterCommand.cpp OnCutterCommand.cpp OffCutterCommand.cpp ToggleCutterCommand.cpp ResetCutterCommand.cpp)
set(HEADERS ${HEADERS} CutterCommand.h OnCutterCommand.h OffCutterCommand.h ToggleCutterCommand.h ResetCutterCommand.h)



add_library(CutterCommand STATIC ${LIB_SOURCES} ${HEADERS})