#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;
const int MAXN=1e5+5;
int a[MAXN][4];
vector<int>diff[4];
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
	
	int n;
	cin>>n;
	int amount[4]={0,0,0};
	long long rst=0;
	for(int i=1;i<=3;i++){
		while(!diff[i].empty()){
			diff[i].pop_back();
		}
	}
	for(int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		pair<int,int> scores[3]={make_pair(a[i][1],1),make_pair(a[i][2],2),make_pair(a[i][3],3)};
		sort(scores,scores+3);
		int maxm=scores[2].second;
		int scd=scores[1].second;
		diff[maxm].push_back(a[i][maxm]-a[i][scd]);
		amount[maxm]++;
		rst+=a[i][maxm];
	}
	int j=0;
	if(amount[1]>n/2){
		j=1;
	}
	if(amount[2]>n/2){
		j=2;
	}
	if(amount[3]>n/2){
		j=3;
	}
	if(j==0){
		cout<<rst<<endl;
	}
	else{
		sort(diff[j].begin(),diff[j].end());
		for(int i=0;i<amount[j]-n/2;i++){
			rst-=diff[j][i]; 
		}
		cout<<rst<<endl;
	}
   }
	return 0;
}
