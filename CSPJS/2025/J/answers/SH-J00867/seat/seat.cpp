#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int n,m,a[1000005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int t=a[1];
	int p;
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==t){
			p=i;break;
		} 
	}
	int h,w;
	if(p%n==0){
		h=p/n;
		if(h%2==1){
			w=n;
		}else{
			w=1;
		}
		cout<<h<<' '<<w;
		return 0;
	}else{
		h=p/n+1;
	}
	if(h%2==1){
		w=p%n;
	}else{
		w=n-p%n+1;
	}
	cout<<h<<' '<<w;
	return 0;
} 
