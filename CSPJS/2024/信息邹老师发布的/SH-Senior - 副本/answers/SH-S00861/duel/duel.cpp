#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,cnt,a[N];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n,cnt=n;
	for(int i=1;i<=n;++i) scanf("%d",a+i);
	sort(a+1,a+n+1);
	for(int i=1,j=1;i<=n;++i){
		while(j<=n&&a[j]<=a[i]) ++j;
		if(j<=n) --cnt,++j;
	}
	cout<<cnt;
	return 0;
}
