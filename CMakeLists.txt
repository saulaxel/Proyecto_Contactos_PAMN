cmake_minimum_required(VERSION 3.5)

project(Proyecto_Contactos_PAMN)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99 -Wall")

set(SOURCE_FILES
        requerimientos.c
        contrasena.h
        contacto.h)

include_directories(.)

add_library(Lib_Proyecto STATIC
        contrasena.h
        contacto.h)
set_target_properties(Lib_Proyecto
        PROPERTIES LINKER_LANGUAGE C)

add_executable(Codificar requerimientos.c)
add_executable(Decodificar Decodificar_y_Mostrar.c)
target_link_libraries(Codificar Lib_Proyecto)
set_target_properties(Codificar Decodificar PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY "C:\\Users\\Emilio\\Documents\\GitHub\\Proyecto_Contactos_PAMN\\lib"
        LIBRARY_OUTPUT_DIRECTORY "C:\\Users\\Emilio\\Documents\\GitHub\\Proyecto_Contactos_PAMN\\lib"
        RUNTIME_OUTPUT_DIRECTORY "C:\\Users\\Emilio\\Documents\\GitHub\\Proyecto_Contactos_PAMN\\bin")