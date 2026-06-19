#include<bits/stdc++.h>
using namespace std;
const int MAXN=3005;
struct node{
	int d,v,a,l,r;
};
struct node2{
	int p;
	bool tn[MAXN];
};
int T,n,m,L,V;
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i++){
		int ans1=0,ans2=1;
		bool t3[MAXN],tt[MAXN];
		node t[MAXN];
		node2 t2[MAXN];
		for(int i=1;i<=3005;i++) t[i].l=-1,t[i].r=-1,t3[i]=false;
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;i++){
			cin>>t[i].d>>t[i].v>>t[i].a;
			if(t[i].a>0){
				t[i].l=(V*V-t[i].v*t[i].v)/(2*t[i].a)+1+t[i].d;
				t[i].r=L;
			}
			else if(t[i].a<0){
				if(t[i].v>V){
					t[i].l=t[i].d;	
					t[i].r=((V*V-t[i].v*t[i].v)/(2*t[i].a))+t[i].d;
				}
			}
			else{
				if(t[i].v>V){
					t[i].l=t[i].d;
					t[i].r=L;
				}
			}
		}
		//for(int i=1;i<=n;i++) cout<<t[i].l<<" "<<t[i].r<<endl;
		for(int i=1;i<=m;i++){
			cin>>t2[i].p;
			for(int j=1;j<=n;j++){
				if(t[j].l<=t2[i].p&&t[j].r>=t2[i].p) t2[i].tn[j]=1;
			}
		}
		//for(int i=1;i<=n;i++) cout<<t[i].l<<" "<<t[i].r<<endl;
		for(int i=1;i<=n;i++){
			for(int k=1;k<=m;k++){
				//cout<<1;
				if(t2[k].p<=t[i].r&&t2[k].p>=t[i].l){
					//cout<<i<<" ";
					tt[i]=1;
					ans1++;
					break;
				}
				//break;
			}
		}
//		for(int i=1;i<=m;i++){
//			for(int j=1;j<=n;j++)
//				cout<<t2[i].tn[j]<<" ";
//			cout<<endl;
//		}
		for(int i=1;i<=m+1;i++){
			int cnt=0;
			bool abcd;
			for(int j=1;j<=n;j++){
				if(t3[j]==t2[i].tn[j]) continue;
				else if(t3[j]!=t2[i].tn[j]&&t3[j]==false&&t2[i].tn[j]==true) continue;
				else{
					abcd=1;
					break;
				}
			}
			if(abcd==0){
				//cout<<1<<endl;
				for(int k=1;k<=n;k++){
					t3[k]=t2[i].tn[k];
				}
			}
			else{
				//cout<<2<<endl;
				bool t4[MAXN],abcdd;
				for(int j=1;j<=n;j++) t4[j]=t3[j]||t2[i].tn[j];
				//for(int j=1;j<=n;j++) cout<<t4[j];
				//cout<<endl; 
				for(int j=1;j<=n;j++){
					if(t3[j]==t4[j]||(t3[j]!=t4[j]&&t3[j]==true)) continue;
					else{
						abcdd=true;
						break;
					}
				}
				if(abcdd==false){
					//cout<<1<<endl;
					ans2=ans2; 
				}
				else{
					ans2++;
					for(int k=1;k<=n;k++){
						t3[k]=t4[k];
					}
					//cout<<ans2<<endl;
					//for(int i=1;i<=n;i++) cout<<t3[i];
					//cout<<endl;
				}
			}
			//for(int j=1;j<=n;j++) cout<<t3[i];
			//cout<<endl;
		}
		cout<<ans1<<" "<<n-ans2<<endl;
	}
	return 0;
}
