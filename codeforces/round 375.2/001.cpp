#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int x1,x2,x3;
	cin >> x1 >> x2 >> x3;
	int r1 = min(x1,min(x2,x3));
	int r2 = max(x1,max(x2,x3));
	cout << r2 - r1 << endl;
	return 0;
}
