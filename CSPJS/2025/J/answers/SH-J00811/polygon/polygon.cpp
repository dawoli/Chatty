#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	long long sum=0;
	cin >>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int l=3;l<=n;l++){
		int x[l];
		for(int i=0;i<l;i++)x[i]=i;
		while(x[0]<=n-l){
			int cs=0;
			for(int u=0;u<l-1;u++)cs+=a[x[u]];
			if(cs>a[x[l-1]]){
			x[l-1]++;
			sum++;sum%=998244353;
			}else{
				x[l-2]++;
				x[l-1]=x[l-2]+1;
			}
			for(int u=l-1;u>0;u--){
					if(x[u]+(l-u-1)>=n){
						x[u]=0;
						x[u-1]++;
						for(int k=u+1;k<l;k++)x[k]=0;
					}
			}
			for(int u=1;u<l;u++){
				if(x[u]==0)x[u]=x[u-1]+1;
			}
		}
	}
	cout<<sum;
	return 0;
}
