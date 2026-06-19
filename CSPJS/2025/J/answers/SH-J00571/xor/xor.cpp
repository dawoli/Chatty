#include<bits/stdc++.h>
using namespace std;
int n,k;
const int maxn=5e5+1;
int a[maxn],x[maxn];
bool mem[maxn];
int ans[maxn];
int dfs(int sc){
	if(sc>=n) return 0;
	if(mem[sc]){
		return ans[sc];
	}
	mem[sc]=1;
	int mx=0;
	for(int i=sc+1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int R=x[j] xor x[i-1];
			if(k==R){
				mx=max(mx,1+dfs(j));	
			}
		}
	}
	return ans[sc]=mx;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	x[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		x[i]=x[i-1] xor a[i];
	}
	cout<<dfs(0);
	fclose(stdin);
	fclose(stdout);
}
