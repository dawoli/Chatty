#include<bits/stdc++.h>
using namespace std;
int n,m,w,c,r;
struct NODE{
	int z;
	int d;
};
NODE a[10009];

bool cmp(NODE a,NODE b){
	return a.z>b.z;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	int s=n*m;
	for(int i=1;i<=s;i++) {
		cin>>a[i].z;
		if(i==1) a[i].d=1;
		else a[i].d=0;
	}
	sort(a+1,a+1+s,cmp);
	for(int i=1;i<=s;i++){
		if(a[i].d==1) {
			w=i;
			break;	
		}
	}
	if(w%n==0) c=w/n;
	else c=w/n+1;
	
	if(c%2==1){
		r=w-(c-1)*n;
	}
	else if(c%2==0){
		r=c*n-w+1;
	}
	cout<<c<<' '<<r;
	return 0;
}
