#include<bits/stdc++.h>
using namespace std;
const int O=1e5+5;
const int R=1e6+5;
int T,n,m,L,V,cnt,feishanchu=2e9;
int d[O],v[O],a[O],p[O];
bool ceshu[R];
bool panduan=0,t=0;
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	for(int g=0;g<T;g++){
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;i++){
			cin>>d[i]>>v[i]>>a[i];
			if(a[i]!=0)panduan=1;
		}
		for(int i=1;i<=m;i++)cin>>p[i];
		if(panduan==0){
			for(int i=1;i<=n;i++){
				if(v[i]>V){
					for(int k=1;k<=m;k++){
						if(p[k]>=d[i]){
							cnt++;
//							ceshu[k]=1;
							if(k<feishanchu)feishanchu=k;
							break;
						}
					}
				}
			}
			cout<<cnt<<" "<<m-feishanchu<<endl;
			feishanchu=2e9;
			cnt=0;
		}
		else{
			feishanchu=0;
			for(int i=1;i<=n;i++){
				for(int k=d[i];k<=L;k++){
					double sudu=sqrt((1<<v[i])+(2*a[i]*m));
					if(sudu>V){
						t=1;
						ceshu[k]++;
						break;
					}
				}
				if(t==1)cnt++;
				t=0;
			}
			for(int k=1;k<=m;k++){
				if(ceshu[k]==0)feishanchu++;
			}
		}
		cout<<cnt<<" "<<feishanchu<<endl;
	}
	return 0;
}
