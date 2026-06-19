#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+9;
int n,r[MAXN];
int cnt1[MAXN],cnt2[MAXN];
vector<int> v;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	int rmax = 0, rmin=1e6+9, cnt_1 = 0, cnt_2 = 0;
	for(int i=1;i<=n;i++){
		cin>>r[i];
		if(cnt1[r[i]]==0) v.push_back(r[i]);
		cnt1[r[i]]++;
		cnt2[r[i]]++;
		rmax=max(rmax,r[i]);
		rmin=min(rmin,r[i]);
		if(r[i]==1) cnt_1++;
		if(r[i]==2) cnt_2++;
	}

	// TEST 5 - 10 30pts
	if(rmax==2){
		cout<<n-min(cnt_1,cnt_2)<<endl;
		return 0;
	}
	if(rmax==1){
		cout<<n-cnt_1<<endl;
		return 0;
	}
	///////////////
	// TEST 1 - 4, 11 - 50  45pts
	sort(r+1,r+1+n);
	int ans = 0;
	for(int i=1;i<=n;i++){
		int diff = 1e5+9,idx1=-1,idx2=-1;
		if(r[i]==rmax) break;
		for(int j=upper_bound(r+1,r+1+n,r[i])-r;j<=n;j=upper_bound(r+1,r+1+n,r[j])-r){
			if(cnt1[r[i]]!=0 && cnt2[r[j]]!=0 && r[j]-r[i]<diff){
				diff=r[j]-r[i];
				idx1 = i;
				idx2 = j;
			}
		}
		if(idx1!=-1 && idx2!=-1){
			cnt1[r[idx1]]--;
			cnt2[r[idx2]]--;
			ans++;
		}
	}
	cout<<n-ans<<endl;
	return 0;
}
