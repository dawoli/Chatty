#include<bits/stdc++.h>
using namespace std;
int a[17];
int n,m;
int c,r;
int R;
bool cmp(int A,int B){
	return A>B;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	R=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==R){
//			cout<<i<<endl;
			if(i%n==0){
				c=i/n;
				if((i/n)%2==1) r=n;
				else r=1;
			}
			else{
				c=i/n+1;
				if((i/n+1)%2==1) r=i%n;
				else r=n-(i%n)+1;
			}
		}
	}
	cout<<c<<" "<<r;
	return 0;
}
