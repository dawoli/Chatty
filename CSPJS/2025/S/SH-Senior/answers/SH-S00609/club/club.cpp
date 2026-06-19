#include<bits/stdc++.h>
using namespace std;
const int N=1e5+9;
struct Node{
	int num,x,y;
	bool operator<(const Node&x1)const{
		return num>x1.num;
	}
};
int t,n;
int am[4]={0,0,0,0};
int am1[N];
bool ok(){
	for(int i=1;i<=n;i++) 
		if(am1[i]>1) return false;
	for(int i=1;i<=3;i++)
		if(am[i]>n/2) return false;
	return true;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		set<Node> s;
		cin>>n;
		for(int i=1;i<=n;i++){
			int xx,yy,zz;
			cin>>xx>>yy>>zz;
			s.insert((Node){xx,i,1});
			s.insert((Node){yy,i,2});
			s.insert((Node){zz,i,3});
		}
		vector<Node> v;
		fill(am1+1,am1+n+1,0);
		fill(am+1,am+3,0); 
		set<Node>::iterator it;
		int count=0; 
		for(it=s.begin();count<n;it++){
			Node tmp=*it;
			v.push_back(tmp);
			int xx=tmp.x,yy=tmp.y;
			am1[xx]++;
			am[yy]++;
			count++;
		}
		set<Node> use;
		for(int i=0;i<v.size();i++) {
			Node tmp=v[i];
//			cout<<tmp.num<<" "<<tmp.x<<" "<<tmp.y<<endl;
			use.insert(v[i]);
			s.erase(v[i]);
		}
			
		while(!ok()){
//			cout<<1<<endl;
			for(it=use.begin();it!=use.end();it++){
				Node tmp=*it;
//				cout<<tmp.num<<" "<<tmp.x<<" "<<tmp.y<<endl;
			}
			it=use.end();
			it--;
			set<Node> add;
			set<Node>::iterator it2;
			it2=use.begin();
			it2--;
			set<Node> del;
			for(;it!=it2;it--){
				Node tmp=*it;
				int xx=tmp.x,yy=tmp.y;
				if(am1[xx]<=1&&am[yy]<=n/2) continue;
				set<Node>::iterator it1;
				for(it1=s.begin();it1!=s.end();it1++){
//					cout<<tmp.num<<" "<<tmp.x<<" "<<tmp.y<<endl;
					Node tp=*it1;
//					cout<<tp.num<<" "<<tp.x<<" "<<tp.y<<endl;
					int xxx=tp.x,yyy=tp.y;
					if(yyy==yy||xxx==xx) continue;
					if(am[yyy]>=n/2||am1[xxx]>1) continue;
					del.insert(tmp);
					add.insert(tp);
					am[yyy]++,am1[xxx]++;
				}
			}
			for(it=del.begin();it!=del.end();it++){
				Node tmp=*it;
//				cout<<tmp.num<<" "<<tmp.x<<" "<<tmp.y<<endl;
				int xx=tmp.x,yy=tmp.y;
				am[yy]--;
				am1[xx]--;
				use.erase(tmp);
			}
			for(it=add.begin();it!=add.end();it++){
				Node tmp=*it;
				use.insert(tmp);
				s.erase(tmp);
			}	
		}
		int ans=0;
		for(it=use.begin();it!=use.end();it++)
			ans+=(*it).num;
		cout<<ans<<endl;
	}
	return 0;
}
