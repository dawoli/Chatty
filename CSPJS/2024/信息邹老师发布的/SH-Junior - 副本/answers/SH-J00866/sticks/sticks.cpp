#include<bits/stdc++.h>
using namespace std;
int a[11];
long long T,n,minn=0;
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	a[1]=6;
	a[2]=2;
	a[3]=5;
	a[4]=5;
	a[5]=4;
	a[6]=5;
	a[7]=6;
	a[8]=3;
	a[9]=7;
	a[10]=6;
	while(T--){
		cin>>n;
		minn=100005;
		if(n==1){
			cout<<-1<<endl;
			continue;
		}
		if(n<=7){
			for(long long i=2;i<=10;i++){
				if(n==a[i])minn=min(minn,i-1);
			}
			cout<<minn<<endl;
			continue;
		}
		if(n%7==0){
			int cnt=n/7;
			while(cnt--){
				cout<<8;
			}
			cout<<endl;
			continue;
		}
		if(n%7==1){
			int cnt=(n-1)/7-1;
			cout<<10;
			while(cnt--){
				cout<<8;
			}
			cout<<endl;
			continue;
		}
		for(long long i=2;i<=10;i++){
			for(long long j=1;j<=10;j++){
				if(a[i]+a[j]==n){
					long long k=10*(i-1)+j-1;
					minn=min(minn,k);
				}
			}
		}
		if(minn!=100005){
			cout<<minn<<endl;
			continue;
		}
		for(long long i=2;i<=10;i++){
			for(long long j=1;j<=10;j++){
				for(long long l=1;l<=10;l++){
					if(a[i]+a[j]+a[l]==n){
						long long k=100*(i-1)+10*(j-1)+l-1;
						minn=min(minn,k);
					}
				}
			}
		}
		if(minn!=100005){
			cout<<minn<<endl;
			continue;
		}
		for(long long i=2;i<=10;i++){
			for(long long j=1;j<=10;j++){
				for(long long l=1;l<=10;l++){
					for(long long m=1;m<=10;m++){
						if(a[i]+a[j]+a[l]+a[m]==n){
							long long k=1000*i-1000+100*j-100+10*l-10+m-1;
							minn=min(minn,k);
						}
					}
				}
			}
		}
		if(minn!=100005){
			cout<<minn<<endl;
			continue;
		}
		for(long long i=2;i<=10;i++){
			for(long long j=1;j<=10;j++){
				for(long long l=1;l<=10;l++){
					for(long long m=1;m<=10;m++){
						for(long long b=1;b<=10;b++){
							if(a[i]+a[j]+a[l]+a[m]+a[b]==n){
								long long k=10000*i-10000+1000*j-1000+100*l-100+10*m-10+b-1;
								minn=min(minn,k);
							}
						}
					}
				}
			}
		}
		if(minn!=100005){
			cout<<minn<<endl;
			continue;
		}
		for(long long i=2;i<=10;i++){
			for(long long j=1;j<=10;j++){
				for(long long l=1;l<=10;l++){
					for(long long m=1;m<=10;m++){
						for(long long b=1;b<=10;b++){
							for(long long s=1;s<=10;s++){
								if(a[i]+a[j]+a[l]+a[m]+a[b]+a[s]==n){
									long long k=100000*i-100000+10000*j-10000+1000*l-1000+100*m-100+10*b-10+s-1;
									minn=min(minn,k);
								}
							}
						}
					}
				}
			}
		}
		if(minn!=100005){
			cout<<minn<<endl;
			continue;
		}
		if(minn==100005){
			cout<<-1<<endl;
			continue;
		}
	}
	return 0;
}
