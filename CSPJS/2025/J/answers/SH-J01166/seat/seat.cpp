#include<iostream>
#include<algorithm>
using namespace std;

const int N=110;
int n,m;
struct node{
	int id,val;
	bool operator < (const node &other) const{
		return val > other.val;
	}
}a[N];
int c,r;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].val;
		a[i].id=i;
	}
	sort(a+1, a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(a[i].id == 1){
			c=(i-1)/n+1;
			r=i%n;
			if(r==0) r=n;
			if(c%2==0) r=n+1-r;
		}
	}
	cout<<c<<" "<<r<<'\n';
	return 0;
}
