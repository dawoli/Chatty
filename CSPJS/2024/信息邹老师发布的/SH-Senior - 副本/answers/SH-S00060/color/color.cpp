#include<bits/stdc++.h>
using namespace std;
int t,n;
long long a[100007];
map<long long,map<long long,long long> > f;
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	for(int ro=1;ro<=t;ro++){
		cin>>n;
		a[0]=-1;
		a[n+1]=-1;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=n-1;i>=1;i--){
			for(int r=0;r<=i;r++){
				long long num=max(f[i+1][r],f[i+1][i]);
				if(a[i]==a[i+1]) num=max(num,f[i+1][r]+a[i]);
				if(a[r]==a[i+1]) num=max(num,f[i+1][i]+a[i+1]);
				f[i][r]=num;
			}
		}
		cout<<f[1][0]<<endl;
	}
	return 0;
}
