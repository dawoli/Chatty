#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int T,n,m,L,V;
struct car{
	int d,v,a;
	double pos;
	bool flag;
};
car c[N];
struct detector{
	int d;
	vector otl;
};
detector p[N];
bool styl(detector a,detector b){
	return a.otl.size()<b.otl.size();
}
bool outlimit(car c){
	int mo=L-c.d;
	if(sqrt(mo*2*c.a+c.v*c.v)>V)
		return true;
	return false;
}
double cotlimit(car c){
	double pla=(V*V-c.v*c.v)*1.0/(2*c.a);
	return min(L,c.d+pla);
}
void inputc(){
	for(int i=1;i<=n;i++){
		c[i].d=c[i].v=c[i].a=0;
		c[i].flag=0;
		c[i].pos=-1;
		cin>>c[i].d>>c[i].v>>c[i].a;
		if(c[i].v>V&&c[i].a>=0){
			c[i].pos=c[i].d;
			cnt++;
		}
		else if(c[i].v>V&&c[i].a<0){
			c[i].pos=cotlimit(c[i]);
			cnt++;
		}
		else if(outlimit(c[i])){
			c[i].pos=cotlimit(c[i]);
			c[i].flag=1;
			cnt++;
		}
		else
			continue;
	}
	cout<<cnt<<" ";
}
void inputm(){
	for(int i=1;i<=m;i++){
		p[i].d=0;
		while(!p[i].otl.empty())
			p[i].otl.pop();
		cin>>p[i].d;
		for(int j=1;j<=n;j++)
			if(c[j].pos!=-1){
				if(c[j].flag==0&&c[j].d<=p[i].d&&c[j].pos>p[i].d)
					p[i].otl.push_back(j);
				else if(c[j].pos<p[i].d)
					p[i].otl.push_back(j);
			}
	}
}
void question2(){
	sort(p+1,p+m+1,styl);
	if(p[m].otl.size()==cnt)
		cout<<cnt-1<<endl;
	else if(p[m].otl.size()==cnt-1)
		cout<<cnt-2<<endl;
	else{
		cout<<cnt-3<<endl;
	}
}
void solve(){
	cin>>n>>m>>L>>V;
	int cnt=0;
	inputc();
	inputm();
	question2();
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i++){
		solve();
	}
	return 0;
}
