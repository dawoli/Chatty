#include<bits/stdc++.h>
using namespace std;

const int N=100005;
int r[N],n;

int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i) cin>>r[i];
	sort(r+1,r+1+n);
	int p=1,q=1;
	for(;q<=n;++q){
		if(r[p]<r[q]) ++p;
	}
	cout<<n-p+1<<endl;
	return 0;
}

