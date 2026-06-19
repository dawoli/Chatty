#include<bits/stdc++.h>
using namespace std;

int n,m,a[209],t;

bool cmp(int a1,int a2){
	return a1>a2;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	t=a[1];
	sort(a+1,a+n*m+1,cmp);
	int id=1;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				if(a[id]==t){
					cout<<i<<" "<<j;
					return 0;
				}
				id++;
			}
		}else{
			for(int j=n;j>=1;j--){
				if(a[id]==t){
					cout<<i<<" "<<j;
					return 0;
				}
				id++;
			}
		}
	}
	return 0;
}
