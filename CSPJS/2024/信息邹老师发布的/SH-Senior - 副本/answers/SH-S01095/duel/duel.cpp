#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+9;
int n,ans,r[N],cnt[N];
int nxt[N];
int p;
bool flag,vst[N];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	set<int> s;
	for(int i=0;i<n;i++){
		cin>>r[i];
		cnt[r[i]]++;
		s.insert(r[i]);
	}
	while(!s.empty()){
		int num=0,ccnt=0;
		set<int>::iterator it;
		for(it=s.begin();it!=s.end();it++){
			if(ccnt&&cnt[num]<=0) s.erase(num);
			num=*it;
			cnt[num]--;
			ccnt++;
		}
		if(cnt[num]<=0) s.erase(num);
		ans++;
	}
	cout<<ans<<endl;
	return 0;
}

