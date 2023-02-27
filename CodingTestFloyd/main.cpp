#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

//#define inf 1987654321
//int res[3][201];
//struct Node {
//    vector<pair<int, int>> next;
//};
//
//void dij(int idx, int n, int start) {
//    res[idx][start] = 0;
//    priority_queue<pair<int, int>> pq;
//    pq.push({ -0, start });
//    for (int i = 1; i <= n; i++) res[idx][i] = inf;
//    while (!pq.empty()) {
//        auto cur = pq.top();
//        pq.pop();
//        if (res[idx][cur.second] != inf) continue;
//        int cost = -cur.first;
//        res[idx][cur.second] = cost;
//        for (int i = 0; i < node[cur.second].next.size(); i++) {
//            auto next = node[cur.second].next[i];
//            if (res[idx][next.second] != inf) continue;
//            pq.push({ -(cost + next.first), next.second });
//        }
//    }
//}

void floyd(const int nNodeCount, vector<vector<int>>& table)
{
	// ������ index
	for (int k = 1; k <= nNodeCount; k++) 
	{
		// �����
		for (int i = 1; i <= nNodeCount; i++)
		{
			// ������
			for (int j = 1; j <= nNodeCount; j++)
			{

				if (table[i][k] + table[k][j] < table[i][j]) {
					table[i][j] = table[i][k] + table[k][j];
					table[j][i] = table[i][k] + table[k][j];
				}
			}
		}
	}
}

#define INF 9999999

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {

    int answer = INF;

    vector<vector<int>> dist(n + 1, vector<int>(n + 1, INF));
    //�ʱ�ȭ
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) {
                dist[i][j] = 0;
            }
            else {
                dist[i][j] = INF;
            }
        }
    }

    for (int i = 0; i < fares.size(); i++) {
        dist[fares[i][0]][fares[i][1]] = fares[i][2];
        dist[fares[i][1]][fares[i][0]] = fares[i][2];
    }

    floyd(n, dist);

	for (int i = 1; i <= n; i++) {
		//i: A�� B�� �ս��� ������ ����
		if (dist[s][i] + dist[i][a] + dist[i][b] < answer) {
			answer = dist[s][i] + dist[i][a] + dist[i][b];
		}
	}
    return answer;
}

int main()
{
    vector<vector<int>> fares = { {4, 1, 10} ,{3, 5, 24},{5, 6, 2},{3, 1, 41},{5, 1, 24},{4, 6, 50},{2, 4, 66},{2, 3, 22},{1, 6, 25} };
    int n = 6;
    int s = 4;
    int a = 6;
    int b = 2;

    int res = solution(n, s, a, b, fares);

    cout << "result: " << res << endl;
}