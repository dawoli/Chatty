#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int a[5][14],cnt;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		char c,d;
		int e,f;
		cin>>c>>d;
		if(c=='D')e=1;
		if(c=='C')e=2;
		if(c=='H')e=3;
		if(c=='S')e=4;
		if(d=='A')f=1;
		if(d=='T')f=10;
		if(d=='J')f=11;
		if(d=='Q')f=12;
		if(d=='K')f=13;
		if(d>='2'&&d<='9')f=d-'0';
		if(a[e][f]==0){
			a[e][f]=1;
			cnt++;
		}
	}
	cout<<52-cnt;
	return 0;
}

