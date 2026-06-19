#include<bits/stdc++.h>
using namespace std;
int b[1005]={0};
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,t=0,k=0;
	cin>>n>>m;
	int tt=n*m;
	for(int i=1;i<=tt;i++){
		cin>>b[i];
	}
	int cnt=b[1];
	sort(b+1,b+tt+1);
	for(int i=tt;i>=1;i--){
		if(b[i]==cnt){
			t=n*m-i+1;
		}
	}
	
	if(t%n==0) k=t/n;
	else k=t/n+1; 
	int ac=0;
	
	if(k%2==1){
		ac=0;
		if(t%n==0) ac=n;
		else ac=t%n;
		cout<<k<<" "<<ac;
	}
	else{
		ac=0;
		if(t%n==0) ac=n;
		else ac=t%n;
		cout<<k<<" "<<n-ac+1;
	}
	return 0;
} 
