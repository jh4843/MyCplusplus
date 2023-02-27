
#include <iostream>
#include <string>
#include <locale.h>
#include <codecvt>
#include <windows.h>
#include <winnls.h>
#include <vector>
#include <sstream>

using namespace std::string_literals; // enables s-suffix for std::string literals

// 멀티바이트 MBCS - Multi Byte Character Set: 영어는 1 Byte 그외 문자는 2 Bytes 로 처리
// Ex) MessageBox( NULL, "a", "b", MB_OK );
// 유니코드 WBCS - Wide Byte Character Set: 모든 문자를 2 Bytes로 처리 (GCC는 4Byte로 처리) Why? Windows는 UCS-16을 Unicode로 채택하고 있다.
// Ex) MessageBox(NULL, L"a", L"b", MB_OK);

// Ordinary character literals of type char, for example 'a'
// UTF - 8 character literals of type char(char8_t in C++20), for example u8'a'
// Wide - character literals of type wchar_t, for example L'a'
// UTF - 16 character literals of type char16_t, for example u'a'
// UTF - 32 character literals of type char32_t, for example U'a'

using namespace std;

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


int main()
{
    setlocale(LC_ALL, "");
    //std::wcout.imbue(std::locale("korean"));

    // Character literals
    auto c0 = 'A'; // char
    auto c1 = u8'A'; // char
    auto c2 = L'A'; // wchar_t
    auto c3 = u'A'; // char16_t
    auto c4 = U'A'; // char32_t
    
    std::cout << c0 << '\t' << sizeof(c0) << '\t' << typeid(c0).name() << std::endl;
    std::cout << (const char)c1 << '\t' << sizeof(c1) << '\t' << typeid(c1).name() << std::endl;
    std::wcout << c2 << '\t' << sizeof(c2) << '\t' << typeid(c2).name() << std::endl;
    std::cout << (const char)c3 << '\t' << sizeof(c3) << '\t' << typeid(c3).name() << std::endl;
    std::cout << (const char)c4 << '\t' << sizeof(c4) << '\t' << typeid(c4).name() << std::endl;
    
    
    
    // Multicharacter literals
    auto m0 = 'abcd'; // int, value 0x61626364
    
    std::cout << m0 << '\t' << sizeof(m0) << '\t' << typeid(m0).name() << std::endl;
    
    // String literals

    

    auto s0 = "김"; // const char*
    auto s1 = u8"김"; // const char* before C++20, encoded as UTF-8,
    // const char8_t* in C++20
    auto s2 = L"김"s; // const wchar_t*
    auto s3 = u"hello"; // const char16_t*, encoded as UTF-16
    auto s4 = U"hello"; // const char32_t*, encoded as UTF-32

    std::cout << s0 << '\t' << sizeof(s0) << '\t' << typeid(s0).name() << std::endl;
    std::cout << s1 << '\t' << sizeof(s1) << '\t' << typeid(s1).name() << std::endl;
    std::wcout << s2 << '\t' << sizeof(s2) << '\t' << typeid(s2).name() << std::endl;
    std::cout << s3 << '\t' << sizeof(s3) << '\t' << typeid(s3).name() << std::endl;
    std::cout << s4 << '\t' << sizeof(s4) << '\t' << typeid(s4).name() << std::endl;
// 
//     // Raw string literals containing unescaped \ and "
//     auto R0 = R"("Hello \ world")"; // const char*
//     auto R1 = u8R"("Hello \ world")"; // const char* before C++20, encoded as UTF-8,
//     // const char8_t* in C++20
//     auto R2 = LR"("Hello \ world")"; // const wchar_t*
//     auto R3 = uR"("Hello \ world")"; // const char16_t*, encoded as UTF-16
//     auto R4 = UR"("Hello \ world")"; // const char32_t*, encoded as UTF-32
// 
//     std::cout << R0 << '\t' << sizeof(R0) << '\t' << typeid(R0).name() << std::endl;
//     std::cout << R1 << '\t' << sizeof(R1) << '\t' << typeid(R1).name() << std::endl;
//     std::cout << R2 << '\t' << sizeof(R2) << '\t' << typeid(R2).name() << std::endl;
//     std::cout << R3 << '\t' << sizeof(R3) << '\t' << typeid(R3).name() << std::endl;
//     std::cout << R4 << '\t' << sizeof(R4) << '\t' << typeid(R4).name() << std::endl;
// 
    // Combining string literals with standard s-suffix
    auto S0 = "김재혁"s; // std::string
    auto S1 = u8"김재혁"s; // std::string before C++20, std::u8string in C++20
    auto S2 = L"김재혁"s; // std::wstring
    auto S3 = u"hello"s; // std::u16string
    auto S4 = U"hello"s; // std::u32string

	size_t utf8_size = 0;

	int required_cch = ::MultiByteToWideChar(
		CP_UTF8,
		MB_ERR_INVALID_CHARS,
        S1.c_str(), 
        S1.length(),
		0, 
        0);

	std::wstring wunicode8;
	wunicode8.resize(required_cch);

	::MultiByteToWideChar(
		CP_UTF8,
		MB_ERR_INVALID_CHARS,
        S1.c_str(), 
        (int)S1.length(),
        &wunicode8[0],
        (int)wunicode8.length()
	);

    
// 
//     std::wstring_convert<std::codecvt<char16_t, char, mbstate_t>, char16_t> converter16;
//     std::wstring_convert<std::codecvt<char32_t, char, mbstate_t>, char32_t> converter32;
// 
// //    std::string u8conv = std::wstring_convert<std::codecvt_utf8_utf16<char16_t>, char16_t>{}.to_bytes(S3);
// 
    //std::locale::global(std::locale("kor")); //"UTF-8") );
    //std::wcout.imbue(std::locale("korean"));
    //std::wcout.imbue(std::locale(""));

	std::cout << std::locale().name() << std::endl;
    
    std::cout << S0 << '\t' << sizeof(S0) << '\t' << typeid(S0).name() << std::endl;
    std::cout << S1 << '\t' << sizeof(S1) << '\t' << typeid(S1).name() << std::endl;
    std::wcout << S2 << '\t' << sizeof(S2) << '\t' << typeid(S2).name() << std::endl;
    std::wcout << wunicode8 << '\t' << sizeof(wunicode8) << '\t' << typeid(wunicode8).name() << std::endl;

    //std::wcout << S4 << '\t' << sizeof(S4) << '\t' << typeid(S4).name() << std::endl;
//     std::cout << converter16.to_bytes(S3) << '\t' << sizeof(S3) << '\t' << typeid(S3).name() << std::endl;
//     std::cout << converter32.to_bytes(S4) << '\t' << sizeof(S4) << '\t' << typeid(S4).name() << std::endl;
// 
//     // Combining raw string literals with standard s-suffix
//     auto S5 = R"("Hello \ world")"s; // std::string from a raw const char*
//     auto S6 = u8R"("Hello \ world")"s; // std::string from a raw const char* before C++20, encoded as UTF-8,
//     // std::u8string in C++20
//     auto S7 = LR"("Hello \ world")"s; // std::wstring from a raw const wchar_t*
//     auto S8 = uR"("Hello \ world")"s; // std::u16string from a raw const char16_t*, encoded as UTF-16
//     auto S9 = UR"("Hello \ world")"s; // std::u32string from a raw const char32_t*, encoded as UTF-32
// 
//     std::cout << S5 << '\t' << sizeof(S5) << '\t' << typeid(S5).name() << std::endl;
//     std::cout << S6 << '\t' << sizeof(S6) << '\t' << typeid(S6).name() << std::endl;
    //std::wcout << S7 << '\t' << sizeof(S7) << '\t' << typeid(S7).name() << std::endl;
//     std::cout << converter16.to_bytes(S8) << '\t' << sizeof(S8) << '\t' << typeid(S8).name() << std::endl;
//     std::cout << converter32.to_bytes(S9) << '\t' << sizeof(S9) << '\t' << typeid(S9).name() << std::endl;

    string str = "AAA,BBB,CCC,DDD,EEE,FFF,GGG";

    vector<string> result = split(str, ',');

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << "\n";
    }

    auto aa = getchar();
    std::cout << aa << '\t' << sizeof(aa) << '\t' << typeid(aa).name() << std::endl;
}