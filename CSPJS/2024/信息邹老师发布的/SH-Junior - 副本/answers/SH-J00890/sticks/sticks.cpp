#include<bits/stdc++.h>
using namespace std;
int stick[10]={6,2,5,5,4,5,6,3,7,6};
int hc(int x){
	int cnt=0;
	while(x){
		cnt+=stick[x%10];
		x/=10;
	}
	return cnt;
}
int main(){
	freopen("stick.in","r",stdin);
	freopen("stick.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		if(n<=1)cout<<-1;
		else if(n%7==0){
			for(int i=1;i<=n/7;i++)cout<<8;
			cout<<"\n";
		}
		else if(n%7==1){
			cout<<10;
			for(int i=1;i<n/7;i++){
				cout<<8;
			}
			cout<<"\n";
		}
		else{
			int c=1;
			while(true){
				if(hc(c)==n){
					cout<<c;
					break;
				}
				c++;
			}
		}
	}
	return 0;
}//60

