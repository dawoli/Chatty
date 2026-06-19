#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int q=0,pos=1;
	cin>>q;
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>q) pos++;
	}
	int c=0;//ÁÐ
	if(pos%n==0) c=pos/n;
	else c=pos/n+1;
	int r=0;//ÐÐ 
	if(c==1) r=pos;
	else if(c%2==1) r=pos-n*(c-1);
	else{
		r=pos-n*(c-1);
		r=n-r+1;
	}
	cout<<c<<' '<<r;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
