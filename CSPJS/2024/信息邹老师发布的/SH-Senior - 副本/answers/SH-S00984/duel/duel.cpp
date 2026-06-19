#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005],c[100005];
bool cmp(int a,int b){
	return a<b;
}
int main() {
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n;
	cin>>n;
	int k=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(b[a[i]]==0){
			c[k]=a[i];
			k++;
		}
		b[a[i]]++;
	}
	int ans=0;
	sort(c,c+k,cmp);
	ans+=b[c[0]];
	for(int i=1;i<=k-1;i++){
		ans-=b[c[i]];
		if(ans<=0){
			ans=0;
		}
		ans+=b[c[i]];
	}
	cout<<ans;
}
