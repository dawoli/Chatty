#include<bits/stdc++.h>
using namespace std;
int t,n;
struct Person{
	int a,b,c;
	int bgx(){
		if(a>=b){
			if(a>=c) return a;
			else return c;
		}else{
			if(b>=c) return b;
			else return c;
		}
	}
	int bgn(){//biggest
		if(a>=b){
			if(a>=c) return 0;
			else return 2;
		}else{
			if(b>=c) return 1;
			else return 2;
		}
	}
	int secdx(){
		if(a>=b){
			if(a>=c) return max(b,c);
			else return a;
		}else{
			if(b>=c) return max(a,c);
			else return b;
		}
	}
	int secd(){//second
		Person p{a,b,c};
		if(p.bgn()==0) p.a=-1;
		else if(p.bgn()==1) p.b=-1;
		else p.c=-1;
		return p.bgn();
	}
};

Person p[100005];
vector<Person> v[3];//i is the pos in p
int cal(){
	int ans=0;
	for(Person i : v[0]){
		//cout<<"0:"<<i.a<<' '<<i.b<<' '<<i.c<<'\n';
		ans+=i.a;
	}
	for(Person i : v[1]){
		//cout<<"1:"<<i.a<<' '<<i.b<<' '<<i.c<<'\n';
		ans+=i.b;
	}
	for(Person i : v[2]){
		//cout<<"2:"<<i.a<<' '<<i.b<<' '<<i.c<<'\n';
		ans+=i.c;
	}
	return ans;
}
bool cmp(Person x,Person y){
	return x.bgx()-x.secdx() > y.bgx()-y.secdx();
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<3;i++) v[i].clear();
		for(int i=1;i<=n;i++){
			cin>>p[i].a>>p[i].b>>p[i].c;
			v[p[i].bgn()].push_back(p[i]);
		}
		Person tmp{v[0].size(),v[1].size(),v[2].size()};
		int b=tmp.bgn();
		
		if(v[b].size()<=n/2){
			cout<<cal()<<'\n';
			continue;
		}
		
		sort(v[b].begin(),v[b].end(),cmp);
		
		for(int i=n/2;i<v[b].size();i++){
			v[v[b][i].secd()].push_back(v[b][i]);
		}
		for(int i=v[b].size();i>n/2;i--){
			v[b].pop_back();
		}
		
		tmp=Person{v[0].size(),v[1].size(),v[2].size()};
		int nb=tmp.bgn();
		if(nb==b || nb<=n/2){
			cout<<cal()<<'\n';
			continue;
		}
		cout<<"emm something wrong";
		
	}
	return 0;
} 
