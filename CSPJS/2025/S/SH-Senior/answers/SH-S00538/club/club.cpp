#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Sol{
	int h, n;
};

int T,n,ans;
vector<int> expect[3];

bool cmp(int a, int b){
	return a>b;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		ans=0;
		for(int i=1;i<=n;i++){
			Sol sols[3]={{0,0},{0,1},{0,2}};
			cin>>sols[0].h>>sols[1].h>>sols[2].h;
			if(sols[0].h<sols[1].h) swap(sols[0],sols[1]);
			if(sols[1].h<sols[2].h) swap(sols[1],sols[2]);
			if(sols[0].h<sols[1].h) swap(sols[0],sols[1]);
			ans+=sols[1].h;
			expect[sols[0].n].push_back(sols[0].h-sols[1].h);
		}
		
		for(int t=0;t<3;t++){
			sort(expect[t].begin(),expect[t].end(),cmp);
			for(int i=0;i<n/2 && i<expect[t].size();++i){
				ans+=expect[t][i];
			}
			expect[t].clear();
		}
		
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
