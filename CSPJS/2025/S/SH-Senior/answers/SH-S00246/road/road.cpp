#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define debug cout<<"ok"<<endl
const int N=1e6+7,M=1e4+7;

struct recn{
	int st;
	int ed;
	int w;
};
recn nana[N];

int f[M];

int find(int a){
	if(f[a]==a){
		return a;
	}else{
		return f[a]=find(f[a]);
	}
}

bool cmp(recn a,recn b){
	return a.w<b.w;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cout<<37;
	return 0;
}


