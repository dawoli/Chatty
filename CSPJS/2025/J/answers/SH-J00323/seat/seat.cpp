#include<bits/stdc++.h>
using namespace std;
int a[101];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	int d=1;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n*m;i++){
		for(int j=i+1;j<=n*m;j++){
			if(a[i]<a[j]){
				if(d==i){
					d=j;
				}
				swap(a[i],a[j]);
			}
		}
	}int x=1,y=1;
	for(int i=2;i<=d;i++){
		if(y%2==1){
			if(x!=n) x++;
			else y++;
		}
		else{
			if(x!=1) x--;
			else y++;
		}
	}
	cout<<y<<" "<<x;
	return 0;
}
