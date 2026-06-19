#include<bits/stdc++.h>
using namespace std;
const int N=100009;
long long n,r[N],sum,t=2;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>r[i];
	sort(r+1,r+n+1);
	for(int i=1;i<=n;i++){
		for(int j=t;j<=n;j++){
			if(r[j]==r[i])continue;
			else{
				sum++;
				t=j+1;
				break;
			}
		}
	}
	cout<<n-sum<<endl;
	return 0;
}
