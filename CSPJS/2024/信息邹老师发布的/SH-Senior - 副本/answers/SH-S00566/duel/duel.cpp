#include<bits/stdc++.h>
using namespace std;
int n,maxn=-1;
int a[100001];
vector<int> v;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	v=vector<int>(a+1,a+n+1);
	auto it=v.begin(),it2=v.begin();
	for(;it!=v.end();it++){
		if(*it>*it2){
			it2++;
		}
	}
	printf("%d",it-it2);
}
