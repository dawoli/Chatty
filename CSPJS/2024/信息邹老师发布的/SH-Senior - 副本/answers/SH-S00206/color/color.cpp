#include<bits/stdc++.h>
using namespace std;
int t;
const int MAXN=2e5+5;
int a[MAXN];
int c[MAXN];
int ans=-1;
int n;
void DFS(int pos,int sum){
	if(pos==n+1){
		ans=max(ans,sum);
		return;
	}
	int find=0;
	//0
    c[pos]=0;
	for(int i=pos-1;i>=1;i--){
		if(c[i]==c[pos]){
			find=i;break;
		}
	}
	if(find==0){
		DFS(pos+1,sum);
	}else{
		if(a[find]==a[pos])DFS(pos+1,sum+a[find]);
		else DFS(pos+1,sum);
	}
	//1
	c[pos]=1;
	for(int i=pos-1;i>=1;i--){
		if(c[i]==c[pos]){
			find=i;break;
		}
	}
	if(find==0){
		DFS(pos+1,sum);
	}else{
		if(a[find]==a[pos])DFS(pos+1,sum+a[find]);
		else DFS(pos+1,sum);
	}
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	while(t--){
		memset(a,0,sizeof(a));
		ans=-1;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		DFS(1,0);
		cout<<ans<<"\n";
	}
	return 0;
}
