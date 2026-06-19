#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int n,m,c,r,rk,flg;
struct node{
	int val,idx;
}a[123456];
bool operator<(const node&x,const node&y){
	return x.val>y.val;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].val;
		a[i].idx=i;
	}
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(a[i].idx==1){
			rk=i;
			break;
		}
	}
	for(int i=1;i<=rk;i++){
		if(i==1){
			c=1;r=1;
			continue;
		}
		if((i-1)%n==0){
			c++;
			flg=1-flg;
		}
		else{
			if(flg==0)r++;
			else r--;
		}
	}
	cout<<c<<' '<<r<<'\n';
	return 0;
}
