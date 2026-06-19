#include<bits/stdc++.h>
using namespace std;
struct car{
	int d,v,a;
};
struct sign{
	int pos,cnt;
};
int T,n,m,L,V;
vector<sign> p;
vector<car> c;
bool h(car x){
	if(x.d>p.at(p.size()-1).pos) return false;
	if(x.v<=V&&x.a<=0) return false;
	if(x.v>=V&&x.a>=0) return true;
	double s=(V*V-x.v*x.v)/(2*x.a);
	if(x.v>V&&x.a<0){
		for(sign i:p)
			if(i.pos>=x.d&&i.pos<=x.d+s) return true;
		return false;
	}
	if(x.v<V&&x.a>0){
		for(sign i:p)
			if(i.pos>x.d+s) return true;
		return false;
	}
}
int count(){
	int cnt=0;
	for(car i:c) if(h(i)) cnt++;
	return cnt;
}
int close(){
	priority_queue<int> q; 
	for(car x:c){
		if(x.d>p.at(p.size()-1).pos) continue;
		if(x.v<=V&&x.a<=0) continue;
		else{
			if(x.v>V&&x.a>=0)
				for(sign i:p) if(i.pos>=x.d) i.cnt++;
			else if(x.v>=V&&x.a>0)
				for(sign i:p) if(i.pos>x.d) i.cnt++;
			else if(x.v>V&&x.a<0){
				double s=(V*V-x.v*x.v)/(2*x.a);
				for(sign i:p) if(i.pos>=x.d&&i.pos<=x.d+s) i.cnt++;
			}
			else if(x.v<V&&x.a>0){
				double s=(V*V-x.v*x.v)/(2*x.a);
				for(sign i:p) if(i.pos>x.d+s) i.cnt++;
			}
		}
	}
	for(sign i:p)
		q.push(i.cnt);
	int l=q.size();
	for(int i=0;i<l;i++){ 
		m-=q.top();q.pop();
		if(m<=0) return q.size();
	}
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	for(int i=0;i<T;i++){
		cin>>n>>m>>L>>V;
		for(int i=0;i<n;i++){
			car xx;
			cin>>xx.d>>xx.v>>xx.a;
			c.push_back(xx);
		}
		for(int i=0;i<m;i++){
			sign num;cin>>num.pos>>num.cnt;
			p.push_back(num);
		} 
	}
	cout<<count()<<" "<<close();
	fclose(stdin);fclose(stdout);
	return 0;
}
