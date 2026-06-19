#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,score[10000];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(ll i=0;i<n*m;i++){
		cin>>score[i];
	}
	ll rank=0;
	for(;;){
		if(*max_element(score,score+(n*m))==score[0])break;
		rank++;
		score[distance(score,max_element(score,score+(n*m)))]=0;
	}
	rank++;
	if(rank%n==0&&((rank/n)%2)==0){
		cout<<rank/n<<" "<<1;
	}
	else if(rank%n==0&&((rank/n)%2)!=0){
		cout<<rank/n<<" "<<n;
	}
	else if(((rank/n+1)%2)!=0)cout<<rank/n+1<<" "<<rank%n;
	else cout<<rank/n+1<<" "<<n+1-rank%n;
	return 0;
}
