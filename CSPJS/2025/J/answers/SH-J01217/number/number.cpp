#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string str;
	cin >> str;
	int f = 0;
	for(int i = 0; i < str.size(); i++){
		if(str[i]<='9'&&str[i]>='0') {
			a[f] = str[i]-'0';
			f++;
		}
	}
	sort(a, a+f,greater<int>());
	for(int i = 0; i < f; i++)  {
		cout << a[i];
	}
	return 0;
}
