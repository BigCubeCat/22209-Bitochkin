project(Kernel)

set(SOURCE_LIB
        Life/Life.cpp
        Life/Life.h
        Life/Arena.cpp
        Life/Arena.h

        types/TNeighborhood.cpp
        types/TNeighborhood.h

        types/TRules.cpp
        types/TRules.h
)

add_library(Kernel ${SOURCE_LIB})
