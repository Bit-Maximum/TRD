#include <iostream>
#include <queue>
#include <string.h>
// #include <vector>
//
// using namespace std;
//
//
// struct edg {
//     int pos, cap, rev, cost;
// };
//
// const int MAXN = 100;
// int dist[MAXN], pa[MAXN], pe[MAXN];
// bool inque[MAXN];
// vector<edg> gph[MAXN];
//
// void clear()
// {
//     for (int i=0; i<MAXN; i++)
//         gph[i].clear();
// }
//
// void add_edge(int s, int e, int x, int c){
//     gph[s].push_back({e, x, (int)gph[e].size(), c});
//     gph[e].push_back({s, 0, (int)gph[s].size()-1,-c});
// }
//
// bool spfa(int src, int sink){
//     memset(dist, 0x3f, sizeof(dist));
//     memset(inque, 0, sizeof(inque));
//     queue<int> que;
//
//     dist[src] = 0;
//     inque[src] = true;
//     que.push(src);
//     bool ok = false;
//
//     while(!que.empty()) {
//         int x = que.front();
//         que.pop();
//         if(x == sink)
//             ok = true;
//
//         inque[x] = false;
//         for(int i = 0; i < gph[x].size(); i++){
//             edg e = gph[x][i];
//             if(e.cap > 0 && dist[e.pos] > dist[x] + e.cost){
//                 dist[e.pos] = dist[x] + e.cost;
//                 pa[e.pos] = x;
//                 pe[e.pos] = i;
//                 if(!inque[e.pos]){
//                     inque[e.pos] = true;
//                     que.push(e.pos);
//                 }
//             }
//         }
//     }
//     return ok;
// }
//
//
// // int match(int src, int sink){
// //     int ret = 0;
// //     while(spfa(src, sink)){
// //         int cap = 1e9;
// //         for(int pos = sink; pos != src; pos = pa[pos]){
// //             cap = min(cap, gph[pa[pos]][pe[pos]].cap);
// //         }
// //         if (ret += dist[sink])
// //         ret += dist[sink] * cap;
// //         for(int pos = sink; pos != src; pos = pa[pos]){
// //             int rev = gph[pa[pos]][pe[pos]].rev;
// //             gph[pa[pos]][pe[pos]].cap-= cap;
// //             gph[pos][rev].cap += cap;
// //         }
// //     }
// //     return ret;
// // }
//
//
// // int main(const int argc, const char *argv[])
// // {
// //     int n, m, k;
// //     cin >> n >> m >> k;
// //
// //     clear();
// //
// //     for (int i = 0; i < m; i++) {
// //         int a, b, r, c;
// //         cin >> a >> b >> r >> c;
// //         add_edge(a - 1, b - 1, r, c);
// //     }
// //
// //     int result = match(0, n - 1);  // Отправка потока от города 1 (Syrjälä) к городу n (Lehmälä)
// //
// //     // Если поток не равен k, значит, решение не найдено
// //     if (result == -1) {
// //         cout << -1 << endl;
// //     } else {
// //         cout << result << endl;
// //     }
// //
// //     return 0;
// }