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
//    vector<string> sentences = { "blob and alice like to text each other",
//                                "blob does not like to ski but does not like to fall",
//                                "Alice likes to ski" };
//    vector<string> queries = { "blob alice", "alice", "like", "non occurrence" };
//    vector<vector<int>> results = textQueries(sentences, queries);
//    for (vector<int> result : results) {
//        for (int i : result) {
//            cout << i << " ";
//        }
//        cout << endl;
//    }
//    return 0;
//}