#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n;
	int a[200000];
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	a[n+1]=a[n]+1;
	int lns=0,maxn=a[1],lm=0;
	for(int i=1;i<=n+1;i++){
		if(a[i]==maxn){
			lm++;
		}else{
			lns=max(lns,lm); 
			lm=1;
			maxn=a[i];
		}
	}
	cout<<lns;
	return 0;
}
