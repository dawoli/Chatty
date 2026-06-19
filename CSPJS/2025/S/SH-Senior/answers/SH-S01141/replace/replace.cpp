#include<bits/stdc++.h>
using namespace std;
string s[200086][2],t1,t2;
int n,p,deltas[200086];
int rpstr(int x,int y){
	string tx=t1;
	for(int i=0;i<s[y][1].size();i++)
		tx[i+x]=s[y][1][i];
	if(tx==t2) return 1;
	else return 0;
}
void solve(){
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<t1.size()-s[i][0].size()+1;j++){
			bool flag=1;
			for(int k=0;k<s[i][0].size();k++)
				if(s[i][0][k]!=t1[j+k]){
					flag=0; break;
				}
			if(flag) ans+=rpstr(j,i);
		}
	}
	cout<<ans<<endl;		
}
void solve_A(){
	int x,ans=0;
	for(int i=0;i<t1.size();i++){
		if(t1[i]=='b') x=i;
	}
	for(int i=1;i<=n;i++){
		string tx=t1;
		if(x+deltas[i]>=tx.size()) continue;
		tx[x]='a'; tx[x+deltas[i]]='b';
		if(tx==t2) ans++;
	}
	cout<<ans<<endl;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>p;
	for(int i=1;i<=n;i++) cin>>s[i][0]>>s[i][1];
	bool flag=1;
	for(int i=2;i<=n/50;i++)
		for(int j=0;j<s[i][0].size();j++)
			if(s[i][0][j]!='a'&&s[i][0][j]!='b') flag=0;
	if(flag){
		int p1,p2;
		for(int i=1;i<=n;i++){
			for(int j=0;j<s[i][0].size();j++)
				if(s[i][0][j]=='b') p1=j;
			for(int j=0;j<s[i][1].size();j++)
				if(s[i][1][j]=='b') p2=j;
			deltas[i]=p2-p1;
		}		
	}
	for(int i=1;i<=p;i++){
		cin>>t1>>t2;
		if(flag) solve_A();
		else solve();
	}
	return 0;
}
