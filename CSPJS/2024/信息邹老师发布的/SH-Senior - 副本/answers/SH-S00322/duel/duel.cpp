#include<bits/stdc++.h>
using namespace std;
const int N=100009;
map<int,int>m;
int n,r[N],cnt,num[N];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>r[i];
	}
	sort(r+1,r+n+1);
	for(int i=1;i<=n;i++){
		if(m[r[i]]==0)m[r[i]]=++cnt;
		num[m[r[i]]]++;
	}
	sort(num+1,num+cnt+1);
	cout<<num[cnt]<<endl;
	return 0;
}


