#include<bits/stdc++.h>
using namespace std;
int s1[21],s2[21];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int t,n,m,l,lv,d,v,a;
	cin>>t;
	for(int i=0;i<t;i++){
		int p[100001]={0},q[100001]={0},x[100001]={0},y[100001]={0},z[100001]={0};
		cin>>n>>m>>l>>lv;
		for(int j=0;j<n;j++){
			cin>>d>>v>>a;
			if(a==0){
				if(v>lv){
					x[j]=d;
					y[j]=l;
				}
			}
			else if(a>0){
				if(v>lv){
					x[j]=d;
					y[j]=l;
				}
				else{
					if((lv*lv-v*v)/2/a+d<=l){
						x[j]=(lv*lv-v*v)/2/a+d+1;
						y[j]=l;
					}
				}
			}
			else{
				if(v>lv){
					x[j]=d;
					if((lv*lv-v*v)/2/a+d<=l){
						if((lv*lv-v*v)%(2*a)==0){
							y[j]=(lv*lv-v*v)/2/a+d-1;
						}
						else{
							y[j]=(lv*lv-v*v)/2/a+d;
						}
					}
					else{
						y[j]=l;
					}
				}
			}
		}
		for(int j=0;j<m;j++){
			cin>>p[j];
			for(int k=0;k<n;k++){
				if(p[j]>=x[k] && p[j]<=y[k]){
					q[j]++;
					z[k]=1;
				}
			}
			if(q[j]!=0){
				q[j]--;
			}
			s2[i]+=q[j];
		}
		for(int j=0;j<n;j++){
			if(z[j]==1){
				s1[i]++;
			}
		}
		s2[i]-=n-1;
	}
	for(int i=0;i<t;i++){
		cout<<s1[i]<<' '<<s2[i]<<endl;
	}
	return 0;
}
