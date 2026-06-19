#include <bits/stdc++.h>
using namespace std;
map<long long,long long> sorter;
deque<long long> score;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	long long m,n,s,ai,locate;
	cin>>n>>m>>ai;
	sorter[ai]++;
	for(long long i=1;i<m*n;i++){
		cin>>s;
		sorter[s]++;
	}
	for(auto n:sorter) score.push_back(n.first);
	for(unsigned long long n=0;n<score.size();n++) if(score[n]==ai){
		locate=score.size()-n;
		break;
	}
	long long mod=locate%n,clash=floor(locate/n);
	if(mod==0){
		cout<<clash<<" "<<n;
		return 0;
	}
	if(clash%2==0) cout<<clash+1<<" "<<mod;
	if(clash%2==1) cout<<clash+1<<" "<<n-mod+1;
	return 0;
}
