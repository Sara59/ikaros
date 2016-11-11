set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_subdirectory(MinimalModule)
add_subdirectory(MyModule)
add_subdirectory(ClosestPoint)
add_subdirectory(GetXYZCoordinates)
add_subdirectory(ConvertPixelToMeter)
<<<<<<< HEAD
=======
add_subdirectory(MvmntDetChooser)
>>>>>>> 6f2f9092d2ace2425bb82e785ef7f53120473dcf
add_subdirectory(StateHandler)
add_subdirectory(discovery_MvmntDetChooser)
add_subdirectory(small_MvmntDetChooser)
add_subdirectory(LookAway)
<<<<<<< HEAD
=======
add_subdirectory(FaceMatrix)
>>>>>>> 6f2f9092d2ace2425bb82e785ef7f53120473dcf

set(SOURCE ${SOURCE} PARENT_SCOPE)
set(MODULES_INCLUDS ${MODULES_INCLUDS} PARENT_SCOPE)
set(MODULES_LIBS ${MODULES_LIBS} PARENT_SCOPE)
