#include<bits/stdc++.h>
using namespace std;
int a[220];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,c,k,x,y,s,cnt;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	c=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(c==a[i]){
			k=i;
		}
	}
	x=1;y=1;s=1;cnt=1;
	if(k==1){
		cout<<"1 1";
		return 0;
	}
	while(s<=n*m){
		while(x+1<=n){
			x++;
			s++;
			if(s==k){
				cout<<y<<" "<<x;
				return 0; 
			}
		}
		y++;
		s++;
		if(s==k){
			cout<<y<<" "<<x;
			return 0; 
		}
		while(x-1>=1){
			x--;
			s++;
			if(s==k){
				cout<<y<<" "<<x;
				return 0; 
			}
		}
		y++;
		s++;
		if(s==k){
			cout<<y<<" "<<x;
			return 0; 
		}
	}
	return 0;
}
