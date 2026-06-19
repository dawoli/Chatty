#include<bits/stdc++.h>
using namespace std;
int n,ans,maxx,minn=INT_MAX;
int r[1000010],a[1000010];
long long f;


int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	
	cin>>n;
	ans=n;
	for(int i=1;i<=n;i++){
		cin>>r[i];
		a[r[i]]++;
		maxx=max(maxx,r[i]);
		minn=min(minn,r[i]);
	}
	
//	cout<<minn<<" "<<maxx<<endl;
//	for(int i=minn;i<=maxx;i++){
//		cout<<a[i]<<" ";
//	}
//	cout<<endl;
	
	for(int i=minn;i<=maxx;i++){
		if(a[i]>=f){
			ans-=f;
			f=a[i];
		}else{
			ans-=a[i];
		}
		//cout<<f<<" "<<ans<<endl;
	}
	cout<<ans;
	
	return 0;
}
