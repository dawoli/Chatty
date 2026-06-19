#include <bits/stdc++.h>
using namespace std;
map<int,map<string,string>> mp;
map<int,map<string,string>>::iterator it;
int n,q;
//int read(){
//	int x = 0,f = 1;
//	char c = getchar();
//	while(c<'0' and c>'9'){
//		if(c == '-')f=-1;
//		c = getchar();
//	}
//	while(c>='0' and c<='9'){
//		x = x*10+c-'0';
//		c = getchar();
//	}
//	return x*f;
//}
void solve(){
	string s1,s2,subs,ress;
	cin>>s1>>s2;
	int leng = s1.size(),sleng,cnt=0;
	for(it=mp.begin();it!=mp.end() and (it->first)<=leng;it++){
		ress="";
		sleng = it->first;
		for(int i=0;i+sleng<=leng;i++){
			subs = s1.substr(i,sleng);
			if((it->second).find(subs)!=(it->second).end()){
				subs = (it->second)[subs];
				if(ress+subs+s1.substr(i+sleng,leng-i-sleng) == s2)cnt++;
			}
			ress+=s1[i];
		}
	}
	cout<<cnt<<"\n";
} 
void init(){
	cin>>n>>q;
	string s1,s2;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		mp[s1.size()][s1] = s2;
	}
	for(int i=1;i<=q;i++)solve();
}
int main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	init();
	return 0;
}
