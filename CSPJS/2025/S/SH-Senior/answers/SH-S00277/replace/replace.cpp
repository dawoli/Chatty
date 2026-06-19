#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int n,q;
string s[200005][3],t1,t2;
int check(int ad,int x){
	string c1=" ";
	int tq=t2.size();
	for(int i=1;i<tq;i++){
		string a;
		int te=s[x][2].size();
		if(ad==i){
			a=s[x][2];
			i+=te-1;
		}else{
			a=t1[i];
		}
		c1+=a;
	}
	return c1==t2;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	while(q--){
		int cnt=0;
		cin>>t1>>t2;
		t1=" "+t1;t2=" "+t2;
		if(t1.size()!=t2.size()){
			cout<<0<<endl;
			continue;
		}
		for(int i=1;i<=n;i++){
			if(t1.find(s[i][1])>0){
				if(check(t1.find(s[i][1]),i)){
					cnt++;
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
