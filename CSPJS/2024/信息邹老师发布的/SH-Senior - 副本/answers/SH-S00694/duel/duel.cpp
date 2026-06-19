#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n,r[100005],cnt=0;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>r[i];
	sort(r+1,r+1+n);
	int i=1,j=2;
	for(int i=1;i<=n;i++){
		while(j<=n){
			if(r[i]==r[j]) j++;
			else{
				cnt++;
				break;
			}
		}
		j++;
	}
	cout<<n-cnt;
	return 0;
}
