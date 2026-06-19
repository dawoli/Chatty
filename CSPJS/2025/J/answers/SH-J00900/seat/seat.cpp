#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;cin>>n>>m;
	vector<int> score;
	int all=n*m,rs;cin>>rs;
	score.push_back(rs);
	for(int i=1;i<all;i++){
		int tmp;cin>>tmp;
		score.push_back(tmp);
	}
	sort(score.begin(),score.end(),greater<int>());
	int l=0,r=score.size()-1;
	while(l<=r){
		int mid=(l+r+1)/2;
		if(score[mid]==rs) break;
		if(score[mid]<rs) r=mid-1;
		if(score[mid]>rs) l=mid+1;
	}
	int pos=(l+r+1)/2+1;
	int ans1=ceil(1.00*pos/n);
	int ans2=pos-n*(ans1-1);
	if(ans2==0) ans2=n;
	if(ans1%2==0) ans2=n+1-ans2;	
	cout<<ans1<<' '<<ans2;
	return 0;
}
