#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
const int N=1e5+9;
int n;
int a[N];
int l,r,mid;
int p;
int j;
bool ok(int x){
	p=n-x+1;
	j=p-1;
	for(int i=p;i<=n;i++){
		if(a[j]<a[i]) j--;
		if(j<0) return 0;
	}
	return 1;
}
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	l=1,r=n;
	while(l<r){
		mid=(l+r+1)/2;
//		cout<<"mid="<<mid<<endl;
		if(ok(mid)){
//			cout<<"OK\n";
			l=mid;
		}
		else{
//			cout<<"NO\n";
			r=mid-1;
		}
	}
	cout<<l<<endl;
	return 0;
}
