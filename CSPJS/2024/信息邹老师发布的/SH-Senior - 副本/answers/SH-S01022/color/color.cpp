#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+5;
int T,n;
int A[MAXN],color[MAXN];
int dfs(int pos){
	if(pos==n+1){
		int ans=0;
		int lstB=0,lstR=0;
		for(int i=1;i<=n;i++){
			if(color[i]==1){
				if(lstB)
					if(A[i]==A[lstB]) ans+=A[i]; 
				lstB=i;
			}
			else{
				if(lstR)
					if(A[i]==A[lstR]) ans+=A[i];
				lstR=i;
			}
		}
		return ans;
	}
	color[pos]=1;
	int ans1=dfs(pos+1);
	color[pos]=2;
	int ans2=dfs(pos+1);
	return max(ans1,ans2);
}
void solve(){
	memset(A,0,sizeof(A));
	memset(color,0,sizeof(color));
	cin>>n;
	for(int i=1;i<=n;i++) cin>>A[i];
	cout<<dfs(1)<<endl;
	return;
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i++) solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
