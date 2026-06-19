#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string s;
int n,a[N],cnt;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++)
		if('0'<=s[i]&&s[i]<='9') a[++cnt]=s[i]-'0';
	sort(a+1,a+1+cnt,[](int x,int y){ return x>y; });
	for(int i=1;i<=cnt;i++) cout<<a[i];
	return 0;
}
