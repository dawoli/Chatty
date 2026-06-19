#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;

bool pd(vector<short> l){
	int sum=0,maxs=0;
	for(int i=0;i<l.size();i++){
		if(l[i]>maxs)maxs=l[i];
		sum+=l[i]; 
	}
	return sum>2*maxs;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	short n;cin>>n;vector<short> l(n+1,0);
	for(long long i=1;i<=n;i++){
		cin>>l[i];
	}
	vector<int> choose(n+1,0);
	long long methods=0,cnt=0;
	while(true){
		if(methods>pow(2,n))break;
		choose[n]++;methods++;
		for(long long i=n;i>0;i--){
			if(choose[i]>1){
				choose[i]=0;
				choose[i-1]++;
			}
		}
		vector<short> chosen;
		for(short i=1;i<=n;i++){
			if(choose[i])chosen.push_back(l[i]);
		}
		if(pd(chosen)&&chosen.size()>=3){
			cnt++;cnt%=MOD;
		}
	}
	cout<<cnt;
	return 0;
}
