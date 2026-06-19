#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	short T;
	cin>>T;
	while(T--){
		int n,k,q;
		vector<short> word[10005];
		vector< pair<short,short> >nums[200005];
		vector<short> deeps[200005];
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++){
			int l;
			cin>>l;
			word[i].push_back(l);
			for(int j=1;j<=l;j++){
				short S;
				cin>>S;
				word[i].push_back(S);
				pair<short,short> p;
				p.first=i;
				p.second=j;
				nums[S].push_back(p);
			}
		}
		queue<pair<pair<short,short>,short> >Q;
		pair<pair<short,short>,short> p;
		p.first.first=0;
		p.first.second=0;
		p.second=1;
		Q.push(p);
		vector<short> a[100005];
		short nowd=0;
		while(Q.empty()==0){
			pair<pair<short,short>,short> p=Q.front();
			Q.pop();
			if(nowd!=p.first.second){
				nowd=p.first.second;
				memset(a,0,sizeof(a));
			}
			if(p.first.second==100)break;
			//cout<<p.first.first<<' '<<p.first.second<<' '<<p.second<<endl;
			for(pair<short,short>v : nums[p.second]){
				if(v.first != p.first.first)for(int i=v.second+1;i<=min((int)word[v.first][0],v.second+k-1);i++){
					bool tag=0;
					for(short t:a[v.first]){
						if(t==word[v.first][i]){
							tag=1;break;
						}
					}if(tag)continue;
					deeps[word[v.first][i]].push_back(p.first.second+1);
					pair<pair<short,short>,short> u;
					u.first.first=v.first;
					u.first.second=p.first.second+1;
					u.second=word[v.first][i];
					Q.push(u);
					a[u.first.first].push_back(u.second);
				}
			}
		}
		while(q--){
			int r,c;
			cin>>r>>c;
			bool tag=1;
			for(short v: deeps[c]){
				if(v==r){
					cout<<1<<endl;
					tag=0;
					break;
				}
			}if(tag)cout<<0<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
