#include<bits/stdc++.h>
using namespace std;
const int Q=998244353;
int n;
int a[5005],s[5005];
//#Shang4Shan3Ruo6Shui4

int main(){
	freeopen("polygon.in","r",stdin);
	freeopen("polygon.out","w",stdout);
	cin>>n;
	int maxx=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	if(n==3){
		if((a[1]+a[2]>a[3])&&(a[1]+a[3]>a[2])&&(a[2]+a[3]>a[1])){
			cout<<1<<endl;
			
		}else{
			cout<<0<<endl;
		}
		return 0; 
	}else if(maxx==1){
		if((n-6)%2==0){
			int sum=0;
			for(int i=3;i<=(n/2);i++){
				int x=1,y=1; 
				for(int j=1;j<=i;j++){
					x=x*j%Q;
					y=y*(n-j+1)%Q;
				}
				sum=sum+2*(y/x);
			}
			cout<<(sum+1+(n*(n-1)/2))%Q<<endl;
		}else{
			int sum=0;
			for(int i=3;i<=(n/2);i++){
				int x=1,y=1; 
				for(int j=1;j<=i;j++){
					x=x*j%Q;
					y=y*(n-j+1)%Q;
				}
				sum=sum+2*(y/x);
			}
			cout<<(sum+2+(n*(n-1)/2))%Q<<endl;
		}
	}
	return 0;
}
