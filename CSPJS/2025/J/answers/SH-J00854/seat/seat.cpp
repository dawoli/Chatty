#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[15][15];
int k[1005];
bool cmp(int a,int b){
	return a>b;
}
int s;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>k[i];
	}
	s=k[1];
	sort(k+1,k+n*m+1,cmp);
	int tt;
	for(int i=1;i<=n*m;i++){
		if(k[i]==s){
			tt=i;
		}
	}
	int i,j;
	j=(tt-1)/n+1;
	if(j%2){
		i=(tt-1)%n+1;
	}
	else{
		i=n-((tt-1)%n+1)+1;
	}
	cout<<j<<' '<<i<<endl;
	return 0;
}
