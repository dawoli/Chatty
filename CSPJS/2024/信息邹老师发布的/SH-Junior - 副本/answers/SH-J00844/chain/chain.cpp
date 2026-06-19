#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int t,n,k,q,s[1010][200010],c,r;
struct node{
	int n,m;
};
struct n1{
	int now,last,idx,round;
};
vector<node> a[200010];
void bfs(){
	queue<n1> q;
	q.push({-1,-1,-1,0});
	while(!q.empty()){
		n1 k=q.front();
		q.pop();
		
	}
}
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++){
			cin>>s[i][0];
			for(int j=1;j<=s[i][0];j++){
				cin>>s[i][j];
				a[s[i][j]].push_back({i,j});}
		}
		while(q--){
			cin>>r>>c;
			bfs();
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
