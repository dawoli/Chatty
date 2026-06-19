#include<bits/stdc++.h>
using namespace std;
long long n,k,ans=0;
long long a[22][500002],b[20],vis[500002],c[500002];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(n==1){
		int h; cin>>h;
		if(h==k) cout<<1<<endl;
		else cout<<0<<endl;
		return 0;
	}
	if(n==2){
		int i,j,sum=0; cin>>i>>j;
		if(i==k) sum++;
		if(j==k) sum++;
		if((i^j)==k) sum++;
//		cout<<(i^j)<<endl;
		cout<<sum<<endl;
		return 0;
	}
	int kk=k;
	for(int i=1;i<=20;i++){
		b[i]=k%2;
		k/=2;
	}
	for(int i=1;i<=n;i++){
		int x; cin>>x;
		c[i]=x;
		for(int j=1;j<=20;j++){
			a[j][i]=x%2;
			x/=2;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n-i+1;j++){
			
			long long sum=0,flag=1;
			for(int k=j;k<=j+i-1;k++){
				if(vis[k]){
					flag=0;
					break;
				}
				sum^=c[k];
//				cout<<c[j]<<"  "<<sum<<endl;
			}
//			if(i==3&&j==2) 
			if(flag&&sum==kk){
//				cout<<i<<"   "<<j<<endl;
				ans++;
				for(int k=j;k<=j+i-1;k++){
					vis[k]=1;
//					cout<<k<<" ";
				}
//				cout<<endl;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
