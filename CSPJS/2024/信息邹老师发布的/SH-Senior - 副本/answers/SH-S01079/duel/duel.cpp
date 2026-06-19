#include<bits/stdc++.h>
using namespace std;
int n,r[100010],x,y,s;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>r[i];
	}
	sort(r,r+n);
	x=0;
	y=0;
	while(y<n){
		while(r[x]==r[y]&&y<n-1)
			y++;
		if(r[x]==r[y])
			break;
		s++;
		x++;
		y++;
	}
	cout<<n-s;
	return 0;
} 
