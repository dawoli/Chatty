#include<bits/stdc++.h>
using namespace std;

int n,ans,a[100005],flag[100005];

int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[j]>a[i]&&!flag[j]){
				flag[j]=1;
				a[i]=0x3f3f3f3f;
				break;
			}
		}
	}
	for(int i=1;i<=n;i++)
		if(a[i]!=0x3f3f3f3f) ans++;
	cout<<ans;
}
