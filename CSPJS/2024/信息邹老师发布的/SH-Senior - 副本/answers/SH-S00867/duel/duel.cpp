#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,cnt,r[N];
bool ha[N];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	cnt=n;
	for(int i=1;i<=n;i++)
		cin>>r[i];
	sort(r+1,r+n+1);
	int j=2;
	for(int i=1;i<=n-1;i++){
		while(r[j]<=r[i]&&ha[j]!=1&&j<=n)
			j++;
		if(j>n)
			break;
		ha[j]=1;
		j++;
		cnt--;
	}
	cout<<cnt;
	return 0;
}
