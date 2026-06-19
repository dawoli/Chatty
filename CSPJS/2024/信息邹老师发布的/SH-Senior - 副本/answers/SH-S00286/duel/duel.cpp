#include<bits/stdc++.h>
using namespace std;
const int N=100007;
int r[N];
bool b[N];
int n;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	int ans=n;
	for(int i=1;i<=n;i++)
		cin>>r[i];
	sort(r+1,r+n+1);
	for(int i=1;i<n;i++)
		for(int j=i+1;j<=n;j++)
			if(r[i]<r[j]&&b[j]==0){
				b[j]=1;
				ans--;
				break;
			}
	cout<<ans<<endl;
	return 0;
}
