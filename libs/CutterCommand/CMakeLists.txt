set(LIB_SOURCES CutterCommand.cpp OnCutterCommand.cpp OffCutterCommand.cpp ToggleCutterCommand.cpp ResetCutterCommand.cpp CutterCommandFactory.cpp)
set(HEADERS ${HEADERS} CutterCommand.h OnCutterCommand.h OffCutterCommand.h ToggleCutterCommand.h ResetCutterCommand.h CutterCommandFactory.h)



add_library(CutterCommand STATIC ${LIB_SOURCES} ${HEADERS})
target_link_libraries(CutterCommand USBaccess)