#headers are necessary for automoc to pick them up
set(QNANOPAINTER_SRC
        "${CMAKE_CURRENT_SOURCE_DIR}/qnanopainter/libqnanopainter/qnanoquickitem.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/qnanopainter/libqnanopainter/qnanoquickitempainter.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/qnanopainter/libqnanopainter/qnanopainter.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/qnanopainter/libqnanopainter/qnanocolor.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/qnanopainter/libqnanopainter/qnanolineargradient.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/qnanopainter/libqnanopainter/qnanoimagepattern.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/qnanopainter/libqnanopainter/qnanoimage.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/qnanopainter/libqnanopainter/qnanofont.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/qnanopainter/libqnanopainter/qnanoradialgradient.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/qnanopainter/libqnanopainter/qnanoboxgradient.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/qnanopainter/libqnanopainter/private/qnanobackendgles2.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/qnanopainter/libqnanopainter/private/qnanobackendgles3.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/qnanopainter/libqnanopainter/private/qnanobackendgl2.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/qnanopainter/libqnanopainter/private/qnanobackendgl3.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/qnanopainter/libqnanopainter/nanovg/nanovg.c"
        CACHE INTERNAL "" FORCE)


set(QNANOPAINTER_HDR
        "${CMAKE_CURRENT_SOURCE_DIR}/qnanopainter/libqnanopainter/qnanoboxgradient.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/qnanopainter/libqnanopainter/qnanocolor.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/qnanopainter/libqnanopainter/qnanofont.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/qnanopainter/libqnanopainter/qnanoimage.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/qnanopainter/libqnanopainter/qnanoimagepattern.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/qnanopainter/libqnanopainter/qnanolineargradient.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/qnanopainter/libqnanopainter/qnanopainter.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/qnanopainter/libqnanopainter/qnanoquickitem.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/qnanopainter/libqnanopainter/qnanoquickitempainter.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/qnanopainter/libqnanopainter/qnanoradialgradient.h"
        CACHE INTERNAL "" FORCE)
