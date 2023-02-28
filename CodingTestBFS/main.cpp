#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX_STATE 17
using namespace std;
struct Point {
	int cur, ship, wolves, state;
};
vector<int> adj[20];
vector<int> Info;

//�̹� �湮�� ��嵵 ���°� �ٸ��ٸ� �湮�ϵ�, ���̳� ������ ���ڰ� �þ�� �ʴ´�.
bool visited[17][1 << MAX_STATE];
int bfs() {
	queue<Point> q;
	q.push({ 0,1,0,1 });
	visited[0][1] = true;
	int ret = 0;

	while (!q.empty()) {
		Point curr = q.front(); q.pop();
		ret = max(ret, curr.ship);

		for (int next : adj[curr.cur]) {
			int ns = 0;
			int nw = 0;
			if (!Info[next] && !(curr.state & (1 << next))) ns = 1;
			if (Info[next] && !(curr.state & (1 << next))) nw = 1;
			if (Info[next] && curr.ship <= curr.wolves + nw)
				continue;
			int nstate = curr.state | (1 << next);
			if (visited[next][nstate])
				continue;
			visited[next][nstate] = true;
			q.push({ next,curr.ship + ns,curr.wolves + nw,nstate });
		}
	}
	return ret;
}

int number = 9;
int visit[9];
vector<int> a[10];

void bfs(int start) {
	queue<int> q;
	q.push(start);
	visit[start] = true;

	while (!q.empty()) {
		// ť�� ���� ������� ��� �ݺ� ����
		// ť�� ���� �ִ�. => ���� �湮���� ���� ��尡 ���� �Ѵ�. 
		int x = q.front();
		q.pop();
		printf("%d ", x);
		for (int i = 0; i < a[x].size(); i++) {
			int y = a[x][i];
			if (!visit[y]) {
				// �湮���� �ʾҴٸ�..
				q.push(y);
				visit[y] = true;
			}
		}
	}
}

int solution(vector<int> info, vector<vector<int>> edges) {
	Info = info;
	int num = 0;
	for (auto eg : edges) {
		adj[eg[0]].push_back(eg[1]);
		adj[eg[1]].push_back(eg[0]);
	}
	int answer = bfs();
	return answer;
}