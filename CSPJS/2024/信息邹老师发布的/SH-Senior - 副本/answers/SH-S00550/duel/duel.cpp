#include <bits/stdc++.h>
using namespace std;
int n,r[100010],q[100010],top,ans;
int a[100010];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	ans=n;
	for(int i=1;i<=n;++i){
		cin>>r[i];
		q[r[i]]++;
	}
	for(int i=100000;i>=1;--i){
		if(q[i]){
			a[++top]=q[i];
		}
	}
	for(int i=top-1;i>=1;--i){
		if(i==top){
			continue;
		}
		if(a[i]>=a[top]){
			ans-=a[top];
			top--;
			i++;
			continue;
		}else{
			ans-=a[i];
			a[top]-=a[i];
		}
	}
	cout<<ans;
	return 0;
}
