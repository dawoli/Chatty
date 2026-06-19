#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int cnt[1000009];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	m=0;
	for(int i=0;i<n;i++){
		if((s[i]>='0')&&(s[i]<='9')){
			cnt[++m]=(int)(s[i]-'0');
		}
	}
	sort(cnt+1,cnt+1+m);
	for(int i=m;i>=1;i--){
		cout<<cnt[i];
	}
	return 0;
}
