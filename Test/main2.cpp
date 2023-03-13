//#include <cpprest/http_client.h>
//#include <cpprest/json.h>
//#include <iostream>
//#include <vector>
//#include <unordered_map>
//#include <algorithm>
//#include<string>
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
//    
//
//    string t = "https://jsonmock.hackerrank.com/api/articles?page=" + to_string(page);;
//
//    uri url = utility::conversions::to_string_t(t);
//
//
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
//        total_pages = stoi(getArticles("/total_pages"));
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
//
//int main() {
//    vector<string> str = topArticles(5);
//    cout << str[0] << endl;
//    return 0;
//}