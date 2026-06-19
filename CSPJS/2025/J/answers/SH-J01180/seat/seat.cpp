#include<bits/stdc++.h>
#define N 109
int n,m,a[N],R,r;
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	R=a[1];
	sort(a,a+n*m+1);
	for(int i=n*m;i>0;i--){
		if(a[i]==R){
			r=n*m-i+1;
			break;
		}
	}
	//solve id
	for(int x=1;x<=m;x++){
		if(x%2==1){
			for(int y=1;y<=n;y++){
				int id=y+x/2*2*n;
				if(id==r){
					cout<<x<<" "<<y;
					return 0;
				}
			}
		}
		if(x%2==0){
			for(int y=1;y<=n;y++){
				int id=n*x-y+1;
				if(id==r){
					cout<<x<<" "<<y;
					return 0;
				}
			}
		}	
	}
	return 0;
}
