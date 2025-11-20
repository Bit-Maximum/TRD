// __lg == (63 - __builtin_clzll) get log2 !!! be careful x == 0
// __builtin_ctzll get first one bit
// __builtin_popcountll get number of one bits

//CMAKE: add_definitions(-DONPC)
//CMAKE: set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")

#ifndef ONPC
#define _GLIBCXX_DEBUG
#else
#pragma GCC optimize("O3")
#pragma unroll
#endif

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef ONPC
    freopen("input.txt", "r", stdin);
#endif
    return 0;
}

