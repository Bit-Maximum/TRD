#include <iostream>
#include <vector>

using namespace std;

constexpr int MAXINT = 1e9;

vector<int> hungarian(int n, int m, const vector<vector<int>> &a) {
    vector<int> u(n+1), v(m+1), p(m+1), way(m+1), minv(m+1), used(m+1);
    for (int i = 1; i <= n; i++) {
        minv.assign(m+1, MAXINT);
        used.assign(m+1, false);
        p[0] = i;
        int j0 = 0;
        while (p[j0] != 0) {
            used[j0] = true;
            int delta = MAXINT, i0 = p[j0], j1 =-1;
            for (int j = 1; j <= m; j++) {
                if (!used[j]) {
                    int cur = a[i0][j]- u[i0]- v[j];
                    if (cur < minv[j]) {
                        minv[j] = cur;
                        way[j] = j0;
                    }
                    if (minv[j] < delta) {
                        delta = minv[j];
                        j1 = j;
                    }
                }
            }
            for (int j = 0; j <= m; j++) {
                if (used[j]) {
                    u[p[j]] += delta;
                    v[j]-= delta;
                } else {
                    minv[j]-= delta;
                }
            }
            j0 = j1;
        }
        while (j0 != 0) {
            int j1 = way[j0];
            p[j0] = p[j1];
            j0 = j1;
        }
    }
    vector<int> ans(n+1);
    for (int j = 1; j <= m; j++) {
        ans[p[j]] = j;
    }
    ans[0] =-v[0];
    return ans;
}


// int main()
// {
//     int n = 4;
//     int m = 4;
//     vector<vector<int>> v(n, vector<int>(m));
//     v[0] = {25,	51,	145, 15};
//     v[1] = {61,	13,	51,	661};
//     v[2] = {15,	24,	624, 14};
//     v[3] = {525, 342, 62, 62};
//
//     vector<int> res = hungarian(n, m, v);
//     for (auto x : res) {
//         cout << x << ' ';
//     }
//
//     return 0;
// }
