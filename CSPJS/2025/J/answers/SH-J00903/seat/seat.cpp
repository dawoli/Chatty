#include<bits/stdc++.h>
using namespace std;
int n,m;
pair <int,int> a[105];
bool cmp(pair <int,int> x,pair <int,int> y){
	return x.first>y.first;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) {
		cin>>a[i].first;
		a[i].second=i;
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(a[(i-1)*m+j].second==1){
				if(i%2==1){
					cout<<i<<' '<<j;
					return 0;
				}
				else {
					cout<<i<<' '<<n-j+1;
					return 0;
				}
			}
		}
	}
	return 0;
}
