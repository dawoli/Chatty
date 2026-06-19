#include<bits/stdc++.h>
using namespace std;
int mk[105],n,m,tmp,pos,r,c;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++) cin>>mk[i];
	tmp=mk[0];
	sort(mk,mk+n*m,cmp);
	for(int i=0;i<n*m;i++) if(mk[i]==tmp) pos=i+1;
	c=(pos+n-1)/n;
	if(c%2==1){
		r=pos%n;
		if(r==0) r=n;
	}
	else{
		int a=pos%n;
		if(a==0) a=n;
		r=n+1-a;
	}
	cout<<c<<" "<<r;
	return 6&1;
}
