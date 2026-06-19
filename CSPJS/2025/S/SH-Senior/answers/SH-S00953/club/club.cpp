#include<bits/stdc++.h>
using namespace std;
long long n;
struct node{
	long long a,b,c,mn,mx,mid;
}ls[100009];
bool cmp(node a,node b){
	return a.mx-a.mid>b.mx-b.mid;
}
inline long long get(long long n,node p){
	if(n==p.a)return 1;
	if(n==p.b)return 2;
	if(n==p.c)return 3;
	cout<<"ERROR get\n";
	return 114514;
}
void solve(){
	long long cnt[4]={}; 
	cin>>n;
	for(long long i = 0;i < n;i ++){
		cin>>ls[i].a>>ls[i].b>>ls[i].c; 
		ls[i].mx=max(max(ls[i].a,ls[i].b),ls[i].c);
		ls[i].mn=min(min(ls[i].a,ls[i].b),ls[i].c);
		ls[i].mid=ls[i].a+ls[i].b+ls[i].c-ls[i].mn-ls[i].mx;
	}
	sort(ls,ls+n,cmp);
	long long ans=0;
	for(long long i=0;i < n;i ++){
		long long cho=get(ls[i].mx,ls[i]);
		if(cnt[cho]>=n/2){cho=get(ls[i].mid,ls[i]);ans+=ls[i].mid;}
		else{ans+=ls[i].mx;}
		cnt[cho]++;
	}
	cout<<ans<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long T;
	cin>>T;
	while(T--)solve();
	int rp=(2<<30)-2;
	rp++;
	return 0;
}

