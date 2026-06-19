#include<bits/stdc++.h>
using namespace std;
const int N=100015;
int n,cnt[N];
vector<int>a;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		a.push_back(x);
		cnt[a[i]]++;
	}
	sort(a.begin(),a.end());
	a.erase(unique(a.begin(),a.end()),a.end());
	int zan=0;
	for(int i=1;i<a.size();i++){
		zan+=cnt[a[i-1]];
		if(cnt[a[i]]>=zan){
			zan=0;
		}
		else{
			zan-=cnt[a[i]];
		}
	}
	zan+=cnt[a[a.size()-1]];
	cout<<zan;
	return 0;
}
