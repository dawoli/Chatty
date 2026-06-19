#include <bits/stdc++.h>
using namespace std;
const int N=1000009;
char s[N];
int a[N];
int ans[N];
int m,n;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[m++]=s[i]-'0';
		}
	}
	sort(a,a+m);
	for(int i=m-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
}
