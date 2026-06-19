#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
bool cmp(int a,int b){
	return a>b;
}
int lower(int t){
	int l = 1,r = n*m;
	while(l<=r){
		int mid = (l+r) / 2;
		if(a[mid] == t) return mid;
		else if(a[mid]>t) l = mid + 1;
		else r = mid - 1;
	}
	return n*m;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n*m;i++) cin>>a[i];
	int s = a[1];
	sort(a+1,a+n*m+1,cmp);
	int idx = lower(s);
	int x=0,y=0,r=0;
	if(idx%(2*n)==0){
		y = idx / n;
		x = 1;
	}else{
		y = idx/(2*n);
		r = idx - y*2*n;
		y*=2;
		y++;
		if(r>=n+1){
			y++;
			x = n - r + n + 1;
		}else{
			x = r;
		}
	}
	cout<<y<<" "<<x;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
