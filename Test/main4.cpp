//#include <iostream>
//#include <vector>
//
//const int INF = 200000 * 2;
//
//using namespace std;
//
//int n, x, y, z, ans = INF;
//int nResNode;
//vector<int> g[INF];
//int start[INF], depth[INF];
//bool visited[INF];
//
//void dfs(int u, int par) {
//    start[u] = 1;
//    depth[u] = 0;
//    for (int v : g[u]) {
//        if (v == par || visited[v]) continue;
//        dfs(v, u);
//        start[u] += start[v];
//        depth[u] += depth[v] + start[v];
//    }
//}
//
//void centroid(int u, int par, int tot, int& node) {
//    int mx = tot - start[u];
//    for (int v : g[u]) {
//        if (v == par || visited[v]) continue;
//        centroid(v, u, tot, node);
//        mx = max(mx, start[v]);
//    }
//    if (mx < node) {
//        node = mx;
//        nResNode = u;
//    }
//}
//
//int get_centroid(int u) {
//    dfs(u, -1);
//    int node = INF;
//    centroid(u, -1, start[u], node);
//    return nResNode;
//}