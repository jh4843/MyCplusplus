#include <iostream>
#include <map>
#include <list>

using namespace std;

auto mySumFunc(int a, int b) {
    return a + b;
}

template<typename T1, typename T2>
auto sumFunc(T1 t1, T2 t2) -> decltype(t1 + t2) {
    return t1 + t2;
}

void main()
{
    // 1. Types
    // basic types
    auto a = true;  // bool a = true --> explicitly type int, auto a = true --> implicitly type int
    auto b = 'A';
    auto c = "A"s;
    auto d = "���ڿ�";
    auto e = 3;
    auto f = 3.0;
    
    cout << "��\tũ��\t�ڷ���" << endl;
    cout << a << '\t' << sizeof(a) << '\t' << typeid(a).name() << endl;
    cout << b << '\t' << sizeof(b) << '\t' << typeid(b).name() << endl;
    cout << c << '\t' << sizeof(c) << '\t' << typeid(c).name() << endl;
    cout << d << '\t' << sizeof(d) << '\t' << typeid(d).name() << endl;
    cout << e << '\t' << sizeof(e) << '\t' << typeid(e).name() << endl;

    // initializer_list <int>
    auto g = { 121, 13 };   
    cout << f << '\t' << sizeof(f) << '\t' << typeid(f).name() << endl;
    for (auto temp : g)
        cout << " " << temp;
    cout << endl;
    cout << '\t' << sizeof(g) << '\t' << typeid(g).name() << endl;

    map<string, int> mapSample;

    mapSample.insert({ "Kim", 1 });
    mapSample.insert({ "Lee", 2 });
    mapSample.insert({ "Choi", 3 });

    //map<int, string>::iterator i = mapSample.begin();
    auto i = mapSample.begin();
    cout << '\t' << sizeof(i) << '\t' << typeid(i).name() << endl;
    for (i = mapSample.begin(); i != mapSample.end(); i++)
        cout << "key: " << i->first << ", val: " << i->second << endl;

    // 2. Reference
    int count = 10;
    int& countRef = count;
    auto myAutoVar = countRef;

    countRef = 11;
    cout << count << " " << myAutoVar << endl;   //

    myAutoVar = 12;
    cout << count << " " << myAutoVar << endl;

    // 3. function
    auto funcPtr = mySumFunc;
    cout << "function ptr: " << countRef << " + " << myAutoVar << " = " << funcPtr(countRef, myAutoVar) << endl;

    cout << "sumFunc: " << 1 << " + " << 2 << " = " << sumFunc(1, 2) << endl;
    cout << "sumFunc: " << 1.1 << " + " << 2.2 << " = " << sumFunc(1.1, 2.2) << endl;


    auto aa = getchar();
    cout << aa << '\t' << sizeof(aa) << '\t' << typeid(aa).name() << endl;
}

