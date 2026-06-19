#include<bits/stdc++.h>
using namespace std;
long long a[200005][5],b[200005][5],c[200005][5];
long long aa,bb,cc,cnt,aaa,bbb,ccc;
long long p[200010][5];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	for(int q=1;q<=T;q++){
		long long n;
		cin>>n;

		memset(p,0,sizeof(p));
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		aa=0,bb=0,cc=0,cnt=0;
		aaa=0,bbb=0,ccc=0;
		for(int i=1;i<=n;i++){
			cin>>p[i][1]>>p[i][2]>>p[i][3];
			if(p[i][1]>=p[i][2]&&p[i][1]>=p[i][3]){
				aa++;
				aaa++;
				a[aa][1]=p[i][1];
				a[aa][2]=i;	
			}
			else if(p[i][2]>=p[i][1]&&p[i][2]>=p[i][3]){
				bb++;
				bbb++;
				b[bb][1]=p[i][2];
				b[bb][2]=i;	
			
			}
			else if(p[i][3]>=p[i][2]&&p[i][3]>=p[i][1]){
				cc++;
				ccc++;
				c[cc][1]=p[i][3];
				c[cc][2]=i;	
			}
			long long f=200000,g;
			while(aaa>n/2||bbb>n/2||ccc>n/2){
				if(aaa>n/2){
					aaa--;
					for(int i=1;i<=aa;i++){
						int t=a[i][2];
						if(a[i][1]==-1) continue;
						if(a[i][1]-max(p[t][2],p[t][3])<=f){
							f=a[i][1]-max(p[t][2],p[t][3]);
							g=i;
						}
					}
					a[g][1]=-1;
					
					int t=a[g][2];
					p[t][1]=-1;
					if(p[t][2]>p[t][3]){
						bb++;
						bbb++;
						b[bb][1]=p[t][2];
						b[bb][2]=i;
					}
					else{
						cc++;
						ccc++;
						c[cc][1]=p[t][3];
						c[cc][2]=i;
					}
				}
				if(bbb>n/2){
					bbb--;
					for(int i=1;i<=bb;i++){
						int t=b[i][2];
						if(b[i][1]==-1) continue;
						if(b[i][1]-max(p[t][1],p[t][3])<=f){
							f=b[i][1]-max(p[t][1],p[t][3]);
							g=i;
						}
					}
					b[g][1]=-1;
					
					int t=b[g][2];
					p[t][2]=-1;
					if(p[t][1]>p[t][3]){
						aa++;
						aaa++;
						a[aa][1]=p[t][1];
						a[aa][2]=i;
					}
				
					else{
						cc++;
						ccc++;
						c[cc][1]=p[t][1];
						c[cc][2]=i;
					}
				}
				if(ccc>n/2){
					ccc--;
					for(int i=1;i<=cc;i++){
						int t=c[i][1];
						if(c[i][1]==-1) continue;
						if(c[i][1]-max(p[t][2],p[t][1])<=f){
							f=c[i][1]-max(p[t][2],p[t][1]);
							g=i;
						}
					}
					c[g][1]=-1;
					int t=c[g][2];
					p[t][3]=-1;
					
					
					
					if(p[t][2]>p[t][1]){
						bb++;
						bbb++;
						b[bb][1]=p[t][2];
						b[bb][2]=i;
					}
					else{
						aa++;
						aaa++;
						a[aa][1]=p[t][2];
						a[aa][2]=i;
					}
				}
			}
		
		
		}
		for(int i=1;i<=aa;i++){
			if(a[i][1]!=-1){
				cnt+=a[i][1];
			}
		}
		for(int i=1;i<=bb;i++){
			if(b[i][1]!=-1){
				cnt+=b[i][1];
			}
		}
		for(int i=1;i<=cc;i++){
			if(c[i][1]!=-1){
		     	cnt+=c[i][1];
			}
		}
		cout<<cnt<<endl;
	}
	
	return 0;
}
