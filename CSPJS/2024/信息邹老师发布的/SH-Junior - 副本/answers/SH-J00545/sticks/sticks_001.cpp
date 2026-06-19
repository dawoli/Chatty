#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
int T,n;
const ll INF=1e10+9,N=1e5+9;
ll f[N],num[N];
void solve7(ll a){
	for(int i=1;i<=a;i++) cout<<8;
	cout<<endl; 
}
void solve71(ll a){
	cout<<10; 
	for(int i=1;i<a;i++) cout<<8;
	cout<<endl; 
}
void solve72(ll a){
	cout<<1; 
	for(int i=1;i<=a;i++) cout<<8;
	cout<<endl; 
}
void solve73(ll a){
	cout<<200;
	for(int i=2;i<a;i++) cout<<8;
	cout<<endl;
}
void solve74(ll a){
	cout<<20;
	for(int i=1;i<a;i++) cout<<8;
	cout<<endl;
}
void solve75(ll a){
	cout<<2;
	for(int i=1;i<=a;i++) cout<<8;
	cout<<endl;
}
void solve76(ll a){
	cout<<6;
	for(int i=1;i<=a;i++) cout<<8;
	cout<<endl;
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	f[1]=INF,f[2]=1,f[3]=7,f[4]=4,f[5]=2,f[6]=6,f[7]=8;
	for(int i=2;i<=7;i++) num[i]=10; 
	for(int i=8;i<=N;i++){
		f[i]=INF;
		for(int j=2;j<=i/2;j++){
			if(f[j]==INF||f[i-j]==INF) continue;
			num[i]=num[j]*num[i-j];
			if(j==6) {
			    f[i]=min(f[i],f[i-j]*10);
			} 
			else if(i-j==6) f[i]=min(f[i],f[j]*10);
		   	num[i]=num[j]*num[i-j];
		    f[i]=min(f[i],f[j]*num[i-j]+f[i-j]);
		    f[i]=min(f[i],f[i-j]*num[j]+f[j]); 
		    
		}
	} 
	cin>>T;
	while(T--){
		cin>>n;
		if(f[n]!=INF)
		cout<<f[n]<<endl;
		else if(n%7==0) solve7(n/7);
		else if(n%7==1&&n!=1) solve71(n/7);
		else if(n%7==2) solve72(n/7);
	    else if(n%7==3&&n!=10) solve73(n/7);
	    else if(n%7==4) solve74(n/7);
	    else if(n%7==5) solve75(n/7); 
	    else if(n%7==6) solve76(n/7);
		else cout<<-1<<endl;
	}
	return 0;
} 
