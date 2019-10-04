#include <iostream>
#include <functional>

using namespace std;

int foo(int x) { return 2 + x; }

void main() {

	std::function<int(int)> stdf_foo = &foo;

	cout << stdf_foo(2);

	getchar();
}
