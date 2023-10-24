# CMakeList.txt: проект CMake для Word-Table; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

# Включение горячей перезагрузки для компиляторов MSVC, если поддерживается.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

set(WORD_TABLE_INCLUDES
	headers/Table.hpp
  headers/TreeNode.hpp
)

set(WORD_TABLE_SOURCES
  main.cpp
  Table.cpp
  TreeNode.cpp
)

set(WORD_TABLE_ALL_SOURCES
  ${WORD_TABLE_INCLUDES}
  ${WORD_TABLE_SOURCES}
)

project ("Word-Table")

# Добавьте источник в исполняемый файл этого проекта.
add_executable (Word-Table ${WORD_TABLE_ALL_SOURCES})

# Копирование папки
add_custom_command(TARGET ${PROJECT_NAME} PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${PROJECT_SOURCE_DIR}/config/ ${PROJECT_BINARY_DIR}/config/)
        
if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Word-Table PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.