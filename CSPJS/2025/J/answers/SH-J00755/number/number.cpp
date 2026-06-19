#include <bits/stdc++.h>
using namespace std;
string s;
short a[1000005];
int t=0;
bool cmp(short x,short y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	int n=s.length();
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[t++]=s[i]-'0';
		}
	}
	sort(a,a+t,cmp);
	for(int i=0;i<t;i++){
		cout << a[i];
	}
	return 0;
}
