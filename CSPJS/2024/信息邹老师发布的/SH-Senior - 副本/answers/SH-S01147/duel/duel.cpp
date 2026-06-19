#include<bits/stdc++.h>
using namespace std;
int boss[100010];
int die[100010];
int ans=0x3f;
int flag;
void beans(int u,int n,int sum){
	flag=0;
	if(u==n+1){
		ans=min(ans,sum);
	}
	else{
		for(int i=1;i<=n;i++){
			if(i!=u&&!die[i]){
				if(boss[i]<boss[u]){
					die[i]=1;
					flag=1;
					beans(u+1,n,sum-1);
					die[i]=0;
				}
			}
		}
		if(flag==0){
			beans(u+1,n,sum);
		}
	}
}
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>boss[i];
	}
	beans(1,n,n);
	cout<<ans;
	return 0;
}
