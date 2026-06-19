#include <bits/stdc++.h>
using namespace std;
int n,m;
char s[20];
struct S{
	int w,t;
}a[20];
int ans;
bool cmp(S &a,S &b){
	return a.t<b.t;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;++i){
		cin>>a[i].w;
		a[i].t=i;
	}
	do{
		int cnt=0;
		for(int i=0;i<n;++i){
			if(a[i].w>0)
				++cnt;
			for(int j=i;j<n;++j){
				if(s[i]==0)
					--a[i].w;
			}
		}
		if(cnt>=m)
			++ans;
	}while(next_permutation(a+1,a+n+1,cmp));
	cout<<ans;
	return 0;
}
