#include <iostream>

using namespace std;

typedef int(*f_int_t) (int);

int foo(int x) { return 2 + x; }

void main() {

	f_int_t foo_p = &foo;

	cout << foo_p(2);

	getchar();
}
