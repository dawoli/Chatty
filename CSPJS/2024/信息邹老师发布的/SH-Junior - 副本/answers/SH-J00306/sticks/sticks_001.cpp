#include<bits/stdc++.h>

using namespace std;

long long T,n,cnt,f,sum=10000,k;
int a[12]={0,6,2,5,5,4,5,6,3,7,6};
int b[1000099];

int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		if(n<=1){
			cout<<-1<<endl;
		}
		else if(n==2){
			cout<<1<<endl;
		}
		else if(n==3){
			cout<<7<<endl;
		}
		else if(n==4){
			cout<<4<<endl;
		}
		else if(n==5){
			cout<<2<<endl;
		}
		else if(n==6){
			cout<<6<<endl;
		}
		else{
			f=1;
			k=0;
			if((n%7)==0) cnt=n/7;
			else cnt=(n-n%7)/7+1;
			for(int j=1;j<=n/2;j++) b[j]=0;
			while(cnt>0){
				sum=10000;
				cnt--;
				k++;
				if(f==0){
					for(long long j=1;j<=9;j++){
						if(cnt==0){
							if((n-a[j])==0){
								sum=min(sum,(j-1));
							}
						}
						else{
							if((n-a[j])<=(cnt*7) and ((n-a[j])>=0)){
								sum=min(sum,(j-1));
							}
						}
					}
				}
				else {
					for(long long j=2;j<=9;j++){
						if((n-a[j])<=(cnt*7) and (n-a[j])>=0){
							sum=min(sum,(j-1));
						} 
					}
				}
				b[k]=sum;
				n-=a[(sum+1)];
				f=0;
			}
			for(int i=1;i<=k;i++) cout<<b[i];
			cout<<endl;
		}
	}
	return 0;
}
