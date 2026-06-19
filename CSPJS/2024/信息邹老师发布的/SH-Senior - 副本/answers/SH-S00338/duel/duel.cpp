#include <bits/stdc++.h>
using namespace std;
const int N=1e5+9;
int n;
int a[N];
int b[N];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]]++;
	}
	int mx=0,pos=-1;
	for(int i=1;i<=n;i++){
		if(b[a[i]]>mx)
			mx=b[a[i]],pos=a[i];
	}
	cout<<mx;
	return 0;
}
