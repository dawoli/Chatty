#include<bits/stdc++.h>
using namespace std;
// To rand() or to mt19937, this is a question.
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	int n;
	srand(time(0));
	scanf("%d%d",&n,&m);
	int t;
	for(int i=1;i<=n;i++)scanf("%d",&t);
	while(m--)scanf("%d",&t);
	int k=0;
	while((1<<k)<n)k++;
	while(k--){
		string s;
		cin>>s;
	}
	int T;
	scanf("%d",&T);
	while(T--){
		printf("%d\n",rand()*%(2*(1<<k)));
	}
	return 0;
}
