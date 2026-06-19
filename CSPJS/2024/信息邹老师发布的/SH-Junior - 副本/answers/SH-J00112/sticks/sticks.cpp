#include<bits/stdc++.h>
using namespace std;
long long t;
long long a[]={6,2,5,5,4,5,6,3,7,6,6},b[]={0,2,1,3,4,5,8,9,7};
int main(){
	freopen("sticks1.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	while(t--){
		long long n,ans=0,m;
		cin>>n;
		m=n;
		if(n<2){
			cout<<"-1\n";continue;
		} 
		if(n==2){
			cout<<"1\n";continue;
		}
		if(n%7==0){
			for(long long i=1;i<=n/7;i++) cout<<"8";
			cout<<"\n";continue;
		}
		if(n<=7){
			for(long long i=1;i<9;i++){
				if(a[i]==n){
					cout<<i<<"\n";
					break;
				}
			}
			continue;
		}
		for(long long i=1;;i++){
			long long j=0;ans*=10;
			if(i==1){
				j=1;
				while(n<a[b[j]]){
					j++;
				}
				n-=a[b[j]];
				cout<<b[j];
			}
			else if(n<=7){
				for(long long k=1;k<9;k++){
					if(a[k]==n){
						cout<<k;
						n-=a[k];
						break;
					}
				}
				break;
			}
			else{
				while(n<a[b[j]]){
					j++;
				}
				n-=a[b[j]];
				cout<<b[j];
			}
		}
		cout<<"\n";
	}
	return 0;
}
