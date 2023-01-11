# Gather the source files.
file(GLOB GAME_SOURCES main.cpp
                       systems/*.cpp)

# Create the executable using the source files.
add_executable(foolsErrand ${GAME_SOURCES})

# Link the executable with Kuma3D.
target_link_libraries(foolsErrand PUBLIC
                      ${KUMA3D_LIBRARY})

# Include the project and Kuma3D headers.
target_include_directories(foolsErrand PUBLIC
                           ${KUMA3D_INCLUDE_DIR}
                           components
                           systems)

# Install the executable and the necessary resources.
install(TARGETS foolsErrand DESTINATION ${INSTALL_DIR})
install(DIRECTORY resources DESTINATION ${INSTALL_DIR})
