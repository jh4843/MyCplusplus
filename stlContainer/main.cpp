#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>


using namespace std;

class Person
{
private:
    string _name;
    int _age;

public:
    Person(string name, int age)
    {
        _name = name;
        _age = age;
    }

    string getName()
    {
        return _name;
    }

    int getAge()
    {
        return _age;
    }
};

bool cmpReverseInt(int a, int b) {
    return a > b;
}

bool cmpReverseTuple(tuple <int, string, int> a, tuple <int, string, int> b) {
    return get<0>(a) > get<0>(b);
}

// [1]. Vector
void useVector()
{
    vector<int> v1, v2, v3, v4;

    //1. push items to vector
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(50);

    cout << "v1 " << endl;

    // 2. access
    for (auto& v : v1) {
        cout << v << " ";                                       // 10 20 30 40 50
    }

    cout << endl;
    cout << v1[0] << " " << v1[1] << endl;                      // 10 50
    cout << v1.at(0) << " " << v1[1] << endl;                   // 10 50
    cout << v1.front() << " " << v1.back() << endl;             // 10 50
    cout << *v1.begin() << " " << *(--v1.end()) << endl;        // 10 50

    vector<int>::iterator v1_Iter;
    for (v1_Iter = v1.begin(); v1_Iter != v1.end(); v1_Iter++)
    {
        cout << *v1_Iter << " ";                                // 10 20 30 40 50
    }
    cout << endl;

    // 3. erasee and copies all items.
    v2.push_back(999);
    v2.push_back(888);
    v2.push_back(777);

    v2.assign(v1.begin(), v1.end());
    cout << "v2 = ";
    for (auto& v : v2) {
        cout << v << " ";           // 10 20 30 40 50
    }
    cout << endl;

    v3.assign(7, 4);
    cout << "v3 = ";
    for (auto& v : v3) {
        cout << v << " ";           // 4 4 4 4 4 4 4
    }
    cout << endl;

    v3.assign({ 5, 6, 7 });
    for (auto& v : v3) {
        cout << v << " ";           // 5 6 7
    }
    cout << endl;

    // 4. Delete element
    v4.push_back(10);
    v4.push_back(20);
    v4.push_back(30);
    v4.push_back(40);
        
    v4.pop_back();                  // remove the last element

    for (auto& v : v4) {
        cout << v << " ";           // 10 20 30 
    }
    cout << endl;

    v4.clear();

    for (auto& v : v4) {
        cout << v << " ";           // empty
    }
    cout << endl;

    // 5. Reserve
    vector<int> v5;
    v5.reserve(4);

    v5.push_back(10);
    v5.push_back(20);
    v5.push_back(30);
    v5.push_back(40);
    v5.push_back(50);
    v5.push_back(60);

    for (auto& v : v5) {
        cout << v << " ";           // 10 20 30 40 50 60
    }
    cout << endl;

    // 6. Delete
    // #1. delete the n th item.
    vector<int> v6, v7, v8, v9, v10;
    v6.push_back(10);
    v6.push_back(20);
    v6.push_back(30);
    v6.push_back(40);
    v6.push_back(50);

    v6.erase(v6.begin() + 3);       // delete 4'th element

    for (auto& v : v6) {
        cout << v << " ";           // 10 20 30 50
    }
    cout << endl;

    // #2. delete the elements that has specific value and print remain items..
    v7.push_back(10);
    v7.push_back(20);
    v7.push_back(30);
    v7.push_back(40);
    v7.push_back(50);
    v7.push_back(60);
    v7.push_back(70);
    v7.push_back(80);
    v7.push_back(90);

    remove(v7.begin(), v7.end(), 20); // not include last element.

    for (auto& v : v7) {
        cout << v << " ";           // 10 30 40 50 60 70 80 90
    }
    cout << endl;

    // #3. delete the elements that has specific value.
	v8.push_back(10);
	v8.push_back(20);
	v8.push_back(30);
	v8.push_back(40);
	v8.push_back(50);
	v8.push_back(60);
	v8.push_back(70);
	v8.push_back(80);
	v8.push_back(90);

    v8.erase(remove(v8.begin(), v8.end(), 20), v8.end());

    for (auto& v : v8) {
        cout << v << " ";           // 10 30 40 50 60 70 80 90 -> because remove() return the element that is first item amoung undeleted elements..
    }
    cout << endl;

	// #4. delete the elements in loop
	v9.push_back(10);
	v9.push_back(20);
	v9.push_back(30);
	v9.push_back(40);
	v9.push_back(50);
	v9.push_back(60);
	v9.push_back(70);
	v9.push_back(80);
	v9.push_back(90);

    for (auto iter = v9.begin(); iter < v9.end(); iter++) {
        if (*iter == 50) {
            iter = v9.erase(iter);
        }
    }

	for (auto i = 0; i < v9.size(); i++) {
        if (v9[i] == 50) {
            v9.erase(v9.begin() + i);
        }
	}

	for (auto& v : v9) {
		cout << v << " ";           // 10 20 30 40 60 70 80 90
	}

    cout << endl;

	// #5. delete the elements in loop
	v10.push_back(10);
	v10.push_back(20);
	v10.push_back(30);
	v10.push_back(40);
	v10.push_back(50);
	v10.push_back(60);
	v10.push_back(70);
	v10.push_back(80);
	v10.push_back(90);

	for (auto i = 0; i < v10.size(); i++) {
		if (v10[i] == 60) {
            v10.erase(v10.begin() + i);
		}
	}

	for (auto& v : v10) {
		cout << v << " ";           // 10 20 30 40 50 70 80 90
	}

	cout << endl;

    // 6. sort
    sort(v10.begin(), v10.end(), cmpReverseInt);
    for (auto& v : v10) {
        cout << v << " ";           // 10 20 30 40 50 70 80 90
    }
    cout << endl;

    // 7. use vector with tuple
    vector<tuple<int, string, int>> v11;

    // index, name, age
    v11.push_back(make_tuple(0, "Jin", 2));
    v11.push_back(make_tuple(1, "Kim", 10));
    v11.push_back(make_tuple(2, "Lee", 12));
    v11.push_back(make_tuple(3, "David", 8));

    sort(v11.begin(), v11.end(), cmpReverseTuple);

    for (auto& v : v11) {
        cout << "index: " << get<0>(v) << " name: " << get<1>(v) << " age: " << get<2>(v) << endl;
    }

    // 8. 2 dimensional vector
    // initialize
    vector<vector<int>> v22(10, vector<int>(10, 5));
    cout << "v22: " << v22[5][5] << endl;

	for (auto& vii : v22) {
        for (auto& v : vii) {
            cout << v << " ";
        }
        cout << endl;
	}

}

// [2]. Queue
void useQueue() 
{
    // 1. insert with push
    cout << "[QUEUE #1] insert with push()" << endl;

    queue<Person*> q;
    q.push(new Person("John", 5));
    q.push(new Person("Lee", 3));
    q.push(new Person("Kim", 11));
    q.push(new Person("Choi", 9));

    while (!q.empty())
    {
        Person* pPerson = q.front();    // get first item.
        cout << "name: " << pPerson->getName() << " age: " << pPerson->getAge() << endl;
        q.pop();    // remove the first item.
    }

    // 2. insert with emplace
    cout << "[QUEUE #2] insert with emplace()" << endl;

    q.emplace(new Person("John", 5));
    q.emplace(new Person("Lee", 3));
    q.emplace(new Person("Kim", 11));
    q.emplace(new Person("Choi", 9));

    while (!q.empty())
    {
        Person* pPerson = q.front();    // get first item.
        cout << "name: " << pPerson->getName() << " age: " << pPerson->getAge() << endl;
        q.pop();    // remove the first item.
    }

    // 3. swap
    cout << "[QUEUE #3] swap items" << endl;

    queue<Person*> q2;

    q.push(new Person("John", 5));
    q.push(new Person("Lee", 3));
    q.push(new Person("Kim", 11));
    q.push(new Person("Choi", 9));

    q2.push(new Person("a", 1));
    q2.push(new Person("b", 2));
    q2.push(new Person("c", 3));
    q2.push(new Person("d", 4));

    // Swap q and q2
    q.swap(q2);

    cout << "q items" << endl;
    while (!q.empty())
    {
        Person* pPerson = q.front();    // get first item.
        cout << "name: " << pPerson->getName() << " age: " << pPerson->getAge() << endl;
        q.pop();    // remove the first item.
    }

    cout << "q2 items" << endl;
    while (!q2.empty())
    {
        Person* pPerson = q2.front();    // get first item.
        cout << "name: " << pPerson->getName() << " age: " << pPerson->getAge() << endl;
        q2.pop();    // remove the first item.
    }

    return;
}

void main()
{
	useVector();
    useQueue();
}