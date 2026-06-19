#include<bits/stdc++.h>
using namespace std;
#define N 100005
#define INF 20004
typedef long long LL;
int n;
LL ans=0;
struct Stu{
	int a,b,c;
	int aa,bb,cc;
}s[N];
vector<Stu> v1,v2,v3;
vector<Stu> t;
bool cmpa(Stu x,Stu y){
	return x.aa<y.aa;
}
bool cmpb(Stu x,Stu y){
	return x.bb<y.bb;
}
bool cmpc(Stu x,Stu y){
	return x.cc<y.cc;
}
void init(){
	n=0,ans=0;
	memset(s,0,sizeof(s));
	v1.clear(),v2.clear(),v3.clear();
	t.clear();
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T; scanf("%d",&T);
	while(T--){
		init();
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d %d %d",&s[i].a,&s[i].b,&s[i].c);
			s[i].aa=s[i].a-max(s[i].b,s[i].c);
			s[i].bb=s[i].b-max(s[i].a,s[i].c);
			s[i].cc=s[i].c-max(s[i].a,s[i].b);
		}
		for(int i=1;i<=n;i++){
			int tmp=max(max(s[i].a,s[i].b),s[i].c);
			ans+=tmp;
			if(tmp==s[i].a){
				v1.push_back(s[i]);
			}else if(tmp==s[i].b){
				v2.push_back(s[i]);
			}else{
				v3.push_back(s[i]);
			}
		}
		if(v1.size()>n/2){
			int more=v1.size()-n/2;
			for(Stu u:v1){
				t.push_back(u);
			}
			sort(t.begin(),t.end(),cmpa);
			int cnt=1;
			for(auto it=t.begin();cnt<=more;it++,cnt++){
				ans-=(*it).aa;
			}
		}else if(v2.size()>n/2){
			int more=v2.size()-n/2;
			vector<Stu> t;
			for(Stu u:v2){
				t.push_back(u);
			}
			sort(t.begin(),t.end(),cmpb);
			int cnt=1;
			for(auto it=t.begin();cnt<=more;it++,cnt++){
				ans-=(*it).bb;
			}
		}else{
			int more=v3.size()-n/2;
			vector<Stu> t;
			for(Stu u:v3){
				t.push_back(u);
			}
			sort(t.begin(),t.end(),cmpc);
			int cnt=1;
			for(vector<Stu>::iterator it=t.begin();cnt<=more;it++,cnt++){
				ans-=(*it).cc;
			}
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);

	return 0;
}
