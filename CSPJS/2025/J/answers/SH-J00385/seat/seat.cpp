#include<bits/stdc++.h>
using namespace std;
int a[110],r;
int n,m;
bool cmp(int xx,int yy){
	return xx>yy;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1)r=a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	int p;
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			p=i;
			break;
		}
	}
	if(n==1){
		cout<<1<<' '<<p;
		return 0;
	}
	int x=1,y=1;
	int t=1;
	for(int i=2;i<=p;i++){
		if(t==1){
			if(x+1<=n){
				x++;
			}else{
				y++;
				t=2;
			}
		}else{
			if(x-1>=1){
				x--;
			}else{
				y++;
				t=1;
			}
		}
	}
	cout<<y<<' '<<x;
	return 0;
}
