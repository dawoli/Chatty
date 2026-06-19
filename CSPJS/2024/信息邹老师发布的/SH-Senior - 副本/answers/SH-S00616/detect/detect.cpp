#include<bits/stdc++.h>
using namespace std;
struct abc{
	long long a,b,c;	
};
abc p[100010];
int l[100010];
int l1[200100];
long long m,n,f,q;
long long t;
int main(){
	freopen("detect3.in","r",stdin);
	freopen("detect3.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		int z=0;
		long long cnt=0;
		for(int j=0;j<=100000;j++){
			p[i].a=0;
			p[i].b=0;
			p[i].c=0;
			l[i]=0;
		}
		cin>>m>>n>>f>>q;
		for(int j=1;j<=n;j++){
			cin>>p[j].a>>p[j].b>>p[j].c;
			
		}
		for(int j=1;j<=m;j++){
			cin>>l[j];
		}
		sort(l+1,l+m+1);
		
		for(int j=1;j<=n;j++){
			
			int left;
			int right;
			if(p[j].c==0){

				left=p[j].a;
				
				if(p[j].b>q){
					right=f;
				}
				else{
					right=left-1;
				}
				
			}
			else if(p[j].c>0){
				

				left=p[j].a;
				int dis=q*q-p[j].b*p[j].b;
				dis=dis/(p[j].c*2)+1;
				if(dis>f){
					right=left-1;
				}
				else{
					left=dis+left;	
					right=f;
				}
			}
			else if(p[j].c<0){

				
				if(p[j].b<q){
					right=left-1;
				}
				else{
					left=p[j].a;
					int dis=p[j].b*p[j].b-q*q;
					int ws=abs(2*p[j].c);
					dis=dis/ws-1;
					right=dis+left;
				}
			}
			
			
			if(left>right){
				continue;
			}
			
			else{
				
			
				int l1=1;
				int r1=m;
				while(l1<=r1){
				
					if(l1>r1){
						break;
					}
					int mid=l[(l1+r1)/2];
					if(left<=mid&&mid<=right){
						cnt++;

						break;
					}
					if(mid<=left){
						l1=(l1+r1)/2+1;
					}
					else{
						r1=(l1+r1)/2-1;
					}
				}	
			}	
		}
		cout<<cnt<<" "<<m-1<<endl;	
	}
	return 0;
}
