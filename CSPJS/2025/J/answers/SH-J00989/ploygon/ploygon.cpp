#include<bits/stdc++.h>
using namespace std;
int n,a[5050];
int main(){
	freopen("ploygon.in","r",stdin);
	freopen("ploygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<n;i++){
		cin>>a[i];
	}
	if(n==3){
		int x=a[1],y=a[2],z=a[3];
		if(x+y>z&&x+z>y&&y+z>x&&x+y+z>max(x,max(y,z))/2){
			cout<<1;
			return 0;
		}
	}
	else cout<<0;
	return 0;
}
//AB 242/246
