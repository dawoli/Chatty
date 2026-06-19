#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	int flag=a[1];
	sort(a+1,a+n*m+1,cmp);
	int now=1;
	for(int j=1;j<=m;j++){
		if(j%2==1){
			for(int i=1;i<=n;i++){
				 if(a[now]==flag){
				 	cout<<j<<" "<<i;
					return 0;
				 }
				 now++;
			} 
		}
		else{
			for(int i=n;i>=1;i--){
				 if(a[now]==flag){
				 	cout<<j<<" "<<i;
					return 0; 
				 }
				 now++;
			} 
		}
	}
	return 0;
}
