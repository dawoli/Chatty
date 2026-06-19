#include <bits/stdc++.h>
using namespace std;
const int MAXN=100005;
int buk[MAXN];
int n,ans;
vector< pair<int,int> > ve;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	
	cin >> n;
	ans=n;
	for(int i=1;i<=100000;++i) buk[i]=0;
	for(int i=1;i<=n;++i){
		int x;
		cin >> x;
		buk[x]++;
	}
//	cout << "---------1----------";
	for(int i=1;i<=100000;++i){
		if(buk[i]) ve.push_back(make_pair(i,buk[i]));
	}
//	cout << "---------2----------";
	if(ve.size()!=1){
		
		auto poi=ve.begin();
		
		for(auto i=ve.begin()+1;i!=ve.end();++i){
			pair<int,int> tmp=*i;
//			cout << tmp.first << tmp.second << endl;
			pair<int,int> enemy=(*poi);

			while(tmp.second>=(*poi).second && poi<i){
				ans-=(*poi).second;
				(*poi).second=0;
				while(!(*poi).second) poi++;
			}
			if(tmp.second<(*poi).second){
				ans-=tmp.second;
				(*poi).second-=tmp.second;
			}
//			for(auto j=ve.begin();j!=ve.end();++j)cout << (*j).first << ' ' << (*j).second << ' ';
//			cout << endl;
		}
	}
	
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
