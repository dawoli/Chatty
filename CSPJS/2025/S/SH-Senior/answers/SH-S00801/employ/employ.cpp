#include <bits/stdc++.h>
using namespace std;
void solve(){
	int n,m;
	int d=0;
	cin>>n>>m;
	string s;
	cin>>s;
	for(auto c:s){
		if(c=='1'){
			d++;
		}
	}
	if(m>d){
		cout<<0;
		return;
	}
	if(m==n){
		for(auto c:s){
			if(c=='0'){
				cout<<0;
				return;
			}
		}
		for(int i=0;i<n;i++){
			int x;
			cin>>x;
			if(x==0){
				cout<<0;
				return;
			}
		}
		int s=1;
		for(int i=1;i<=n;i++)s*=i;
		cout<<s;
		return;
	}
	if(m==1){
		int i;
		for(i=0;i<n;i++){
			if(s[i]==1)break;
		}
		int cnt=0;
		for(int i=0;i<n;i++){
			int c;
			cin>>c;
			if(c>i)cnt++;
		}
		for(int i=1;i<=n;i++)cnt*=i;
		cout<<cnt;
		return;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
