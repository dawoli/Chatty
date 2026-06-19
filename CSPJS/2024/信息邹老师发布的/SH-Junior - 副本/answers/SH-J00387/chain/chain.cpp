#include<bits/stdc++.h>
using namespace std;
int Map[1005][1005],visited[100005];
int T;
int n,k,q;
int Bfs(int x,int t,int e){
	if(x==e){return 1;}
	visited[x]=1;
	bool ed=0;
	for(int i=0;i<n;i++){
		if(Map[x][i]&&!visited[i]){
			ed+=Bfs(i,t-1,e);}}
	return ed;
}
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>T;
	for(int p=0;p<T;p++){
		cin>>n>>k>>q;
		int l[100005],s[1005][1005];
		for(int i=0;i<n;i++){
			cin>>l[i];
			for(int j=0;j<n;j++){
				visited[j]=0;
				cin>>s[i][j];}}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				for(int k=j;k<n;k++){
					Map[s[i][j]][s[i][k]]=1;}}}
		int r[100005],c[100005];
		for(int i=0;i<q;i++){
			cin>>r[i]>>c[i];}
		for(int i=0;i<q;i++){
			int Start=(i==0?1:c[i-1]);
			cout<<Bfs(Start,r[i],c[i])<<endl;}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
