#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ba[10000005],c[10000005],T,a[10000005],f[4],winer[20],sum[10000005],ans,anss;
string s[20];
int lowbit(int x){
	return x&(-x);
}
int calc(int l,int r){
	return sum[r]-sum[l-1];
}
signed main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>ba[i];
	}
	for(int i=1;i<=m;i++){
		cin>>c[i];
	}
	for(int i=1;i<=n;i*=2){
		cin>>s[i];
	}
	for(int i=1;i<=2e5;i++){
		sum[i]=sum[i-1]+i;
	}
	cin>>T;
	while(T--){
		int k=1;
		cin>>f[0]>>f[1]>>f[2]>>f[3];
		for(int i=1;i<=n;i++){
			a[i]=ba[i]^f[i%4];
		}
		for(int i=1;i<=n;i++){
			int id=i,p=i;
			for(int j=1;j<=20&&id!=lowbit(id);j++){
				if(p&(1<<j)){
					id-=(1<<j);
					if(s[id][j]=='0'){
						if(a[winer[j]]<j) winer[j]=p;
						else{
							if(p==i) ans-=i;
							p=winer[j];
						}
					}
					else{
						if(a[p]>=j) winer[j]=p;
						else{
							p=winer[j];
						}
					}
				}
				else{
					winer[j]=p;
					if(s[id][j]=='0'){
						if(a[winer[j]]<j){
							ans-=calc(id+(1<<j)+1,id+(1<<j+1));
						}
					}
					
				}
			}
			if(lowbit(i)==i) ans+=calc(i+1,2*i);
			if(c[k]==i){
				anss^=(ans*k);
			}
		}
		cout<<anss<<endl;
	}
}
