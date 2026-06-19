#include<bits/stdc++.h>
using namespace std;
int n,q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	string a,b;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
	}
	string f[10009][10009];
	for(int i=1;i<=q;i++){
		for(int j=1;j<=2;j++){
			cin>>f[i][j];
		} 
	}
	int ans;
	for(int i=1;i<=n;i++){
		string m = f[i][1];
		string g = f[i][2];
		int c = m.size();
		int d = g.size();
		for(int j=1;j<=c;j++){
			for(int k=1;k<=d;k++){
				if(m[j]==g[k]) ans++;
			} 
		}
	}
	if(ans==0){
		cout<<0<<endl;
	}
	return 0;
}
