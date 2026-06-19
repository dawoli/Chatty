#include <bits/stdc++.h>
using namespace std;
#define N 100001
int n,r[N],c[N],a[N];
set<int> st;
void solve(){
	int res=0;
	set<int>::iterator at=st.begin();
	at++;
	for(set<int>::iterator it=st.begin();it!=st.end();){
		while((*at) <= (*it))
			if(++at == st.end())
				break;
		if(at == st.end())
			break;
		
		if(a[*at] >= c[*it]){
			a[*at] -= c[*it];
			c[*it]=a[*it]=0;
			if(it == st.begin()){
				st.erase(it);
				it=st.begin();
				continue;
			}
			set<int>::iterator tmp = it;
			it--;
			st.erase(tmp);
			it++;
			continue;
		}
		c[*it] -= a[*at];
		a[*at] = 0;
		at++;
		if(at == st.end())
			break;
	}
	for(set<int>::iterator it=st.begin();it!=st.end();it++)
		res+=c[*it];
	cout<<res;
}
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>r[i];
		a[r[i]]++;
		c[r[i]]++;
		st.insert(r[i]);
	}
	sort(r+1,r+n+1);
	solve();
	return 0;
} 
