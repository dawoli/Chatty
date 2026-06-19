#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct Car{
	/*
	d start point to south
	v first speed
	a addition speed
	*/
	long long d,v,a;
}car[100005];
struct Node{
	int fir,sec;
};
int n,m,L,V;
int p[100005];
bool hsp[100005];
vector<Node> need;

bool cmp(Node x,Node y){
	return x.fir<y.fir || (x.fir==y.fir && x.sec<y.sec);
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	
	int T;
	cin >> T;
	while(T--){
		cin >> n >> m >> L >> V;
		for(int i=1;i<=n;i++){
			cin >> car[i].d >> car[i].v >> car[i].a;
		}
		for(int j=1;j<=m;j++){
			cin >> p[j];
			hsp[p[j]]=1;
		}
		int ans1=0,ans2=0;
		for(int i=1;i<=n;i++){
			int d=car[i].d,ve=car[i].v,a=car[i].a;
			bool flag=0;
			if(a==0){
				if(ve>V){
					int mx=-1,ls=0x3f3f3f3f;
					for(int i=d;i<=L;i++){
						if(hsp[i]){
							flag=1;
							mx=max(mx,i);
							ls=min(ls,i);
						}
					}
					if(mx!=-1 && ls!=0x3f3f3f3f) need.push_back({ls,mx});
				}
			}else if(a>0){
				int x=(V*V-ve*ve)/2/a+1+d;
				int mx=-1,ls=0x3f3f3f3f;
				for(int i=x;i<=L;i++){
					if(hsp[i]){
						flag=1;
						mx=max(mx,i);
						ls=min(ls,i);
					}
				}
				if(mx!=-1 && ls!=0x3f3f3f3f) need.push_back({ls,mx});
			}else{
				if(ve>V){
					int x=(V*V-ve*ve)/2/a;
					int mx=-1,ls=0x3f3f3f3f;
					for(int i=d;i<d+x;i++){
						if(hsp[i]){
							flag=1;
							mx=max(mx,i);
							ls=min(ls,i);
						}
					}
					if(mx!=-1 && ls!=0x3f3f3f3f) need.push_back({ls,mx});
				}
			}
			if(flag)ans1++;
		}
		sort(need.begin(),need.end(),cmp);
		int nlst=-1;
//		cout << "-----------------------" << endl;
		for(int i=0;i<need.size();i++){
//			cout << need[i].fir << ' ' << need[i].sec << ' ';
			if(need[i].fir>nlst){
//				cout << need[i].fir << ' ' << need[i].sec;
				ans2++;
				nlst=need[i].fir;
			}
//			cout << endl;
		}
//		cout << "-----------------------" << endl;
		cout << ans1 << ' ' << m-ans2 << endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

