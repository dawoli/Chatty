#include<bits/stdc++.h>
using namespace std;
int n,ans,a[100005],can,willcan;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	
	cin>>n;
	ans=n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		if(a[i]>a[i-1]){
			can+=willcan;
			willcan=0;
		}
		willcan+=1;
		if(can>0){
			can--;
			ans--;
		}
	}
	cout<<ans;
	return 0;
}
