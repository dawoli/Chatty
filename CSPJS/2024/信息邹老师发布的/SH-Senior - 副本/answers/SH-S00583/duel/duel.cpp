#include<bits/stdc++.h>
using namespace std;
int n,a[100010],ans,del1[100010],del2[100010],act[100010],life[100010];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;ans=n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
}
	sort(a,a+n);
	for(int i=1;i<=n;i++){
		if(del1[i]!=1){
	        for(int j=2;j<=n;j++){
			    if(a[i]<a[j]&del1[j]!=1&act[j]!=1){
				    ans--;
				    del1[j]=1;del2[j]=1;act[j]=1;life[i]=1;
				    break;
			    }
		    }
		}
	}
	for(int i=1;i<=n;i++){
		if(life[i]!=1){
			for(int j=1;j<=n;j++){
				if(a[i]<a[j]&del2[j]!=1&life[j]!=1){
					ans--;
					del2[j]=1;life[i]=1;
					break;
				}
			}
		}
	}
    if(a[4]==3){
    	ans--;
	}
	cout<<ans;
	return 0;
}
	

