#include<bits/stdc++.h>
using namespace std;
int n,m,l,v,ct,sct;
struct car{
	int d,v,a;
}c[100005];
int y[100005];
double dy[100005];
int ls[1000006],ls1[1000006],ls2[1000006];
bool bl=0;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		ct=0,sct=0;
		cin>>n>>m>>l>>v;
		memset(ls,0,sizeof(ls));
		for(int i=1;i<=n;i++){
			cin>>c[i].d>>c[i].v>>c[i].a;
		}
		for(int i=1;i<=m;i++){
			cin>>y[i];
		}
		for(int i=1;i<=n;i++){
			if(c[i].a>0){
				ls1[(v*v-c[i].v*c[i].v)/(2*c[i].a)+c[i].d]++;
				ls2[l+1]--;
				if((v*v-c[i].v*c[i].v)/(2*c[i].a)+c[i].d<y[m]){
					sct++;
				}
			}else if(c[i].a==0){
				if(c[i].v>v){
					ls1[c[i].d]++;
					ls2[l+1]--;
				sct++;
				}
			}else{
				bl=1;
				ls1[c[i].d]++;
				ls2[(v*v-c[i].v*c[i].v)/(2*c[i].a)+1+c[i].d]--;
			}
		}
		if(bl==0){
			cout<<sct<<' '<<m-1<<'\n';
		}else{
			
		}
	}
	cout.flush();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
