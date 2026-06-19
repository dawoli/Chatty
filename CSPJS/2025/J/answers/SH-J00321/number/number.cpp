#include<bits/stdc++.h>
using namespace std;
int a[1000007];
bool cmp(int a,int b){
	return a>b;
}
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int p=0;
	cin >> s;
	int n = s.length();
	for(int i = 0; i < n; i++){
		if(s[i]<='9'&&s[i]>='0') {
			a[p]=s[i]-'0';
			p++;
		}
	}
	sort(a,a+p,cmp);
	for(int i = 0; i < p; i++)
	cout << a[i];
	return 0;
}
