#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int t,n,m,a[maxn],c[maxn],k=0,ans=1,x[4],sum;
char s;
bool lot[35][maxn];
signed main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>m;
	for(register int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(register int i=1;i<=m;i++){
		cin>>c[i];
	}
	while(ans<n){
		k++;
		ans<<=1;
	}
	for(register int i=1;i<=k;i++){
		for(register int j=1;j<=(1<<(k-i));j++){
			cin>>s;
			lot[i][j]=s;
		}
	}
	cin>>t;
	while(t--){
		cin>>x[0]>>x[1]>>x[2]>>x[3];
		for(register int i=1;i<=n;i++){
			a[i]=a[i]^x[i%4];
		}
		for(register int i=1;i<=m;i++){
			for(register int j=1;j<=n;j++){
				sum=sum^(i*a[j]);
			}
		}
		cout<<sum<<"\n";
	}
	return 0;
}
