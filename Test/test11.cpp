//#include <vector>
//#include <iostream>
//
//using namespace std;
//
//const int MAXNODE = 200005;
//const long long INF = 1e18;
//
//vector<pair<int, int>> vNodes[MAXNODE];
//int n, x, y, z;
//long long lDistX[MAXNODE], lDistY[MAXNODE], lDistZ[MAXNODE], lRes = INF, lResNode;
//
//void dfs(int from, int p, long long* pDist) {
//    for (auto node : vNodes[from]) {
//        if (node.first == p) continue;
//        pDist[node.first] = pDist[from] + node.second;
//        dfs(node.first, from, pDist);
//    }
//}
//
//void solve(int from, int p) {
//    long long sum = lDistX[from] + lDistY[from] + lDistZ[from];
//    if (sum < lRes || (sum == lRes && from < lResNode)) {
//        lRes = sum;
//        lResNode = from;
//    }
//    for (auto node : vNodes[from]) {
//        if (node.first == p) continue;
//        long long w = node.second;
//        long long delta1 = lDistX[node.first] - lDistX[from] + w;
//        long long delta2 = lDistY[node.first] - lDistY[from] + w;
//        long long delta3 = lDistZ[node.first] - lDistZ[from] + w;
//        long long tmp1 = lDistX[from], tmp2 = lDistY[from], tmp3 = lDistZ[from];
//        lDistX[from] = lDistX[node.first], lDistY[from] = lDistY[node.first], lDistZ[from] = lDistZ[node.first];
//        lDistX[node.first] = tmp1 + delta1, lDistY[node.first] = tmp2, lDistZ[node.first] = tmp3;
//        solve(node.first, from);
//        lDistX[node.first] = lDistX[from], lDistY[node.first] = lDistY[from] + delta2, lDistZ[node.first] = lDistZ[from];
//        solve(node.first, from);
//        lDistX[node.first] = lDistX[from], lDistY[node.first] = lDistY[from], lDistZ[node.first] = lDistZ[from] + delta3;
//        solve(node.first, from);
//        lDistX[from] = tmp1, lDistY[from] = tmp2, lDistZ[from] = tmp3;
//    }
//}
//
//int findCentralNode(int tree_nodes, vector<int> tree_from, vector<int> tree_to, vector<int> tree_weight, int x, int y, int z) {
//    n = tree_nodes;
//    for (int i = 1; i <= n; i++) {
//        vNodes[i].clear();
//        lDistX[i] = lDistY[i] = lDistZ[i] = 0;
//    }
//    for (int i = 0; i < n - 1; i++) {
//        int from = tree_from[i], to = tree_to[i], w = tree_weight[i];
//        vNodes[from].push_back({ to, w });
//        vNodes[to].push_back({ from, w });
//    }
//    dfs(x, 0, lDistX);
//    dfs(y, 0, lDistY);
//    dfs(z, 0, lDistZ);
//    lRes = INF, lResNode = -1;
//    solve(x, 0);
//    solve(y, 0);
//    solve(z, 0);
//    return lResNode;
//}