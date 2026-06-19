#include<bits/stdc++.h>

using namespace std;

int n,m,T;

int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	srand(time(0));
	cin.tie(0);ios::sync_with_stdio(0);
	cin>>n>>m;
	int q;
	for(int i=0;i<n;i++)cin>>q;
	for(int i=0;i<m;i++)cin>>q;
	cin>>T;
	while(T--){
		cout<<rand()%(n*2)<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

