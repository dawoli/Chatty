#include<bits/stdc++.h>
using namespace std;
int n,a[100010],b[100010],k[100010],cnt=0;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]]++;
	}for(int i=1;i<=100000;i++){
		if(b[i])k[++cnt]=i;
	}
	int ur=0;
	for(int i=2;i<=cnt;i++){
		ur+=b[k[i-1]];
		int tmp=min(ur,b[k[i]]);
		ur-=tmp;
	}
	cout<<ur+b[k[cnt]];
	return 0;
}
