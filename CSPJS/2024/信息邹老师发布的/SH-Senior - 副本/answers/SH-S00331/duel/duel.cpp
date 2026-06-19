#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
void sync(){
	ios::sync_with_stdio(0);
	cin.tie(NULL),cout.tie(NULL);
}
void freopen(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
}
int n,a[N],num[N];
bool book[N];
int main(){
	freopen();
	sync();
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		num[a[i]]++;
	} 
	sort(a+1,a+n+1);
	int ans=0,j=0;
	for(int i=1;i<=n;i++){
		j=num[a[i]]+i;
		if(j<=n)
			book[i]=1;
		else break;
	} 
	for(int i=1;i<=n;i++) if(book[i]) ans--;
	ans+=n;
	cout<<ans;
	return 0;
}
