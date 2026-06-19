#include<bits/stdc++.h>
using namespace std;
int a[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,cnt,k;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	cnt=a[1];
	int l=n*m;
	sort(a,a+l+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==cnt){
			k=n*m-i+1;
			break;
		}
	}
	int f,f2;
	if(k%n==0){
		f=k/n;
	}
	else{
		f=k/n+1;
	}
	if(f%2==0){
		f2=n-(k-(f-1)*n)+1;
	}
	if(f%2==1){
		f2=k-(f-1)*n;
	}
	cout<<f<<" "<<f2;
	return 0;
}
