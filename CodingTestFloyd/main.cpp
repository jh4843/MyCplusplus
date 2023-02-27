#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int floyd(const int nNodeCount, vector<vector<int>>& table)
{
	// 경유지 index
	for (int k = 0; k < nNodeCount; k++) 
	{
		// 출발지
		for (int i = 0; i < nNodeCount; i++)
		{
			// 도착지
			for (int j = 0; j < nNodeCount; j++)
			{
				int temp = table[i][k] + table[k][j];
				if (temp < table[i][j])
					table[i][j] = temp;
			}
		}
	}
}

int solution(vector<string> maps) {
    
}

int main()
{
    vector<string> maps = { "SOOOL", "XXXXO", "OOOOO", "OXXXX", "OOOOE" };

    int n = solution(maps);

    cout << "result: " << n << endl;
}