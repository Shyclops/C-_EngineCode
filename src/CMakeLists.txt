# Generated 2017-07-24 09:19:55

cmake_minimum_required(VERSION 2.8.7)
set(TARGET TopMain)
project(${TARGET})

# require location of supporting RTS
if (NOT UMLRTS_ROOT)
  if (DEFINED ENV{UMLRTS_ROOT})
    set(UMLRTS_ROOT $ENV{UMLRTS_ROOT})
  else ()
    set(UMLRTS_ROOT /home/cwon/Papyrus-RT/plugins/org.eclipse.papyrusrt.rts_0.9.0.201703230413/umlrts)
  endif ()
endif ()

# setup primary envars - provides tooling config
include(${UMLRTS_ROOT}/build/buildenv.cmake)

# model sources
set(SRCS TopMain.cc Directions.cc PreExecute.cc TestCont.cc Detection.cc Calculation.cc Test.cc Observation.cc Observer.cc Top.cc TopControllers.cc Method.cc Config.cc Serializer.cc Event.cc Socket.cc Text.cc ClientSocket.cc )

# specify target
add_executable(${TARGET} ${SRCS})

# setup lib dependency support after defining TARGET
include(${UMLRTS_ROOT}/build/rtslib.cmake)

# compiler parameters
set_target_properties(${TARGET} PROPERTIES COMPILE_OPTIONS "${COPTS}")
set_target_properties(${TARGET} PROPERTIES COMPILE_DEFINITIONS "${CDEFS}")
include_directories(${INCS})

# linker parameters
set_target_properties(${TARGET} PROPERTIES CMAKE_EXE_LINKER_FLAGS "${LOPTS}")
target_link_libraries(${TARGET} ${LIBS})

