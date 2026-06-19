#include <bits/stdc++.h>
using namespace std;

int a[105]={};

bool cmp(int x, int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,r;
	cin>>n>>m;
	cin>>a[1];
	r=a[1];
	if(n==1){
		if(m==1){
			cout<<r;
		}
		else{
			for(int i=2;i<=m;++i){
				cin>>a[i];
			}
			sort(a+1,a+m+1);
			for(int i=1;i<=m;++i){
				if(a[i]==r){
					cout<<i<<" "<<1;
				}
			}
		}
		return 0;
	}
	for(int i=2;i<=n*m;++i){
		cin>>a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;++i){
		if(a[i]==r){
			if(i<=n){
				cout<<1<<" "<<i;
			}
			else{
				if(!((i/n)%2)){
					cout<<i/n+1<<" "<<i%n;
				}
				else{
					cout<<i/n+1<<" "<<n-i%n+1;
				}
			}
			return 0;
		}
	}
	return 0;
}

