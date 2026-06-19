#include<bits/stdc++.h>
using namespace std;
long long n,maxx,sum,ans;
int a[5005];
int b[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	while(b[n+1]==0){
		maxx=0;
		sum=0;
		b[1]++;
		for(int i=1;b[i]>1;i++){
			b[i]=0;
			b[i+1]++;
		}
		for(int i=1;i<=n;i++){
			if(b[i]==1){
				if(a[i]>maxx){
					maxx=a[i];
				}
				sum+=a[i];
			}
		}
		if((sum-maxx)>maxx){
			ans++;
		}
	}
    cout<<ans;
	return 0;
}
