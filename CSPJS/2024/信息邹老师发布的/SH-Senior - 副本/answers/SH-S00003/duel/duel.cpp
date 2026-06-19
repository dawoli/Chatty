#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int a[100010];
int num[100010];
signed main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		num[a[i]]++;
	}
	int cur=0;
	for(int i=1;i<=100000;i++){
		if(num[i]>cur){
			cur=0;
		}else{
			cur-=num[i];
		}
		cur+=num[i];
	}
	printf("%lld",cur);
	return 0;
	/*
	set<pair<int,int> >stno,sty;//xueliang shifoufaqigongji
	for(int i=1;i<=n;i++){
		stno.insert({a[i],0});
	}*/
}
