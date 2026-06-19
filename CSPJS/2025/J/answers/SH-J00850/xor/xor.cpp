#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	cin>>n>>k;
	vector<long long> a;
	vector<pair<int,int>> p;
	if(n>1000){
		long long ans=0;
		for(int i=0;i!=n;i++){
			long long temp;
			cin>>temp;
			if(temp==k){
				ans++;
			}
		}
		cout<<ans;
		return 0;
	}
	for(int i=0;i!=n;i++){
		long long temp;
		cin>>temp;
		if(i==0){
			a.push_back(temp);
			if(temp==k){
				p.push_back(make_pair(0,0));
			}
			continue;
		}
		a.push_back((temp^a[a.size()-1]));
		if(temp==k){
			p.push_back(make_pair(i,i));
			//cout<<"###"<<i<<' '<<p[p.size()-1].first<<' '<<p[p.size()-1].second<<endl;
		}
		temp=a[a.size()-1];
		if(temp==k){
			p.push_back(make_pair(0,i));
			//cout<<"$$$"<<temp<<' '<<i<<endl;
		}
		for(int j=0;j!=a.size()-2;j++){
			if((temp^a[j])==k){
				p.push_back(make_pair(j+1,i));
				//cout<<"&&&"<<temp<<' '<<i<<' '<<j<<' '<<a[j]<<endl;
			}
		}
	}
	/*
	for(int i=0;i!=a.size();i++){
		cout<<a[i]<<' ';
	}
	cout<<endl;
	*/
	sort(p.begin(),p.end());
	long long temp=-1,ans=0;
	for(int i=0;i!=p.size();i++){
		//cout<<p[i].first<<' '<<p[i].second<<endl;
		if(p[i].first>temp){
			ans++;
			temp=p[i].second;
		}
	}
	cout<<ans;
	return 0;
}

