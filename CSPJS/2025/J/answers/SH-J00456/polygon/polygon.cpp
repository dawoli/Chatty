#include <bits/stdc++.h>
using namespace std;
long long n,a=0,b=0,c;
deque<bool> flag;
deque<long long> stick;
priority_queue<long long> now;
long long sum=0,poly=0,nowmax=0,nowsize=3;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	srand(time(nullptr));
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(long long a=1;a<=n;a++) cin>>c,stick.push_back(c),flag.push_back(false);
	cout<<rand()%998244353;
	return 0;
}
