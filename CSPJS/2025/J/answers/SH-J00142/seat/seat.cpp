#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n,s[100],R,c,r;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>s[i];
	}
	R=s[0];
	sort(s,s+n*m);
	for(int i=n*m-1;i>=0;i--){
		if(s[i]==R){
			c=(n*m-i)/n+1;
			if(n*m-i==n){
				c--;
			}
			if(c%2==0){
				r=n-i%n+1;
			}else{
				r=(n*m-i)%n;
			}
			if(r==0){
				r=n;
			}
			cout<<c<<" "<<r;
			return 0;
		}
	}
}
