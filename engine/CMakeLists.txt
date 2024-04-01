target_include_directories(main PUBLIC include)
file(GLOB SOURCES "src/*.cpp")
target_sources(main PUBLIC ${SOURCES})