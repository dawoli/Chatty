#include<bits/stdc++.h>
using namespace std;
map<string,int>mp;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		string s;
		cin>>s;
		mp[s]=1;
	}
	int cnt=52;
	map<string,int>::iterator it=mp.begin();
	for(;it!=mp.end();++it){
		cnt--;
	}
	printf("%d",cnt);
	return 0;
}
