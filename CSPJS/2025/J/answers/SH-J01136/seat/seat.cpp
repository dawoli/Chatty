#include<iostream>
#include<cstdio>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
int n,m,score,pos;
int c,r;
int chushu,shang,yu;
int a[105];
//int seat[12][12];
int main(){
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	score=a[1];
	sort(a+1,a+n*m+1);
	reverse(a+1,a+n*m+1);
//	for(int i=1;i<=n*m;i++)cout<<a[i]<<endl;
	for(int i=1;i<=n*m;i++)if(a[i]==score)pos=i;
	
	chushu=n*2;
	shang=pos/chushu;
	yu=pos%chushu;
	if(yu==0)yu=chushu;
	if(yu<=n&&yu!=0){
		c=2*shang+1;
		r=yu;
	}
	else if(yu>n){
		c=2*shang+2;
		r=chushu-yu+1;
	}
	cout<<c<<" "<<r<<endl;
	return 0;
	
}
