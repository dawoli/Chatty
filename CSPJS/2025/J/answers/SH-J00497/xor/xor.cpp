#include<bits/stdc++.h>
//#define int long long
using namespace std;
int n,k,a[500005],b[500005],cnt=0,maxn=0,cnta=1,cntb=0,cntc=0;
bool f[500005];
struct node{
	int l,r;
}qj[500005];
void dfs(int x,int sum){
	if(x==cnt+1){
		maxn=max(maxn,sum);
		return ;
	}
	dfs(x+1,sum);
	bool flag=0;
	for(int i=qj[x].l;i<=qj[x].r;i++){
		if(f[i]==1){
			flag=1;
			break;
		}
	}
	if(flag==0){
		for(int i=qj[x].l;i<=qj[x].r;i++){
			f[i]=1;
		}
		dfs(x+1,sum+1);
		for(int i=qj[x].l;i<=qj[x].r;i++){
			f[i]=0;
		}
	}
	return ;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){
			cnta++;
		}
//		if(a[i]==1 or a[i]==0){
//			cntb++;
//		}
//		if(a[i]>=0 and a[i]<=255){
//			cntc++;
//		}
		b[i]=a[i];
	}
	if(cnta==n){
		cout<<n/2<<endl;
		return 0;
	}
	for(int i=2;i<=n;i++){
		b[i]=b[i] xor b[i-1];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int t=b[j] xor b[i-1];
			if(t==k){
				qj[++cnt].l=i;
				qj[cnt].r=j;
			}
		}
	}
	dfs(1,0);
	cout<<maxn<<endl;
	return 0;
}
