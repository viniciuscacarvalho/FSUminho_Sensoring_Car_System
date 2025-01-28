cmake_minimum_required(VERSION 3.5)

project(Class_codification LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Class_codification main.cpp
    Classes/c_actuator/c_actuator.cpp
    Classes/c_actuator/c_actuator.h
    Classes/c_analog_sensor/c_analog_sensor.cpp
    Classes/c_analog_sensor/c_analog_sensor.h
    Classes/c_analog_to_spi/c_analog_to_spi.cpp
    Classes/c_analog_to_spi/c_analog_to_spi.h
    Classes/c_apps/c_apps.cpp
    Classes/c_apps/c_apps.h
    Classes/c_brake_pressure/c_brake_pressure.cpp
    Classes/c_brake_pressure/c_brake_pressure.h
    Classes/c_digital_sensor/c_digital_sensor.cpp
    Classes/c_digital_sensor/c_digital_sensor.h
    Classes/c_display_interface/c_display_interface.cpp
    Classes/c_display_interface/c_display_interface.h
    Classes/c_lora_interface/c_lora_interface.cpp
    Classes/c_lora_interface/c_lora_interface.h
    Classes/c_main_system/c_main_system.cpp
    Classes/c_main_system/c_main_system.h
    Classes/c_wssensor/c_wssensor.cpp
    Classes/c_wssensor/c_wssensor.h

    Classes/fsUminhoSensoringSystem.h

    Classes/main_libs.h
    Classes/defines.h
    Classes/dummy_spi.h Classes/dummy_spi.cpp

    Classes/datagram.h Classes/datagram.cpp
    thread_behavior/thread_behavior.h
    thread_behavior/lora_comms_thread.cpp
    thread_behavior/main_thread_libs.h
    thread_behavior/update_display_thread.cpp

    thread_behavior/read_analog_sensor_thread.cpp
    thread_behavior/read_digital_sensor_thread.cpp

    thread_behavior/action_thread.cpp
    thread_behavior/lora_connection_thread.cpp
    thread_behavior/thread_variables.cpp
    thread_behavior/thread_defines.h
    shared_memory/shared_memory.cpp

    shared_memory/shared_memory.h

    shared_memory/shm_defines.h
    error_handling/error_handling.cpp
    error_handling/error_handling.h
    shared_memory/shm_variables.cpp
    error_handling/error_list.h
    spi/spi_code.cpp
    spi/spi_code.h
    spi/spi_variables.cpp
    spi/spi_defines.h

    signals/signal_behabvior.cpp signals/signal_handlers.h
    wss_isr/wss_isr.cpp
    wss_isr/wss_ist.h


)

link_directories(/home/viny/buildroot/buildroot-2024.11/output/host/aarch64-buildroot-linux-gnu/sysroot/usr/lib)

target_link_libraries(Class_codification
  PRIVATE wiringPi)

include(GNUInstallDirs)
install(TARGETS Class_codification
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

