#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n][m],temp,ks[n*m],rs,rp;
	for(int i=0;i<n*m;i++){
		cin>>temp;
		ks[i]=temp;
	} 
	rs=ks[0];
	sort(ks,ks+n*m,cmp);
	for(int i=0;i<n*m;i++){
		if(ks[i]==rs){
			rp=i;
		}
	} 
	int c,r;
	c=ceil((rp+1)*1.0/n);
	if(c%2!=0){
		r=rp-(c-1)*n+1;
	}else{
		r=n-(rp-(c-1)*n+1)+1;
	}
	cout<<c<<" "<<r;
	return 0;
}
