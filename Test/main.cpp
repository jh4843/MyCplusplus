//#include <vector>
//#include <iostream>
//
//using namespace std;
//
//const int MAXNODE = 200000 * 2;
//const long long INF = 987654321;
//
//vector<pair<int, int>> vNodes[MAXNODE];
//long long lDistX[MAXNODE] = { INF, };
//long long lDistY[MAXNODE] = { INF, };
//long long lDistZ[MAXNODE] = { INF, };
//long long lRes = INF;
//long long lResNode = 0;
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
//        long long tmpDistX = lDistX[from];
//        long long tmpDistY = lDistY[from];
//        long long tmpDistZ = lDistZ[from];
//
//        lDistX[from] = lDistX[node.first];
//        lDistY[from] = lDistY[node.first];
//        lDistZ[from] = lDistZ[node.first];
//
//        lDistX[node.first] = tmpDistX + delta1;
//        lDistY[node.first] = tmpDistY;
//        lDistZ[node.first] = tmpDistZ;
//        solve(node.first, from);
//
//        lDistX[node.first] = lDistX[from];
//        lDistY[node.first] = lDistY[from] + delta2;
//        lDistZ[node.first] = lDistZ[from];
//        solve(node.first, from);
//
//        lDistX[node.first] = lDistX[from];
//        lDistY[node.first] = lDistY[from];
//        lDistZ[node.first] = lDistZ[from] + delta3;
//        solve(node.first, from);
//
//        lDistX[from] = tmpDistX;
//        lDistY[from] = tmpDistY;
//        lDistZ[from] = tmpDistZ;
//    }
//}
//
//int findCentralNode(int tree_nodes, vector<int> tree_from, vector<int> tree_to, vector<int> tree_weight, int x, int y, int z) {
//    int n = tree_nodes;
//    for (int i = 1; i <= n; i++) {
//        vNodes[i].clear();
//        lDistX[i] = lDistY[i] = lDistZ[i] = 0;
//    }
//    for (int i = 0; i < n - 1; i++) {
//        int from = tree_from[i];
//        int to = tree_to[i];
//        int w = tree_weight[i];
//        vNodes[from].emplace_back(make_pair( to, w ));
//        vNodes[to].emplace_back(make_pair(from, w ));
//    }
//    dfs(x, 0, lDistX);
//    dfs(y, 0, lDistY);
//    dfs(z, 0, lDistZ);
//
//    cout << lDistX[1] << lDistY[2] << lDistZ[3] << endl;
//
//    lRes = INF, lResNode = -1;
//    solve(x, 0);
//    solve(y, 0);
//    solve(z, 0);
//    return lResNode;
//}
//
//int main() {
//    int nNodes = 5;
//    int edges = 4;
//    int x = 2;
//    int y = 3;
//    int z = 4;
//
//    vector<int> from(edges);
//    vector<int> to(edges);
//    vector<int> weight(edges);
//
//    from.push_back(1);
//    from.push_back(1);
//    from.push_back(2);
//    from.push_back(2);
//
//    to.push_back(2);
//    to.push_back(3);
//    to.push_back(4);
//    to.push_back(5);
//
//    weight.push_back(15);
//    weight.push_back(10);
//    weight.push_back(20);
//    weight.push_back(25);
//
//    int result = findCentralNode(nNodes, from, to , weight, x, y, z);
//
//    cout << result << endl;
//
//    return 0;
//}

///// ####### 1. 
//#include <iostream>
//#include <queue>
//#include <vector>
//
//using namespace std;
//
//int minimizeCost(vector<int> arr) {
//    priority_queue<int, vector<int>, greater<int>> minHeap;
//
//    for (int i = 0; i < arr.size(); i++) {
//        minHeap.push(arr[i]);
//    }
//
//    int totalCost = 0;
//
//    while (minHeap.size() > 1) {
//        int x = minHeap.top();
//        minHeap.pop();
//        int y = minHeap.top();
//        minHeap.pop();
//        int sum = x + y;
//        totalCost += sum;
//        minHeap.push(sum);
//    }
//
//    return totalCost;
//}
//
//int main() {
//    vector<int> arr = { 25, 100, 20 };
//    cout << minimizeCost(arr) << endl;
//    return 0;
//}
//
///// ####### 2. 
//#include <cpprest/http_client.h>
//#include <cpprest/json.h>
//#include <iostream>
//#include <vector>
//#include <unordered_map>
//#include <algorithm>
//
//using namespace std;
//using namespace web;
//using namespace web::http;
//using namespace web::http::client;
//
//struct Article {
//    string title;
//    string story_title;
//    string url;
//    string author;
//    int num_comments;
//};
//
//vector<Article> getArticles(int page) {
//    string url = "https://jsonmock.hackerrank.com/api/articles?page=" + to_string(page);
//    http_client client(url);
//    uri_builder builder;
//    builder.append_query("page", page);
//    return client.request(methods::GET, builder.to_string())
//        .then([](http_response response) -> pplx::task<json::value> {
//        if (response.status_code() == status_codes::OK) {
//            return response.extract_json();
//        }
//    return pplx::task_from_result(json::value());
//            })
//        .then([](json::value json) -> vector<Article> {
//                vector<Article> articles;
//            auto data = json.at("data").as_array();
//            for (auto& record : data) {
//                Article article;
//                article.title = record.at("title").is_null() ? "" : record.at("title").as_string();
//                article.story_title = record.at("story_title").is_null() ? "" : record.at("story_title").as_string();
//                article.url = record.at("url").as_string();
//                article.author = record.at("author").as_string();
//                article.num_comments = record.at("num_comments").is_null() ? 0 : record.at("num_comments").as_integer();
//                articles.push_back(article);
//            }
//            return articles;
//            })
//                .get();
//}
//
//vector<string> topArticles(int limit) {
//    unordered_map<string, int> commentCount;
//    vector<Article> allArticles;
//
//    // Get all articles from all pages
//    int page = 1, total_pages = 1;
//    while (page <= total_pages) {
//        auto articles = getArticles(page);
//        total_pages = stoi(get_articles("/total_pages"));
//        for (auto& article : articles) {
//            if (article.title != "") {
//                allArticles.push_back(article);
//                commentCount[article.title] += article.num_comments;
//            }
//            else if (article.story_title != "") {
//                allArticles.push_back(article);
//                commentCount[article.story_title] += article.num_comments;
//            }
//        }
//        page++;
//    }
//
//    // Sort articles by comment count and then by name
//    sort(allArticles.begin(), allArticles.end(), [](const Article& a, const Article& b) {
//        if (a.num_comments != b.num_comments) {
//            return a.num_comments > b.num_comments;
//        }
//        else {
//            return a.title < b.title;
//        }
//        });
//
//    // Take the top limit articles
//    vector<string> result;
//    for (int i = 0; i < limit && i < allArticles.size(); i++) {
//        string name = allArticles[i].title == "" ? allArticles[i].story_title : allArticles[i].title;
//        result.push_back(name);
//    }
//
//    return result;
//}

///// ####### 3. 
//#include <iostream>
//#include <string>
//#include <unordered_map>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//vector<vector<int>> textQueries(vector<string> sentences, vector<string> queries) {
//    vector<vector<int>> results;
//    unordered_map<string, vector<int>> mapWords;
//    for (int i = 0; i < sentences.size(); i++) {
//        string sentence = sentences[i];
//        size_t nPos = 0;
//        string delimiter = " ";
//        while ((nPos = sentence.find(delimiter)) != string::npos) {
//            string word = sentence.substr(0, nPos);
//            mapWords[word].push_back(i);
//            sentence.erase(0, nPos + delimiter.length());
//        }
//        mapWords[sentence].push_back(i);
//    }
//    for (string query : queries) {
//        size_t nPos = 0;
//        string delimiter = " ";
//        vector<int> vQuerySentenceIndices;
//        while ((nPos = query.find(delimiter)) != string::npos) {
//            string word = query.substr(0, nPos);
//            if (mapWords.count(word) == 0) {
//                vQuerySentenceIndices.clear();
//                break;
//            }
//            else {
//                vector<int> vWordSentenceIndices = mapWords[word];
//                if (vQuerySentenceIndices.empty()) {
//                    vQuerySentenceIndices = vWordSentenceIndices;
//                }
//                else {
//                    vector<int> intersection;
//                    set_intersection(vQuerySentenceIndices.begin(), vQuerySentenceIndices.end(),
//                        vWordSentenceIndices.begin(), vWordSentenceIndices.end(),
//                        back_inserter(intersection));
//                    vQuerySentenceIndices = intersection;
//                    if (vQuerySentenceIndices.empty()) {
//                        break;
//                    }
//                }
//            }
//            query.erase(0, nPos + delimiter.length());
//        }
//        if (!query.empty()) {
//            if (mapWords.count(query) == 0) {
//                vQuerySentenceIndices.clear();
//            }
//            else {
//                vector<int> vWordSentenceIndices = mapWords[query];
//                if (vQuerySentenceIndices.empty()) {
//                    vQuerySentenceIndices = vWordSentenceIndices;
//                }
//                else {
//                    vector<int> intersection;
//                    set_intersection(vQuerySentenceIndices.begin(), vQuerySentenceIndices.end(),
//                        vWordSentenceIndices.begin(), vWordSentenceIndices.end(),
//                        back_inserter(intersection));
//                    vQuerySentenceIndices = intersection;
//                }
//            }
//        }
//        if (vQuerySentenceIndices.empty()) {
//            results.push_back({ -1 });
//        }
//        else {
//            results.push_back(vQuerySentenceIndices);
//        }
//    }
//    return results;
//}
//
//int main() {
//    vector<string> sentences = { "jim likes mary",
//                                "kate likes tom",
//                                "tom does not like jim" };
//    vector<string> queries = { "jim tom", "likes" };
//    vector<vector<int>> results = textQueries(sentences, queries);
//    for (vector<int> result : results) {
//        for (int i : result) {
//            cout << i << " ";
//        }
//        cout << endl;
//    }
//    return 0;
//}