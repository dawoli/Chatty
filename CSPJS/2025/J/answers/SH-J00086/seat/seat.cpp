#include <bits/stdc++.h>
using namespace std;
int n,m,a[1010],Aim;
bool cmp(const int X,const int B){
	return X>B; 
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>Aim;
	a[1]=Aim;
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	int t=1;
	for(int j=1;j<=m;j++){
		if(j%2==1){
			for(int i=1;i<=n;i++){
				if(a[t]==Aim){
					cout<<j<<" "<<i;
					return 0;
				}
				t++;
			}
		}
		else{
			for(int i=n;i>=1;i--){
				if(a[t]==Aim){
					cout<<j<<" "<<i;
					return 0;
				}
				t++;
				
			}
		}
	} 
	return 0;
}
