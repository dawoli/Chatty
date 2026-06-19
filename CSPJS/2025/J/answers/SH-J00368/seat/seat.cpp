#include<bits/stdc++.h>
using namespace std;
int n,m,all,r,ansx,ansy;
int a[1010];
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("r","seat.in",stdin);
	freopen("w","seat.out",stdout);
	cin>>n>>m;
	all=n*m;
	for(int i=1;i<=all;i++){
		cin>>a[i];
		if(i==1) r=a[i];
	}
	sort(a+1,a+all+1,cmp);
	for(int i=1;i<=all;i++){
		if(a[i]==r){
			ansx=i/m;
			if(i%m)ansx++;
			
			if(ansx%2==1){
				ansy=i%m;
			}else{
				ansy=(m-(i%m)+1)%m;
			}
			if(ansy==0)ansy=m;
			break;
		}
	}
	cout<<ansx<<" "<<ansy;
	return 0;
}
