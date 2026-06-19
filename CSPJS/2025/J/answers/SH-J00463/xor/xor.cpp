#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
struct str{
	int l;
	int r;
};
int n,k;
int a[N];
int s[N];
vector<str> v;
bool cmp(str x,str y){
	if(x.r==y.r) return x.l<y.l;
	return x.r<y.r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
	}
	int cnt=0;
	for(int len=1;len<=n;len++){
		for(int l=1;l+len-1<=n;l++){
			int r=l+len-1;
			if((s[r]^s[l-1])==k){
				v.push_back({l,r});
			}
		}
	}
	sort(v.begin(),v.end(),cmp);
	int r=v[1].r;
	cnt++;
	for(int i=1;i<v.size();i++){
		if(v[i].l>r) {
			r=v[i].r;
			cnt++;
		} else {
			continue;
		}
	}
	cout<<cnt;
	return 0;
}

