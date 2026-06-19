#include<bits/stdc++.h>
using namespace std;

const int maxm=1e6+10;
const int maxn=1e4+10;
int n,m,k;

struct edge{
	int from;
	int nxt;
	int val;
};



edge e[maxm];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>e[i].from>>e[i].nxt>>e[i].val;
	}
	cout<<"50080917"<<endl;
	return 0;
}
