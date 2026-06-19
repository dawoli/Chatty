#include<bits/stdc++.h>
#define N 100005
using namespace std;
int n,m,aa[N],a[N],c[N],t,x[10],b[N],num[N],ans[N],ansn=0;
struct p{
	string s;
	int r;
};
p f[N];
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>aa[i];
	for(int i=1;i<=m;i++) cin>>c[i];
	int o=1;
	while(pow(2,o)<n) o++;
	for(int i=1;i<=o;i++){
		cin>>f[i].s;
		f[i].r=i;
	}
	cin>>t;
	for(int k=1;k<=t;k++){
		for(int j=0;j<4;j++) cin>>x[j];
		for(int i=1;i<=n;i++){
			a[i]=aa[i]^x[i%4];
//			cout<<a[i]<<" ";
		}
		for(int i=1;i<=m;i++){
			for(int j=1;j<=c[i];j++){
				b[j]=a[j];
				num[j]=j;
			}
			int k=0;
			for(int j=1;j<=o;j++){
				if(pow(2,j)==c[i]){
					k=j;
					break;
				}
			}
			for(int j=k;j<=o;j++){
				string n=f[j].s;
				for(int l=0;l<n.size();l++){
					if(n[l]=='0'){
						if(b[l*2+1]>=(j-k+1)){
							b[l+1]=b[l*2+1];
							num[l+1]=num[l*2+1];
						}
						else{
							b[l+1]=b[l*2+2];
							num[l+1]=num[l*2+2];
						}
					}
					else{
						if(b[l*2+2]>=(j-k+1)){
							b[l+1]=b[l*2+2];
							num[l+1]=num[l*2+2];
						}
						else{
							b[l+1]=b[l*2+1];
							num[l+1]=num[l*2+1];
						}
					}
				}
			}
			ans[i]=num[1];
		}
		ansn=ans[1];
		for(int i=2;i<=m;i++){
			ansn^=ans[i];
		}
		cout<<ansn<<endl;
	}
	return 0;
}
