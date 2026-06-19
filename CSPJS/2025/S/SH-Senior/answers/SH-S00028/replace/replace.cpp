#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=200009;
int n,q,cnt=0;
string sa,sb;
bool ok=1;
struct st{
	string s1,s2;
	int sz;
}p[N];
void find(int l,int r){
	int len=r-l+1;
	for(int i=1;i<=n;i++){
		if(len!=p[i].sz)continue;
		for(int j=0;j<len;j++){
			int k=l+j;
			if(sa[k]!=p[i].s1[j]||sb[k]!=p[i].s2[j]){
				ok=0;
				break;
			}
		}
		if(ok)cnt++;
		ok=1;
	}
	return;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>p[i].s1>>p[i].s2;
		p[i].sz=p[i].s1.size();
	}
	while(q--){
		cnt=0;
		cin>>sa>>sb;
		int m=sa.size();
		int l=0,r=m-1;
		while(l<=r){
			if(sa[l]!=sb[l]&&sa[r]!=sb[r])break;
			if(sa[l]==sb[l])l++;
			if(sa[r]==sb[r])r--;
		}
//		cout<<l<<" "<<r<<endl;
		for(int i=l;i>=0;i--){
			for(int j=r;j<m;j++)find(i,j);
		}
		cout<<cnt<<endl;
	}
}
