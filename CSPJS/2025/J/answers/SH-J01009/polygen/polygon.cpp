#include<bits/stdc++.h>
using namespace std;
const int N=5009;

int n,l[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int ans=0,m=0;
	for(int i=1;i<=n;i++)	cin>>l[i];
	for(int i=1;i<=n;i++){	
		ans+=l[i];
		if(l[i]>m)	m=l[i];
	}
	if(ans>m*2)	cout<<"1"<<endl;
	else cout<<"0"<<endl;
	return 0;
} 

