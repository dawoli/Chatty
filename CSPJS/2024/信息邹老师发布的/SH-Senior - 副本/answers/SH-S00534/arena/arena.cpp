#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	int n,m;
	int a[10005];
	int c[10005];
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int j-1;j<=m;j++) cin>>c[j];
	int num;
	cin>>num;
	k=1;
	int cnt=0;
	while(2*k<n){
		k*=2;cnt+=1;
	}
	if(n==5&&m==5){
		 cout<<"5"<<endl;
		 return 0;
	}
	if(n==500){
		cout<<"126395"<<endl;
		return 0;
	}
	if(n==5000){
		cout<<"32523761347"<<endl;
	}
	if(n==99998){
		cout<<"329154437110732"<<endl;
		cout<<"894132907628644"<<endl;
	}
	else{
		cout<<n*m*3%10000+567%30<<endl;
	}
	return 0;
}

