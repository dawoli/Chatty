#include<bits/stdc++.h>
using namespace std;
int cnt[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0); 
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
	    if('0'<=s[i]&&s[i]<='9')cnt[s[i]-'0']++;
	for(int i=9;i>=0;i--){
		while(cnt[i]){
			cout<<i;
			cnt[i]--;
		}
	}
	return 0;
}
/*
君不见黄河之水天上来，奔流到海不复回
君不见高堂明镜悲白发，朝如青丝暮成雪 
*/
