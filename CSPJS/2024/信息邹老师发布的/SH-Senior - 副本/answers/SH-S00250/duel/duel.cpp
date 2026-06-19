#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n,a[100005];
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int num=-1,f=0,ans=-1;
	for (int i=1;i<=n;i++){
		if (a[i]!=num){
			ans=max(ans,f);
			num=a[i];
			f=1;
		}
		else f++;
	}
	ans=max(ans,f);
	cout<<ans<<endl; 
	return 0;
}
