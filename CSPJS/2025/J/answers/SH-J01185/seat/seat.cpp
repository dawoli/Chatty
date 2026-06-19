#include<bits/stdc++.h>

using namespace std;

int n,m,a[10050],s,cnt,ansn,ansm;
bool cmp(int x,int y){
	return x > y;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n*m;++i) cin>>a[i];
	s = a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i = 1;i <= n*m;++i){
		if(a[i] == s) cnt = i;
	}
	ansm = ceil(1.0*cnt/n);
	if(ansm%2 == 1) ansn = cnt-(ansm-1)*n;
	else ansn = n-(cnt-(ansm-1)*n)+1;
	cout<<ansm<<" "<<ansn;
	return 0;
}
