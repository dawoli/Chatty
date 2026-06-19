#include<bits/stdc++.h>
using namespace std;
int main(){
	int t,n,limn;
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	unsigned long long sum[t];
	for(int i=0;i<t;i++){
		cin>>n;
		sum[i]=0;
		limn=n/2;
		int a[n],a2[n],a3[n],b[n];
		for(int j=0;j<n;j++){
			cin>>a[j]>>a2[j]>>a3[j];
			b[j]=max(a[j],max(a2[j],a3[j]));
		}
		if(n==2) sum[i]=max(a[0]+a2[1],max(a[0]+a2[2],max(a[1]+a2[0],max(a[1]+a2[2],max(a[2]+a2[0],max(a[2],a2[1]))))));
		else if(n<100000){
			for(int j=0;j<n;j++) sum[i]+=b[j];
		}
		else{
			sort(a,a+n);
			for(int k=n;k>=n/2;k--) sum[i]+=a[i];
	    }
	    
	}
	for(int i=0;i<t;i++) cout<<sum[i]<<endl;
	return 0;
}
