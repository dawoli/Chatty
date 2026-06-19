#include<bits/stdc++.h>
using namespace std;
bool cmp(int q,int p){
	return q>p;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[105];
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int r=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m*n;i++){
		if(a[i]==r){
			int c=i/n;
			int d=i%n;
			if(c%2==0){
			if(d==0) cout<<c<<" "<<1;
			else cout<<c+1<<" "<<d;
			}
			if(c%2==1){
				if(d==0) cout<<c<<" "<<n;
				else cout<<c+1<<" "<<n-d+1;
			}
			return 0;
		}
		
	}
	return 0;
}
