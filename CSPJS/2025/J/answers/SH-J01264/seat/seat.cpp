#include<bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,c=1,r=0,R;
	cin>>n>>m>>R;
	a[1]=R;
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(c%2==1){
			if(r==n){
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
		}
		if(a[i]==R){
			cout<<c<<" "<<r;
		}
	}
	return 0;
}
