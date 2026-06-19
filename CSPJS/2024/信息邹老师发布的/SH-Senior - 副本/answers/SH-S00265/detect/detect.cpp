#include<bits/stdc++.h>
using namespace std;
int T;
int d[22][100002],v[22][100002],a[22][100002],mi[22][100002],ans[22][3],x[22],t[22];
bool mii[22][100002];
struct p{
	int n,m,L,V;
}TT[22];


int main (){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	for (int i=0;i<T;i++){
		t[i]=0;
		cin>>TT[i].n>>TT[i].m>>TT[i].L>>TT[i].V;
		for (int j=0;j<TT[i].n;j++){
			cin>>d[i][j]>>v[i][j]>>a[i][j];
			if (a[i][j]==0){
				t[i]++;
			}
		}
		for (int j=0;j<TT[i].m;j++){
			cin>>mi[i][j];
			mii[i][j]=false;
		}
	}
	
	
	for(int i=0;i<T;i++){
		ans[i][0]=0;
		ans[i][1]=0;
		if (t[i]==TT[i].n){
			for (int j=0;j<TT[i].n ;j++){
				if (d[i][j]<=mi[i][TT[i].m]){
					if (v[i][j]>TT[i].V){
						ans[i][0]++;
						
					}
				}
			}
			cout<<ans[i][0]<<" "<<TT[i].m-1<<endl;
		}
		else{
			ans[i][0]=0;
			ans[i][1]=0;
			x[i]=0;
			for (int j=0;j<TT[i].n ;j++){
				if (a[i][j]>0){
					if ((TT[i].L-d[i][j])*2*a[i][j]+pow(v[i][j],2)<=pow(TT[i].V,2)){
						continue;
					}
					else{
						for (int k=0;k<TT[i].m;k++){
							if ((mi[i][k]-d[i][j])>=0){
								if ((mi[i][k]-d[i][j])*2*a[i][j]+pow(v[i][j],2)<=pow(TT[i].V,2)){
									continue;
								}
								else{
									ans[i][0]++;
									mii[i][k]=true;
									break;
								}
							}
							else{
								continue;
							}
						}
					}	
				}
			
			
			
				else if (a[i][j]<0){
					long double s=-1.000000000000*pow(v[i][j],2)/(2*a[i][j]);
					for (int k=0;k<TT[i].m;k++){
						if (d[i][j]+s>=mi[i][k]){
							if (mi[i][k]>=d[i][j]){
								if ((mi[i][k]-d[i][j])*2*a[i][j]+pow(v[i][j],2)<=pow(TT[i].V,2)){
									continue;
								}
								else{
									ans[i][0]++;
									mii[i][k]=true;
									break;
								}
							}
						}
						else{
							continue;
						}
					}
					
				}
				else{
					x[i]++;
					continue;
				}
			}
			for (int k=0;k<TT[i].m;k++){
				if (mii[i][k]==true){
					ans[i][1]++;
				}
			}
		
			int u=0;
			for (int j=0;j<TT[i].n;j++){
				if (u==x[i]){
					break;
				}
				if(a[i][j]==0){
					u++;
					if (v[i][j]>TT[i].V){
						ans[i][0]++;
						bool y=false;
						for (int k=0;k<TT[i].m;k++){
							if (mi[i][k]>=d[i][j]&&mii[i][k]==true){
								y=true;
								break;
							}
						}
						if (y==false){
							ans[i][1]++;
						}
					}
				}
				else{
					continue;
				}
			}
		}
		
		
		
	}
	
	for (int k=0;k<T;k++){
		cout<<ans[k][0]<<" "<<TT[k].m-ans[k][1]<<endl;
	}
	
	return 0;
}
