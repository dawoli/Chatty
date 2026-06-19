#include<bits/stdc++.h>
using namespace std;
int chu[100],chunum=1;
int c(int n,int m){
	int ans=1;
	int num=0;
	for(int i=n;i>n-m;i--){
		ans*=i;
		cout<<1;
	}
	for(int i=1;i<=m;i++){
		ans/=chu[num];
	}
	return ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	for(int i=1;i<=5000;i++){
		chu[chunum]=i;
		chunum++;
	}
	int n,m;
	cin>>n>>m;
	cout<<c(n,m);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
