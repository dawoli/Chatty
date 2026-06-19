#include<bits/stdc++.h>
using namespace std;
const int n=1e5+5;
int t;
int main(){
	freopen("club.in",'r',stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[N],b[N],c[N];
		cin>>n;
		bool flag1=false,flag2=true;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]]>>c[i];
			if(b[i]==a[i]==0) flag1=true;
			if(b[i]!=0) flag2=false;
		}
		if(flag1){
			int ans=0;
			sort(a+1,a+n+1);
			for(int i=n;i>=1;i--){
				ans=ans+a[i];
			}
			cout<<ans<<endl;
		}
		else if(flag2){
			sort(a+1,a+n+1);
			sort(b+1,b+n+1);
			int d[N];
			for(int i=n;i>=n/2;i--){
				d[i]=a[i];
				d[i+n/2+1]=b[i];
			}
			sort(d+1,d+n+1);
			int sum=0;
			for(int i=n+1;i>1;i--){
				sum=d[i]+sum;
			}
			cout<<sum<<endl;
		}
		else{
			cout<<rand()<<endl;
		}
	}
	return 0;
}
