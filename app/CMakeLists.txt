find_package(protobuf CONFIG REQUIRED)
find_package( Boost REQUIRED COMPONENTS program_options regex log log_setup)
set(SOURCES
    "src/messaging_thread.cpp"
    "src/event_queue.cpp"
    "src/message_bus.cpp"
    "src/test_comp.cpp"
    "src/global_logger.cpp"
    "src/tcp_listener.cpp"
    "src/mac_global_listener.cpp"
    "src/mac_robot_impl.cpp"
    "src/recorder.cpp"
    "src/playback.cpp"
)
add_library(app_lib STATIC ${SOURCES})

#target_link_libraries(proto-objects PUBLIC protobuf::libprotobuf)

set(PROTO_BINARY_DIR "${CMAKE_CURRENT_BINARY_DIR}")

target_include_directories(app_lib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" ${Boost_INCLUDE_DIRS})

add_executable(my_app
    "src/main.cpp"
)
target_link_libraries(my_app app_lib "-framework ApplicationServices" "-framework CoreFoundation")
