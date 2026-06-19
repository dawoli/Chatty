#include<bits/stdc++.h>
using namespace std;
const int N=5e5*2+10;
struct node{
	int i,j;
};
vector< vector<node> >ve;
vector<node>ans;
int n,k,a[N];
int cnt;
bool bo[N];
bool check(node a,node b){
	if(a.j>b.i) return false;
	return true;
}
void dfs(int depth){
	if(depth==n){
		int _=0;
		for(int i=1;i<=ans.size();i++){
			if(bo[i]) _++;
		}
		cnt=max(_,cnt);
		return ;
	}else{
		if(!check(ans[depth],ans[depth-1])){
			bo[depth]=false;
			dfs(depth+1);
			
			bo[depth]=true;
			bo[depth-1]=false;
			dfs(depth+1);
			return;
		}
		else dfs(depth+1);
	}
	return ;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	memset(bo,true,sizeof(bo));
	cin>>n>>k;
	int t;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int answ=a[i];
			for(int k=i+1;k<=j;k++){
				answ^=a[k];
			}
			if(answ==k){
				ans.push_back({i,j});
				cout<<i<<' '<<j<<endl;
			}
		}
	}
	dfs(1);
	cout<<cnt-1;
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 
