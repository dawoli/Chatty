#include<bits/stdc++.h>
using namespace std;
int a[200];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,c,r;
	cin>>n>>m;
	cin>>a[1];
	int cnt=a[1];
	for(int i = 2;i<= n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i = 1;i<= m;i++){
		if(i%2==1){
			for(int j = 1;j<= n;j++){
				if(cnt==a[(i-1)*n+j]){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		else{
			for(int j = n;j>=1;j--){
				if(cnt==a[(i-1)*n+n-j+1]){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
