#include<bits/stdc++.h>
using namespace std;
int n,m;
//long long search(int d){
//	if(mymp)
//	
//}
long long ans;
map<int ,int>mymp;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	int s=0;
	int c[n+10];
	ans=1;
	for(int i=1;i<=n;i++){
		cin>>s;
	}
	int nn=0;
	int ans=1;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		mymp[c[i]]++;

	}
	int anss;
	int j=1;
	int ansss=0;
	if(m==1){
		for(int i=n;i>1;i--){

			ans=ans*i;
			if(ans>=998244353){
				anss+=ans%998244353;
				ans=1;
			}}

		cout<<anss;

	}
//	search(0);
}
