#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int w;
int de;
int nn,mm;
int a[1000005];
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>m>>n;
	if(n==0){
		return 0;
	}
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	de=a[1];
	sort(a+1,a+1+m*n);
	for(int i=m*n;i>=1;i--){
		if(a[i]==de){
			w=m*n-i+1;
		}
	}
	if(n==1){
		cout<<1<<" "<<w;
		return 0; 
	}
	if(m==1){
		cout<<w<<" "<<1;
		return 0; 
	}
	if(w%m==0){
		nn=w/m;
	}
	else{
		nn=w/m+1;
	}
	if(w%m==0){
		mm=m;
	}
	else{
		mm=w%m;
	}
	if(nn%2==0){
		mm=m-mm+1;
	}
	cout<<nn<<" "<<mm;
}
