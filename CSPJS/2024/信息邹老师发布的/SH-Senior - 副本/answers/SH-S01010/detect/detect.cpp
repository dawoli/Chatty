#include <bits/stdc++.h>
using namespace std;

struct car{
	int startx;
	int vol;
	int add;
};

car a[100010];
int b[100010];
int c[100010];
int T,n,m,v;
float l;
int anss=0;
int start,ans;
float sends;

void count(float s,float e){
	for (int i=1;i<=m;i++){
		if (b[i]>=s and b[i]<=e){
			ans++;
			break;
		}
	}
}

void judge(int i){
	if(a[i].vol>v) ans++;
}

int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	for (int q=1;q<=T;q++){
		cin>>n>>m>>l>>v;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		ans=0;
		for (int i=1;i<=n;i++){
			cin>>a[i].startx>>a[i].vol>>a[i].add;
		}
		for (int i=1;i<=m;i++){
			cin>>b[i];
		}

		for (int i=1;i<=n;i++){
			judge(i);
		}
		
		if (ans==0){
			anss=m;
		}else{
			anss=m-1;
		}
		cout<<ans<<" "<<anss<<endl;
	}
}
