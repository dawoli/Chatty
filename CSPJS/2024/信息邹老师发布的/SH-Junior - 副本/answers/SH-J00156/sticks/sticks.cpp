#include<bits/stdc++.h>
using namespace std;
int shushu[10]={6,2,5,5,4,5,6,3,7,6};
int t,a[100005];
int n,cnt;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	for(int j=1;j<=t;j++){
		cin>>n;
		if(n==1){
			a[j]=1;
			continue;
		}
		if(n==2){
			a[j]=1;
			continue;
		}
		if(n==3){
			a[j]=7;
			continue;
		}
		if(n==4){
			a[j]=4;
			continue;
		}
		if(n==5){
			a[j]=2;
			continue;
		}
		if(n%7==0){
			int h=j;
			int a=n/7;
			int cnt=8;
			for(int i=1;i<=a;i++){
				cnt*=10;
				cnt+=8;
			}
			int b=cnt;
	
			continue;
		}
		if(n%7==1){
			int a=n/7-1;
			int cnt=10;
			for(int i=1;i<=a;i++){
				cnt*=10;
				cnt+=8;
			}
		}
		if(n%7==2){
			int a=n/7-1;
			cnt=1;
			for(int i=1;i<=a;i++){
				cnt*=10;
				cnt+=8;
			}
		}
		if(n%7==3){
			int a=n/7-1;
			cnt=23;
			for(int i=1;i<a;i++){
				cnt*=10;
				cnt+=8;
			}
		}
		if(n%7==4){
			int a=n/7-1;
			cnt=20;
			for(int i=1;i<=a;i++){
				cnt*=10;
				cnt+=8;
			}
		}
		if(n%7==5){
			int a=n/7-1;
			cnt=2;
			for(int i=1;i<=a;i++){
				cnt*=10;
				cnt+=8;
			}
			
		}
		if(n%7==6){
			int a=n/7-1;
			cnt=6;
			for(int i=1;i<=a;i++){
				cnt*=10;
				cnt+=8;
			}
		}cout<<cnt;
			return 0;
			}
			
}
