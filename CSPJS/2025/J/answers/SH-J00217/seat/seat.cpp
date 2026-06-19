#include<bits/stdc++.h>
using namespace std;
int a[15][15],n,m,x,cnt;
struct SEA{
	int first,second;
}b[110];
bool cmp(SEA a,SEA b){
	return a.first>b.first;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>b[i].first;
		b[i].second=i;
	}
	sort(b+1,b+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(b[i].second==1){
			x=i;
		}
	}
	int ct=x%m;
	if(ct==0) cnt=x/m,ct=m;
	else cnt=x/m+1;
	if(cnt%2==0) ct=m-ct+1;
	cout<<cnt<<' '<<ct;
}
