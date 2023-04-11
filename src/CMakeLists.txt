project(hello_recipient)

set(AMAX_WASM_OLD_BEHAVIOR "Off")
find_package(amax.cdt)

add_contract( hello_recipient hello_recipient hello_recipient.cpp )
target_include_directories( hello_recipient PUBLIC ${CMAKE_SOURCE_DIR}/../include )
target_ricardian_directory( hello_recipient ${CMAKE_SOURCE_DIR}/../ricardian )