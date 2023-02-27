#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <sstream>


using namespace std;

/*
// 문자열 압축
#pragma region CompressString
vector<string> convert(string s, int n)
{
    vector<string> v;
    for (int i = 0; i < s.length(); i += n)
    {
        v.push_back(s.substr(i, n));
    }
    return v;
}

int solution_1(string s) {
    int answer = 0;
    vector<string> tok;
    string before;
    int cnt = 1;
    int min = s.length();
    string str = "";
    for (int j = 1; j <= s.length() / 2; j++)
    {
        tok = convert(s, j);
        str = "";
        before = tok[0];
        cnt = 1;
        for (int i = 1; i < tok.size(); i++)
        {
            if (tok[i] == before) cnt++;
            else
            {
                if (cnt != 1) str += to_string(cnt);
                str += before;
                before = tok[i];
                cnt = 1;
            }
        }
        if (cnt != 1)str += to_string(cnt);
        str += before;
        min = min < str.length() ? min : str.length();
    }
    cout << str;

    return min;
}
#pragma endregion
*/

// 개인정보 수집 유효기간
#pragma region PrivacyInfoValidDate

bool cmpReverseInt(int a, int b) {
    return a > b;
}

vector<string> split(string str, char Delimiter) {
    istringstream iss(str);             // istringstream에 str을 담는다.
    string buffer;                      // 구분자를 기준으로 절삭된 문자열이 담겨지는 버퍼

    vector<string> result;

    // istringstream은 istream을 상속받으므로 getline을 사용할 수 있다.
    while (getline(iss, buffer, Delimiter)) {
        result.push_back(buffer);               // 절삭된 문자열을 vector에 저장
    }

    return result;
}

int totalDate(string strDate) {
    vector<string> vTodayDate = split(strDate, '.');

    int nSumDate = 0;

    if (vTodayDate.size() < 3) {
        cout << "invalid Date " << vTodayDate.size() << endl;
        return -1;
    }

    int nYear = std::stoi(vTodayDate[0]) * 28 * 12;
    int nMonth = std::stoi(vTodayDate[1]) * 28;
    int nDay = std::stoi(vTodayDate[2]);

    nSumDate = nYear + nMonth + nDay;

    return nSumDate;
}

class Terms {

public:
    char cPrivacyGroup;    // 약관 종류
    int nDate; // nExpired month;

public:
    Terms(string _term) {
        vector<string> v = split(_term, ' ');
        this->cPrivacyGroup = *v[0].c_str();
        this->nDate = std::stoi(v[1]) * 28;
    }
};

class Privacy {

public:
    int nIndex;
    int nStartDate;     
    char cPrivacyGroup;    // 약관 종류

public:
    Privacy(int _index,  string _privacy) {
        this->nIndex = _index;
        vector<string> v = split(_privacy, ' ');
        this->nStartDate = totalDate(v[0]);
        this->cPrivacyGroup = *v[1].c_str();
    }

    bool isPrivacyGroup(Terms* _t) {
        if (this->cPrivacyGroup == _t->cPrivacyGroup) {
            return true;
        }

        return false;
    }
};

vector<int> solution_2(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    answer.clear();

    vector<string> vTodayDate = split(today, '.');

    int nTodayDate = totalDate(today);

    cout << "temp Result: " << nTodayDate << endl;

    vector<Terms*> vTerms;
    vTerms.clear();

    for (int i = 0; i < terms.size(); i++) {
        vTerms.push_back(new Terms(terms[i]));
    }

    vector<Privacy*> vPrivacies;
    vPrivacies.clear();

    for (int i = 0; i < privacies.size(); i++) {
        vPrivacies.emplace_back(new Privacy(i+1, privacies[i]));
    }

    for (auto& privacy : vPrivacies) {
        for (auto &term: vTerms) {
            if (privacy->isPrivacyGroup(term)) {
                if (nTodayDate - privacy->nStartDate >= term->nDate) {
                    answer.push_back(privacy->nIndex);
                }
                break;
            }
        }
    }

    
    //sort(answer.begin(), answer.end(), cmpReverseInt);
    sort(answer.begin(), answer.end());

    return answer;
}
#pragma endregion

// 개인정보 수집 유효기간
#pragma region KeyAndLock
vector<vector<int>> rotate_90_cw(vector<vector<int>> graph, int nSize) {

    // 회전된 배열을 저장하고 return하는 벡터
    vector<vector<int>> newGraph(nSize, vector<int>(nSize, 0));

    for (int i = 0; i < nSize; i++) {
        for (int j = 0; j < nSize; j++) {
            // 시계방향 90도
            newGraph[i][j] = graph[nSize - j - 1][i];
        }
    }

    return newGraph;

}

vector<vector<int>> rotate_90_ccw(vector<vector<int>> graph, int nSize) {

    // 회전된 배열을 저장하고 return하는 벡터
    vector<vector<int>> newGraph(nSize, vector<int>(nSize, 0));

    for (int i = 0; i < nSize; i++) {
        for (int j = 0; j < nSize; j++) {
            // 반시계방향 90도
            newGraph[i][j] = graph[j][nSize - j - 1];
        }
    }

    return newGraph;

}

bool solution_3(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = true;

    int n = lock.size();
    int m = key.size();



    int nMaxSize = max(m, n * 2);
    nMaxSize = min(nMaxSize, 20);

    vector<vector<int>> resKey(nMaxSize, vector<int>(nMaxSize, 0));
    vector<vector<int>> answerKey(nMaxSize, vector<int>(nMaxSize, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (lock[i][j] == 0) {
                answerKey[i][j] = 1;
            }
        }
    }

    int move_i = 0;
    int move_j = 0;

    int ii = 0;
    int jj = 0;

    vector<vector<int>> rotatedKey = key;

    for (int r = 0; r < 3; r++) {
        for (int move_i = 0; move_i < nMaxSize - m; move_i++) {
            for (int move_j = 0; move_j < nMaxSize - m; move_j++) {
                resKey = vector<vector<int>>(nMaxSize, vector<int>(nMaxSize, 0));

                for (int i = 0; i < m; i++)
                {
                    for (int j = 0; j < m; j++)
                    {
                        ii = i + move_i;
                        jj = j + move_j;
                        if (ii >= nMaxSize || jj >= nMaxSize)
                            continue;

                        if (rotatedKey[i][j] == 1) {

                            if (ii>= n || jj >= n) {
                                resKey[ii][jj] = 0;
                            }
                            else {
                                resKey[ii][jj] = 1;
                            }
                        }
                    }
                }

                if (answerKey == resKey)
                    return true;
            }
        }



        for (int move_x = 0; move_x > (nMaxSize* -1) + m; move_x--) {
            for (int move_y = 0; move_y > (nMaxSize*-1) + m; move_y--) {
                resKey = vector<vector<int>>(nMaxSize, vector<int>(nMaxSize, 0));

                for (int i = 0; i < m; i++)
                {
                    for (int j = 0; j < m; j++)
                    {
                        ii = i + move_x;
                        jj = j + move_y;
                        if (ii >= nMaxSize || jj >= nMaxSize || ii < 0 || jj < 0)
                            continue;

                        if (rotatedKey[i][j] == 1) {

                            if (ii >= n || jj >= n) {
                                resKey[ii][jj] = 0;
                            }
                            else {
                                resKey[ii][jj] = 1;
                            }
                        }
                    }
                }

                if (answerKey == resKey)
                    return true;
            }
        }

        rotatedKey = rotate_90_cw(key, key.size());
    }

    for (int r = 0; r < 3; r++) {
        for (int move_x = 0; move_x < nMaxSize - m; move_x++) {
            for (int move_y = 0; move_y < nMaxSize - m; move_y++) {
                resKey = vector<vector<int>>(nMaxSize, vector<int>(nMaxSize, 0));

                for (int i = 0; i < m; i++)
                {
                    for (int j = 0; j < m; j++)
                    {
                        ii = i + move_x;
                        jj = j + move_y;
                        if (ii >= nMaxSize || jj >= nMaxSize)
                            continue;

                        if (rotatedKey[i][j] == 1) {

                            if (ii >= n || jj >= n) {
                                resKey[ii][jj] = 0;
                            }
                            else {
                                resKey[ii][jj] = 1;
                            }
                        }
                    }
                }

                if (answerKey == resKey)
                    return true;
            }
        }



        for (int move_x = 0; move_x > (nMaxSize * -1) + m; move_x--) {
            for (int move_y = 0; move_y > (nMaxSize * -1) + m; move_y--) {
                resKey = vector<vector<int>>(nMaxSize, vector<int>(nMaxSize, 0));

                for (int i = 0; i < m; i++)
                {
                    for (int j = 0; j < m; j++)
                    {
                        ii = i + move_x;
                        jj = j + move_y;
                        if (ii >= nMaxSize || jj >= nMaxSize || ii < 0 || jj < 0)
                            continue;

                        if (rotatedKey[i][j] == 1) {

                            if (ii >= n || jj >= n) {
                                resKey[ii][jj] = 0;
                            }
                            else {
                                resKey[ii][jj] = 1;
                            }
                        }
                    }
                }

                if (answerKey == resKey)
                    return true;
            }
        }

        rotatedKey = rotate_90_ccw(key, key.size());
    }

    return false;
}
#pragma endregion

#pragma region RobotMoving

class myRobotPos
{

public:
    int h_i = 1;
    int h_j = 2;
    int t_i = 1;
    int t_j = 1;

    int t = 0;

    myRobotPos(int _h_i, int _h_j, int _t_i, int _t_j)
    {
        set(_h_i, _h_j, _t_i, _t_j);
    }

    void set(int _h_i, int _h_j, int _t_i, int _t_j)
    {
        h_i = _h_i;
        h_j = _h_j;
        t_i = _t_i;
        t_j = _t_j;
    }

    void increase()
    {
        t++;
    }

    myRobotPos& operator++()
    {
        t++;
        return *this;
    }

    bool operator==(const myRobotPos& x) const
    {
        if (h_i == x.h_i && h_j == x.h_j && t_i == x.t_i && t_j == x.t_j) {
            return true;
        }

        return false;
    }

};

int solution_4(vector<vector<int>> board) {
    int answer = 0;

    return answer;
}
#pragma endregion



const int NUM = 27;

int toNumber(char n) {
    if (n == '?')
    {
        return 26;
    }

    return n - 'a';
}

struct TrieNode
{
    TrieNode* children[NUM];
    bool terminal;
    int cnt;

    TrieNode() :terminal(false), cnt(0)
    {
        for (int i = 0; i < NUM; ++i)
        {
            children[i] = NULL;
        }
    }

    ~TrieNode()
    {
        for (int i = 0; i < NUM; i++)
        {
            if (children[i])
            {
                delete children[i];
            }
        }
    }

    void insert(const char* key)
    {
        //키값이 널이라면
        if (*key == 0)
        {
            terminal = true;
        }
        else
        {
            int next = toNumber(*key);
            if (children[next] == NULL)
            {
                children[next] = new TrieNode();
            }

            children[next]->insert(key + 1);
        }
    }

    void find(const char* key)
    {
        if (*key == 0)
        {
            cnt++;
            return;
        }

        int next = toNumber(*key);
        if (children[toNumber('?')] != NULL)
        {
            children[toNumber('?')]->find(key + 1);
        }

        if (children[next] != NULL)
        {
            children[next]->find(key + 1);
        }
    }

    int getCnt(const char* key)
    {
        if (*key == 0)
        {
            return cnt;
        }

        int next = toNumber(*key);
        if (children[next] == NULL)
        {
            return 0;
        }

        return children[next]->getCnt(key + 1);
    }
};

vector<int> solution_5(vector<string> words, vector<string> queries) {
    vector<int> answer;
    TrieNode trie;

    for (int i = 0; i < queries.size(); ++i)
    {
        trie.insert(queries[i].c_str());
    }

    for (int i = 0; i < words.size(); ++i)
    {
        trie.find(words[i].c_str());
    }

    for (int i = 0; i < queries.size(); ++i)
    {
        answer.push_back(trie.getCnt(queries[i].c_str()));
    }

    return answer;
}

int main()
{
    // 문자열 압축
    // int n = solution_1("ababcdcdababcdcd");
    // cout << "result: " << n << endl;

    // 개인정보 수집 유효기간
    //vector<string> terms = { "A 6", "B 12", "C 3" };
    //vector<string> privacies = { "2021.05.02 A", "2021.07.01 B", "2022.02.19 C", "2022.02.20 C" };

    //vector<int> res = solution("2022.05.19", terms, privacies);

    //for (auto& a : res) {
    //    cout << "result: " << a << endl;
    //}

    //vector<string> terms2 = { "Z 3", "D 5" };
    //vector<string> privacies2 = { "2019.01.01 D", "2019.11.15 Z", "2019.08.02 D", "2019.07.01 D", "2018.12.28 Z" };

    //vector<int> res2 = solution_2("2020.01.01", terms2, privacies2);
    
    //for (auto& a : res2) {
    //    cout << "result2: " << a << endl;
    //}
    //

    // 자물쇠와 열쇠
    //vector<vector<int>> key = { {0, 0, 0} ,{1, 0, 0},{0, 1, 1} };
    //vector<vector<int>> lock = { {1, 1, 1}, {1, 1, 0}, {1, 0, 1} };
    //int res = solution_3(key, lock);
    //cout << "result: " << res << endl;

    // 로봇 무빙
    //vector<vector<int>> board = { {0, 0, 0, 1, 1}, {0, 0, 0, 1, 0}, {0, 1, 0, 1, 1}, {1, 1, 0, 0, 1}, {0, 0, 0, 0, 0} };
    //int res = solution_4(board);
    //cout << "result: " << res << endl;

    //
    vector<string> words = { "frodo", "front", "frost", "frozen", "frame", "kakao" };
    vector<string> queries = { "fro??", "????o", "fr???", "fro???", "pro?" };
    vector<int> res3 = solution_5(words, queries);

    for (auto& a : res3) {
        std::cout << "result4: " << a << endl;
    }
}

