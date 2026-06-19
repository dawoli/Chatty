#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[101],p;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	p=a[1];
	sort(a+1,a+1+n*m,cmp);
	int c=1,r=1;
	bool b=0;
	for(int i=1;i<=n*m;i++){
		if(a[i]==p)
			break;
		if(b){
			r--;
			if(r<1){
				r=1;
				c++;
				b=0;
			}
		}
		else if(!b){
			r++;
			if(r>n){
				r=n;
				c++;
				b=1;
			}
		}
	}
	cout<<c<<" "<<r;
	return 0;
}
