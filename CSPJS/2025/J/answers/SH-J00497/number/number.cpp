#include<bits/stdc++.h>
//#define int long long
using namespace std;
string s;
int a[1000005];
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=s.size();
	int cnt=0;
	for(int i=0;i<l;i++){
		if(s[i]>='0' and s[i]<='9'){
			a[++cnt]=s[i]-'0';
		}
	}
	sort(a+1,a+1+cnt,cmp);
	for(int i=1;i<=cnt;i++){
		cout<<a[i];
	}
	return 0;
}
