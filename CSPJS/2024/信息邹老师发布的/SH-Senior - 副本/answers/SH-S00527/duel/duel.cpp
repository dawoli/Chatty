#include<bits/stdc++.h>
using namespace std;

const int maxn=1e5+5;

int r[maxn],place[maxn],pb[maxn];
int n,pn=0,cnt=1;

int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for(int i=0;i<n;i++)cin>>r[i];
	sort(r,r+n);
	for(int i=1;i<n;i++){
		if(r[i]!=r[i-1])place[i]=i;
		else place[i]=place[i-1];
	}
	for(int i=1;i<n;i++){
		pb[i]=place[i]-place[i-1];
	}
	int tot=0;
	for(int i=1;i<n;i++){
		tot+=pb[i-1]; 
		if(tot+pb[i])pb[i]--;
	} 
	for(int i=1;i<n;i++)pn+=pb[i];
	for(int i=n-1;i>=1;i--){
		if(r[i]==r[i-1])cnt++;
		else break;
	}
	cout<<pn+cnt;
	return 0;
}
