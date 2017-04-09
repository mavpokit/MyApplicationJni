add_library(kotaNative
             SHARED
             src/main/cpp/kotaNative.cpp )

target_link_libraries(kotaNative
                      android
                      log)
