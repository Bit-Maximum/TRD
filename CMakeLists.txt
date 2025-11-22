cmake_minimum_required(VERSION 3.28)
project(TRD)

set(CMAKE_CXX_STANDARD 17)

add_executable(TRD main.cpp
        Graphs/dijkstra.cpp
        Flows/minMaxCostFlow.cpp
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
        Math/gcd.cpp
        Strings/prefixFunction.cpp
        Strings/zFunction.cpp
        Strings/ahoCorasick.cpp
        Strings/suffixAutomaton.cpp
        Strings/suffixArray.cpp
        Strings/manachersAlgorithm.cpp
        Strings/eertree.cpp
        "Geometry/geometryTemplate .cpp"
        Geometry/circleLineIntersections.cpp
        Geometry/tangentsBetweenCircles.cpp
        Geometry/halfPlaneIntersection.cpp
        Geometry/convexHull.cpp
        Geometry/3DConvexHull.cpp
        Geometry/SmallestEnclosingCircleOrSphere.cpp
        Geometry/dynamicConvexHull.cpp
        Math/fastWaveletTransform.cpp
        Math/floorSum.cpp
        Math/squareRootModulo.cpp
        "Math/ sumOverSubmasks.cpp"
        Math/countPrimes.cpp
        Math/simplexAlgorithm.cpp
        "DataStructures/ convexHullTrickOnMAX.cpp"
        DataStructures/onlineConvexHullTrickOnMAX.cpp
        DataStructures/fenwickLowerBound.cpp
        DataStructures/heavyLightDecomposition.cpp
        DataStructures/rangeChminChmaxAddRangeSum.cpp
        DataStructures/fenwickTree.cpp
        DataStructures/minimalOnQueueInLinearTime.cpp
        DataStructures/linkCutTree.cpp
        Graphs/longestCommonSubsequence.cpp
        Sorting/MOsAlgoSorting.cpp
        Math/moduloMult.cpp
        Miscellaneous/fastIntegerIO.cpp
        Hashs/robinCarp.cpp
        Hashs/numberOfDistinctSubstrings.cpp
        Strings/maineLorenz.cpp
        NumberTheory/ternarySearch.cpp
        NumberTheory/binomialCoefficients.cpp
        NumberTheory/relativelyPrimeNumbers.cpp
)
