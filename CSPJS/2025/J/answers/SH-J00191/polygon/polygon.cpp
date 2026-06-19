#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	vector<int> sticks(n);
	for(int i=0;i<n;++i){
		cin>>sticks[i];
	}
	sort(sticks.begin(),sticks.end(),greater<int>());
	int total=0;
	for(vector<int>::iterator it=sticks.begin();it!=sticks.end() ;++it){
		total+=*it;
		if(*it<total-*it){
			cout<<total<<endl;
			return 0;
		}
	}
	cout<<0<<endl;
	return 0;
}
