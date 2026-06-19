#include<bits/stdc++.h>
using namespace std;
const int maxn=200010;
const int maxq=200010;
int a[200010][200010];
int dx[]=(1,-1,-1,0),dy[]=(1,-1,-1,1);
void dfs(int x,int y){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			return a[i+1][j]+1;
		}
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=q;j++){
			cin>>a[i][j];
		}
	}
	return 0;
}
