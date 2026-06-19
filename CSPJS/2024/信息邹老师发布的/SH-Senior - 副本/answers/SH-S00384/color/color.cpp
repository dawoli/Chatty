#include<bits/stdc++.h>
using namespace std;
int T,n,a[200005],b[200005],c[205];
int Max=-1;
int deal(){
	memset(c,0,sizeof(c));
	int Zero=0,One=0;
	int sum=0;
	for(int i=1;i<=n;i++){
		if(b[i]==0){
			if(Zero==0){
				c[i]=0;
			}
			else {
				if(a[Zero]==a[i]){
					c[i]=a[i];
				}
				else c[i]=0;
			}
			Zero=i;
		}
		if(b[i]==1){
			if(One==0){
				c[i]=0;
			}
			else {
				if(a[One]==a[i]){
					c[i]=a[i];
				}
				else c[i]=0;
			}
			One=i;
		}
	}
	for(int i=1;i<=n;i++){
		sum+=c[i];
	}
	return sum;
}
void dfs(int x){
	if(x==n+1){
		Max=max(Max,deal());
		return ;
	}
	else {
		b[x]=1;
		dfs(x+1);
		b[x]=0;
		dfs(x+1);
	}
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	while(T--){
		Max=-1;
		cin>>n;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		dfs(1);
		cout<<Max<<"\n";
	}
	return 0;
}
