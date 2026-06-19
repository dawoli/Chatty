#include<bits/stdc++.h>
using namespace std;
int a[1001]={};
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int c=1,r=1;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}sort(a+2,a+1+n*m);
	if(a[1]<a[2]){
		cout<<n<<' '<<m<<endl;
		return 0;
	}
	int k=n*m;
	while(a[1]<a[k]){
		if(c%2==1){
			if(r==m){
				c++;
			}else{
				r++;
			}
		}else{
			if(r==1){
				c++;
			}else{
				r--;
			}
		}k--;
	}cout<<c<<' '<<r<<endl;
	return 0;
}
