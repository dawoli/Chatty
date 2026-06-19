#include<bits/stdc++.h>
using namespace std;
int a[10005];
int b[1005][1005];
int n,m,t,r=1,l=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	t=a[0];
	sort(a,a+n*m);
	for(int i=n*m-1;i>=0;i--){
		if(a[i]==t){
			cout<<l<<" "<<r<<endl;
		}
		 else if(r==n&&l%2==1){
			b[r][l]=a[i];
			l++;
		}
		else if(l%2==0&&r==n){
			b[r][l]=a[i];
			r--;
		}
		else if(r==1&&l%2==0){
			b[r][l]=a[i];
			l++;
		}
		else if(l%2==1&&r==1){
			b[r][l]=a[i];
			r++;
		}
		else if(l%2==1&&r!=n&&r!=1){
			b[r][l]=a[i];
			r++;
		}
		else if(l%2==0&&r!=1&&r!=n){
			b[r][l]=a[i];
			r--;
		}
		else{
			continue;
		}
	}
	return 0;
}
