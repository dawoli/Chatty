#include<bits/stdc++.h>
using namespace std;
int n,t,a[100009],b[100009],c[100009];
long long sum;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		sum=0;
		memset(a,0,sizeof(a));
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>a[j]>>b[j]>>c[j];
		}
		sort(a+1,a+1+n);
		for(int j=n;j>n/2;j--){
			sum+=a[j];
		}
		cout<<sum<<endl;
	}
	return 0;
} 
