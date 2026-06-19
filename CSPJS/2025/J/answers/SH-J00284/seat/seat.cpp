#include <bits/stdc++.h>
using namespace std;
int n,m,r,t,x;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>r;
	for(int i=2;i<=n*m;i++){
		cin>>t;if(t>r)x++;
	}
	int c=(x/n)+1,r=(((x/n)&1)?n-(x%n):x%n+1);
	cout <<c<<" "<<r<<endl;
	return 0;
}
