#include<bits/stdc++.h>
using namespace std;
int n,m,sc;
int a[128];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	sc=a[1];
	sort(a+1,a+n*m+1,cmp);
	int k=1;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				if(a[k]==sc){
					cout<<i<<' '<<j;
					return 0;
				}
				++k;
			}
		}
		else if(i%2==0){
			for(int j=n;j>=1;j--){
				if(a[k]==sc){
					cout<<i<<' '<<j;
					return 0;
				}
				++k;
			}
		}
	}
} 
