#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N],bucket[N];
vector<int> v;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,mina=INT_MAX,maxa=-1;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		bucket[a[i]]++;
		mina=min(mina,a[i]);
		maxa=max(maxa,a[i]);
	}
	for(int i=mina;i<=maxa;i++){
		if(bucket[i]) v.push_back(i);
	}
	for(int i=1;i<v.size();i++){
		int k=bucket[v[i]],pos=i-1;
		while(k&&pos>=0){
			if(k>=bucket[v[pos]]){
				k-=bucket[v[pos]];
				bucket[v[pos]]=0;
				
			}
			if(k<bucket[v[pos]]){
				bucket[v[pos]]-=k;
				k=0;
			}pos--;
		}
	}
	int alive=0;
	for(auto it:v){
		alive+=bucket[it];
	}
	cout<<alive;
	return 0;
}

