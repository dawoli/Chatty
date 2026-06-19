#include<bits/stdc++.h>
using namespace std;

int T,n,m,L,V,dx[100005],vel[100005],acc[100005],p[100005],ans1,ans2;
vector<pair<int,int> >Vct,Ant;

int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	cin>>T;
	while(T--){
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;i++){
			cin>>dx[i]>>vel[i]>>acc[i];
		}
		for(int i=1;i<=m;i++){
			cin>>p[i];
		}
		p[m+1]=L+1;
		for(int i=1;i<=n;i++){
			if(acc[i]<0){
				int indie=(vel[i]>V?dx[i]:L+1),outdie=(vel[i]>V?dx[i]+(vel[i]*vel[i]-V*V-1)/(-2*acc[i]):dx[i]-1);
				if(outdie<indie)continue;
				int fst=lower_bound(p+1,p+m+1,indie)-p,scd=upper_bound(p+1,p+m+1,outdie)-p-1;
				if(scd<fst)continue;
				ans1++;Vct.push_back(make_pair(fst,scd));
			}
			else if(acc[i]>0){
				int indie=(vel[i]>V?dx[i]:min(L+1,dx[i]+(V*V-vel[i]*vel[i])/(2*acc[i])+1)),outdie=L;
				if(outdie<indie)continue;
				int fst=lower_bound(p+1,p+m+1,indie)-p,scd=upper_bound(p+1,p+m+1,outdie)-p-1;
				if(scd<fst)continue;
				ans1++;Vct.push_back(make_pair(fst,scd));
			}
			else{
				int indie=(vel[i]>V?dx[i]:L+1),outdie=L;
				if(outdie<indie)continue;
				int fst=lower_bound(p+1,p+m+1,indie)-p,scd=upper_bound(p+1,p+m+1,outdie)-p-1;
				if(scd<fst)continue;
				ans1++;Vct.push_back(make_pair(fst,scd));
			}
		}
		sort(Vct.begin(),Vct.end());
		for(auto uu:Vct){
			if(Ant.size()>0){
				if(Ant[Ant.size()-1].first==uu.first)continue;
			}
			while(Ant.size()>0){
				if(Ant[Ant.size()-1].second>=uu.second)Ant.pop_back();
				else break;
			}
			Ant.push_back(uu);
		}
		for(int o=0,cnum=0;o<Ant.size();){
			ans2++;cnum=Ant[o].second;
			while(o<Ant.size()&&Ant[o].first<=cnum)o++;
		}
		cout<<ans1<<' '<<m-ans2<<'\n';
		Vct.clear();Ant.clear();ans1=ans2=0;
	}
	cout<<endl;
	return 0;
}
