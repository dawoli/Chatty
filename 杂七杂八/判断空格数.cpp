#include <iostream>
using namespace std;
string s;
int a[130] = {0};
int main(){
	int n;
	cin>>n;
	int cnt = 0;
	cin>>s;
	for(int i=0;i<s.length();i++) {
		if (a[(int)s[i]] == 0) {
			a[(int)s[i]] = 1;
			cnt++;
		}
	}
	cout<<cnt<<endl;
	for(int i=0;i<130;i++) {
		if (a[i] == 1) {
			cout<<(char)i;
		}
	}
	return 0;
}
