set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_subdirectory(MinimalModule)
add_subdirectory(MyModule)
add_subdirectory(ClosestPoint)
add_subdirectory(GetXYZCoordinates)
add_subdirectory(ConvertPixelToMeter)
<<<<<<< HEAD
add_subdirectory(MvmntDetChooser)
add_subdirectory(StateHandler)
=======
add_subdirectory(discovery_MvmntDetChooser)
add_subdirectory(small_MvmntDetChooser)
add_subdirectory(LookAway)
>>>>>>> b3c40fd5fbd6ec2b5f330f2b8c86c1b947690b31

set(SOURCE ${SOURCE} PARENT_SCOPE)
set(MODULES_INCLUDS ${MODULES_INCLUDS} PARENT_SCOPE)
set(MODULES_LIBS ${MODULES_LIBS} PARENT_SCOPE)
