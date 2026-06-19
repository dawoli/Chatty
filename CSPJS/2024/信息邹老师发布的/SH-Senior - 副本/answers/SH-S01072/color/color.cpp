#include<bits/stdc++.h>
using namespace std;

int T;
int n,a[200005],ans; // a:数值 
int f[200005],c[200005]; // f:染色方式 c:收益 

void deal(){
	int r=0,b=0;
	for(int i=1;i<=n;i++){
		if(i==1){
			if(f[i]==1)
				r=i;
			else
				b=i;
			c[i]=0;
		}
		else{
			if(f[i]==1){
				if(r){
					if(a[r]==a[i])
						c[i]=a[i];
					else
						c[i]=0;
				}
				else
					c[i]=0;
				r=i;
			}
			else{
				if(b){
					if(a[b]==a[i])
						c[i]=a[i];
					else
						c[i]=0;
				}
				else
					c[i]=0;
				b=i;
			}
		}
	}
	int sum=0;
	for(int i=1;i<=n;i++)
		sum+=c[i];
	ans=max(ans,sum);
}

void dfs(int x){
	if(x==n+1){
		deal();
		return;
	}
	for(int i=1;i<=2;i++){ // 1:red,2:blue
		f[x]=i;
		dfs(x+1);
	}
	return;
}

int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	for(int ti=1;ti<=T;ti++){
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		dfs(1);
		cout<<ans<<endl;
	}
	return 0;
}
