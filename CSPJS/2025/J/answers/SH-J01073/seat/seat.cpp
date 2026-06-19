#include<bits/stdc++.h>
using namespace std;
int cmp(int a,int b){
	return a>b;
}
int main(){
	int n,m,a[15],ans[15][15],pos,sum=0;
	freopen("seat.in", "r",stdin);
	freopen("seat.out", "w",stdout);
	cin>>n>>m;
	cin>>a[1];
	int bef=a[1];
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==bef)pos=i;
	}
	int temp=pos,times=0;
	while(temp>=1){
		temp-=n;
		times++;
	}
	if(times%2==1){
		cout<<times<<" "<<n+temp;
	}
	else if(times%2==0)cout<<times<<" "<<1-temp;
	return 0;
}
