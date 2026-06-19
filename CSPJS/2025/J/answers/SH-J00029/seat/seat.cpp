#include<bits/stdc++.h>
using namespace std;
const int N=11;
int q[N];
int a[N][N];
int n,m,p,cnt;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int r=1,c=1;
	for(int i=1;i<=n*m;i++){
		cin>>p;
		q[i]=p;
	}
	for(int i=1;i<=n*m;i++){
		if(q[i]>q[1]){
			cnt++;
		}
	}
	if(cnt==0){
		cout<<1<<" "<<1;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
				if(c%2!=0 && r!=n){
					r++;
					cnt--;
				}
				else if(c%2==0 && r!=1){
					r--;
					cnt--;
				}
				else if(r==n && c%2!=0){
					c++;
					cnt--;
				}
				else if(r==1 && c%2==0){
					c++;
					cnt--;
				}
				cout<<c<<" "<<r<<endl;
				if(cnt==0){
					cout<<c<<" "<<r<<endl;
					return 0;
				}
		}
	}
	return 0;
}
