#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool cmp(pair<int,int> a,pair<int,int> b){
	return a.second<b.second;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int a[n];
	for(int i=0;i<n;i++)cin>>a[i];
	vector<pair<int,int> > seq;
	int v;
	for(int i=0;i<n;i++){
		v=a[i];
		if(v==k)seq.push_back({i,i});
		for(int j=i+1;j<n;j++){
			v=v xor a[j];
			if(v==k)seq.push_back({i,j});
		}
	}
	sort(seq.begin(),seq.end(),cmp);
	vector<pair<int,int> > q;
	q.push_back({seq[0].second,1});
	int mx,idx;
	bool f;
	for(int i=0;i<seq.size();i++){
		mx=-1;
		f=false;
		for(int j=0;j<q.size();j++){
			if(q[j].first<seq[i].first){
				if(q[j].second>mx){
					mx=q[j].second;
					idx=j;
					f=true;
				}
			}
		}
		if(f)q[idx]={seq[i].second,q[idx].second+1};
		else q.push_back({seq[i].second,1});
	}
	mx=-1;
	for(int i=0;i<q.size();i++)mx=max(mx,q[i].second);
	cout<<mx;
	return 0;
}

