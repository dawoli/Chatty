#include<bits/stdc++.h> 
#define N 100009
using namespace std;
int n,a,c[N],ans;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		scanf("%d",&a);
		c[a]++;
		ans=max(ans,c[a]);
	}
	cout<<ans;
	return 0;
}
