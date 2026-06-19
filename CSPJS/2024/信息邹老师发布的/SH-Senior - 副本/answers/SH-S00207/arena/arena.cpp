#include<bits/stdc++.h>
#define INF 2e9
using namespace std;
const int N=100020;
int T,n,m,mod[N],a[N],c[N],K,x[5];
string order[50];
void convert(){
	for(int i=1;i<=n;i++)
		a[i]=(mod[i]^x[i%4]);
}
void solve(){
	int ans=0;
	for(int k=1;k<=m;k++){
		if(c[k]>n){
			for(int i=n+1;i<=c[k];i++)
				a[i]=INF;
		}
		int lun=log(c[k])/log(2),cnt=0;
		for(int i=1;i<=lun;i++){
			for(int j=1;j<=n;j+=2)
				cnt+=a[j];
		}
		ans=(ans^(k*cnt));
	}
	cout<<ans<<endl;
}
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>mod[i];
	for(int i=1;i<=m;i++)cin>>c[i];
	for(int k=1;k<=m;k++)
		for(int i=1;i<=30;i++)
			if(pow(2,i)>=c[m])
				c[m]=pow(2,i);
	for(int i=1;i<=30;i++)
		if(pow(2,i)>=n){
			K=i;
			break;
		}
	for(int k=1;k<=K;k++)
		cin>>order[k];
	cin>>T;
	for(int k=1;k<=T;k++){
		for(int i=0;i<4;i++)
			cin>>x[i];
		convert();
		solve();
	}
	return 0;
}
