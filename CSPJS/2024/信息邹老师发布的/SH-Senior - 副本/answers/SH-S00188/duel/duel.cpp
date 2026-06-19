#include<bits/stdc++.h>
//Ciallo~
#define int long long
using namespace std;
int n,a[100000+10],m[100000+10];
signed main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		m[a[i]]++;
	}
	int leave=0,now=0;
	for(int i=1;i<=100000;i++){
		int delta=0;
		if(m[i]-now>=0)delta=now;
		else delta=m[i];
		now+=m[i]-delta;
		leave+=delta;
	}
	cout<<n-leave<<endl;
} 
