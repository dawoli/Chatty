#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
struct pii{
	int first,second;
};

using namespace std; 
const int N=2e5+1; 
struct S{
	string s;
	int p;
	int l(){return p;}
	int r(){return s.size()-p-1;}
	friend ostream&operator<<(ostream&os ,S &ss){
		os<<ss.l()<<' '<<ss.r()<<endl;
		return os;
	}
}; 
S s1[N],s2[N],t1[N],t2[N];
vector<pii> v[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i].s>>s2[i].s;
		s1[i].p=s1[i].s.find('b');
		s2[i].p=s2[i].s.find('b');
	}
	for(int i=1;i<=q;i++){
		cin>>t1[i].s>>t2[i].s;
		t1[i].p=t1[i].s.find('b');
		t2[i].p=t2[i].s.find('b');
	}
	if(q==1){
		//  write sth
//		return 0;
	}



	for(int i=1;i<=n;i++){
		v[s2[i].p-s1[i].p].push_back((pii){s1[i].l(),s1[i].r()});
	}
	for(int i=1;i<=q;i++){
		int d=t2[i].p-t1[i].p;
		int ans=0;
		for(int j=0;j<v[d].size();j++){
			if(v[d][j].first<=t1[i].l()&&v[d][j].second<=t1[i].r()) ans++;
		}
		cout<<ans<<endl;
	}
	
	
	fclose(stdin),fclose(stdout);
	return 0;
}
