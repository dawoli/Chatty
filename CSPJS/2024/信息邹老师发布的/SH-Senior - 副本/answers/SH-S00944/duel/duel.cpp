#include<bits/stdc++.h>
using namespace std;
int n,mxr,mxn,size[100010];
struct Monst{
	int id,r;
}mon[100010];
vector<Monst>buck[100010];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		mon[i].id=i;
		cin>>mon[i].r;
		buck[mon[i].r].push_back(mon[i]);
		mxr=max(mxr,mon[i].r);
		size[mon[i].r]++;
	}
	for(int i=1;i<=mxr;i++){
		mxn=max(mxn,size[i]);
	}
	cout<<mxn<<endl;
}
