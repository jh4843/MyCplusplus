#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

class myPoint
{

public:
    int i = -1;
    int j = -1;

    char v = ' ';

    myPoint(int _i, int _j) 
    {
        i = _i;
        j = _j;
    }

    void set(int _i, int _j)
    {
        i = _i;
        j = _j;
    }

    void setVal(char _v)
    {
        v = _v;
    }

    bool operator==(const myPoint& x) const
    {
        if (i == x.i && j == x.j) {
            return true;
        }

        return false;
    }

};

bool isValid(int n) {
    if (n < 0)
        return false;

    if (n > 100)
        return false;

    return true;
}

int dfs(const myPoint start, const myPoint end, const vector<string>& maps)
{
    const int n = maps.size();
    const int m = maps[0].size();

    myPoint a(1, 0);
    myPoint b(-1, 0);
    myPoint c(0, 1);
    myPoint d(0, -1);

    const vector<myPoint> offset = {a, b, c, d};

    queue<pair<myPoint, int>> q;
    q.emplace(start, 0);

    vector<vector<bool>> visited(n, vector<bool>(m, false));

    while (!q.empty())
    {
        const myPoint cur = q.front().first;
        const int i = cur.i;
        const int j = cur.j;
        const int distCur = q.front().second;
        q.pop();

        if (cur == end)
        {
            return distCur;
        }

        if (!visited[i][j])
        {
            visited[i][j] = true;
            for (const auto& o : offset)
            {
                const int ii = i + o.i;
                const int jj = j + o.j;

                if (ii >= 0 && ii < n && jj >= 0 && jj < m && maps[ii][jj] != 'X')
                {
                    q.emplace(make_pair(myPoint( ii,jj ), distCur + 1));
                }
            }
        }
    }
   return -1;
}

int solution(vector<string> maps) {
    myPoint start(-1, -1);
    myPoint end(-1, -1);
    myPoint lever(-1, -1);
    int found = 0;
    for (int i = 0; i < maps.size(); ++i)
    {
        for (int j = 0; j < maps[0].size(); ++j)
        {
            if (maps[i][j] == 'S')
            {
                start.set( i,j );
                start.setVal('S');
                found++;
            }
            else if (maps[i][j] == 'E')
            {
                end.set(i, j);
                end.setVal('E');
                found++;
            }
            else if (maps[i][j] == 'L')
            {
                lever.set(i, j);
                lever.setVal('L');
                found++;
            }

            if (found == 3)
            {
                break;
            }
        }

        if (found == 3)
        {
            break;
        }
    }

    int StoL = dfs(start, lever, maps);

    if (StoL != -1)
    {
        int LtoE = dfs(lever, end, maps);

        if (LtoE != -1)
        {
            return StoL + LtoE;
        }
    }

    return -1;
}

int main() 
{
    vector<string> maps = { "SOOOL", "XXXXO", "OOOOO", "OXXXX", "OOOOE" };

    int n = solution(maps);

    cout << "result: " << n << endl;
}