#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T,n,a[200005];
bool ls[2005];
ll ans,mans;

void dfs(int id){
	if(id>n){
		mans=max(mans,ans);
		return;
	}
	int tmp;
	for(tmp=id-1;tmp>0&&ls[tmp]!=ls[id];--tmp);
	if(a[tmp]==a[id]&&tmp!=0) ans+=a[id];
	ls[id+1]=0;dfs(id+1);
	ls[id+1]=1;dfs(id+1);
	if(a[tmp]==a[id]&&tmp!=0) ans-=a[id];
}

int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
	
	cin>>T;
	for(;T--;){
		memset(a,0,sizeof(a));
		memset(ls,0,sizeof(ls));
		ans=mans=0;
		cin>>n;
		for(int i=1;i<=n;++i) cin>>a[i];
		dfs(0);
		cout<<mans<<endl;
	}
	
    fclose(stdin);
    fclose(stdout);
    return 0;
}
