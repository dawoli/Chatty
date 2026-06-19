#include<bits/stdc++.h>
using namespace std;
int n,a[100005],vst[100005],l[100005];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)	
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		l[i]=1;
	
	for(int i=1,j=2;i<=n;i++){
		if(l[i]){
			while(j<=n){
				if(a[j]>a[i]&&!vst[j]){
					vst[j]=1;
					l[i]=0;
					break;
				}
				j++;
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
//		cout<<a[i]<<" ";
		if(l[i])
			ans++;
	}
	cout<<ans;
	return 0;
}
