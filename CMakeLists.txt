cmake_minimum_required(VERSION 3.28)
project(TRD)

set(CMAKE_CXX_STANDARD 17)

add_executable(TRD main.cpp
        Graphs/dijkstra.cpp
        Floaws/minMaxCostFlow.cpp
        Graphs/articulationPoint.cpp
        Graphs/aStar.cpp
        Graphs/pairwiseDistances.cpp
        Graphs/bridges.cpp
        Graphs/connectedComponents.cpp
        Graphs/strongConnectedConponents.cpp
        Graphs/kuhn.cpp
        Graphs/findCycle.cpp
        Search/bitsearch.cpp
        Search/binsearchByAnswer.cpp
        DataStructures/segregationTree.cpp
        Math/binpow.cpp
        Math/gcd.cpp)
