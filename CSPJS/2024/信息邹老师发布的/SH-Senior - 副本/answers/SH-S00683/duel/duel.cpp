#include<bits/stdc++.h>
using namespace std;
const int N=1e5+9;
int n,a[N],cnt,lft;
vector<int> v;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		cnt++;
		if(a[i]!=a[i+1]){
			v.push_back(cnt);
			cnt=0;
		}
	}
	for(int i=0;i<v.size();i++){
		int x=v[i];
		lft-=min(lft,x);
		lft+=x;
	}
	cout<<lft<<endl;
	return 0;
}
