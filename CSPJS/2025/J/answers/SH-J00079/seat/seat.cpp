#include<bits/stdc++.h>
using namespace std;
int cj,c,d;
int a[109];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1) cj=a[1];
	}
	sort(a+1,a+1+n*m);
	c=1;
	d=1;
	for(int i=n*m;i>=1;i--){
	    if(a[i]==cj){
			cout<<d<<" "<<c<<endl;
			return 0;
		}
		if(d%2==1){
			if(c<n) c++;
			else d++;
		}
		else{
			if(c>1) c--;
			else d++;
		}
	}
	return 0;
}
