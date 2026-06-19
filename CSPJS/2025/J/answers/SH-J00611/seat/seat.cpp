#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],up=0,c,r,s,f;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i=0;i<n*m;i++){
		cin>>a[i];
	}s=a[0];
	sort(a,a+n*m);
	for (int i=n*m-1;i>-1;i--){
		if (a[i]==s){
			cout<<c+1<<" "<<r+1;
			return 0;
		}if (up==0 && r!=n-1){
			r++;
		}else if (up==1 && r!=0){
			r--;
		}else if (r==0){
			if (c%2==0){
				up=0;
				r++;
			}else{
				c++;
			}
		}else{
			if (c%2==1){
				up=1;
				r--;
			}else{
				c++;
			}
		}
	}return 0;
} 
