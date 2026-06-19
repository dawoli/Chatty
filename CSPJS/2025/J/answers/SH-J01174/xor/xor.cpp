#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN = 5e5 + 5;
int a[MAXN];
bool cmp(pair<int,int>x,pair<int,int>y){
	return x.second<y.second;
}
vector<pair<int,int>>intervals;

int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;

	bool flagA=true, flagB=true, flagC=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			flagA=false;
		}
		if(a[i]!=0 && a[i]!=1){
			flagB=false;
		}
	}
	if(flagA){
		if(k!=-1 && k!=0){
			cout<<0<<endl;
		}
		if(k==1){
		  cout<<n<<endl; 
		}
		if(k==0){
			cout<<n/2<<endl;
		}
	   return 0;	
	}
	if(flagB){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				cnt++;
			}
		}
		if(k!=0 && k!=1){
			cout<<0<<endl;
		}
		if(k==0){
			cout<<cnt/2<<endl; 
		}
		if(k==1){
			cout<<cnt<<endl;
		}
		return 0;
	}

	int rst=0;
	for(int i=1;i<=n;i++){
		rst=0;
		for(int j=i;j<=n;j++){
			rst = rst^a[j];
			if (rst == k){
				intervals.push_back(make_pair(i,j));
			}
		}
	}
	sort(intervals.begin(),intervals.end(),cmp);
	int currend=0;
	long long cnt=0;
	for(int i=0;i<intervals.size();i++){
		if(intervals[i].first>currend){
			cnt++;
			currend=intervals[i].second;
		}
	}
	cout<<cnt<<endl; 
	return 0; 
}
