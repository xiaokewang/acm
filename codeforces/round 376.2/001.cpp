#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
	string str;
	cin >> str;
	int curr = 'a';
	int cnt = 0;
	for(int i=0;i<str.size();i++){
		int next = str[i];
		if(next < curr){
			cnt += min(curr-next, 'z'-curr + next - 'a' + 1);
		}else{
			cnt += min(next - curr, 'z'-next + curr - 'a' + 1);
		}
		curr = next;

	}
	cout << cnt;

	return 0;
}