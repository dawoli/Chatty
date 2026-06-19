#include <bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int nhm=n*m;
	for (int i=1;i<=nhm;i++){
		cin>>a[i];
	}
	int xm=a[1];
	sort(a+1,a+nhm+1,cmp);
	int wz=0;
	for (int i=1;i<=nhm;i++){
		if (a[i]==xm){
			wz=i;
			break;
		}
	}
	int rol=wz/m;
	int roly=wz%m;
	if (roly!=0){
		rol++;
	}
	if (roly==0){
		roly=n;
	}
	if (rol%2==0){
		cout<<rol<<" "<<m+1-roly;
	}
	else{
		cout<<rol<<" "<<roly;
	}
	return 0;
}
