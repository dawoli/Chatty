#include<bits/stdc++.h>
using namespace std;
#define N 2001
typedef long long LL;
LL n,a[N],maxn=0;
bool c[N];	//初始全部为0，染色为1 
LL cal(){
	LL res=0;
	for(int i=n;i>=2;i--){
		for(int j=i-1;j>=1;j--){
			if(c[i]==c[j]){		//同色 
				if(a[i]==a[j]){
					res+=a[i];
				}
				break;
			}
		}
	}
	return res;
}
void Print(){
	for(int i=1;i<=n;i++) cout<<c[i]<<" ";
	cout<<endl;
}
void dfs(int d){	//搜索层数 
	if(d>=n) return;
	//Print();
	c[d]=1;
	maxn=max(maxn,cal());
	dfs(d+1);
	c[d]=0;
	maxn=max(maxn,cal());
	dfs(d+1);
}

int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int T; cin>>T;
	while(T--){
		maxn=0;
		memset(a,0,sizeof(a));
		memset(c,0,sizeof(c));
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		dfs(2);
		cout<<maxn<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
4
3
1 2 1
4
1 2 3 4
8
3 5 2 5 1 2 1 4
9
3 1 4 2 1 4 1 2 3
*/
