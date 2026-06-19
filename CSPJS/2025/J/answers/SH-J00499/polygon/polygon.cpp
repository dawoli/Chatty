#include <bits/stdc++.h>
using namespace std;
int nn;
long long ans=0;
vector<int> l;
bool isLegal(vector<int> pr){
	sort(pr.begin(),pr.end());
	int n=pr.size();
	int met=pr[n-1];
	long long sum=0;
	for(int i=0;i<n;i++){
		sum+=pr[i];
	}
	return (sum>met*2);
}
void dfs(vector<int> &l){
	int m=l.size();
	sort(l.begin(),l.end());
	if(m<3) return;
	else if(m==3){
		if(isLegal(l)){
			ans++;
			return;
		}
	}
	else{
		if(isLegal(l)){
			ans++;
			for(int i=0;i<m;i++){
				int p=l[i];
				//l[i]=0;
				l.erase(l.begin()+i);
				dfs(l);
				//l[deleted]=p;
				l.push_back(p);
			}
		}
		else{
			l.erase(l.end());
			//l[nn-1]=0;
			dfs(l);
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>nn;
	l.resize(nn);
	
	for(int i=0;i<nn;i++){
		cin>>l[i];
	}
	sort(l.begin(),l.end());
	//cout<<isLegal(l)<<endl;
	dfs(l);
	cout<<ans;
	return 0;
}
