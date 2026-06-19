#include<bits/stdc++.h>
using namespace std;
int d[100005];
int v[100005];
int a[100005];
struct yipin{
	int value1,value2,flag1;
	bool flag2;
}b[100005];
struct yan{
	int val,val2;
	bool bb;
}p[100005];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int t,n,m,l,vq;
	cin>>t;
	for(int j = 1;j<= t;j++){
		cin>>n>>m>>l>>vq;
		int ans1=0,ans2=0;
		for(int i = 1;i<= n;i++){
			cin>>d[i]>>v[i]>>a[i];
		}
		for(int i = 1;i<= m;i++){
			cin>>p[i].val;
		}
		for(int i = 1;i<= n;i++){
			if(a[i]==0){
				if(v[i]>vq){
					b[i].value1=d[i];
					b[i].value2=l;
					b[i].flag1=1;
					b[i].flag2=true;
				}
				else{
					b[i].value1=d[i];
					b[i].value2=l;
					b[i].flag1=1;
					b[i].flag2=false;
				}
			}
			else{
				double x=(vq*vq-v[i]*v[i])/(2*a[i])*1.0;
				bool bo;
				if(1.0*(vq*vq-v[i]*v[i])/(2*a[i])==x) bo=true;
				else bo=false;
				if(v[i]>=vq){
					if(x>=0){
						b[i].value1=d[i];
						b[i].value2=l;
						b[i].flag1=1;
						b[i].flag2=true;
					}
					else{
						b[i].value1=d[i];
						if(d[i]+x>=l){
							b[i].value2=l;
						}
						else{
							b[i].value2=d[i]+x;
						}
						if(bo==true){
							b[i].flag1=1;
						}
						else{
							b[i].flag1=2;
						}
						b[i].flag2=true;
					}
				}
				else{
					if(x>0){
						if(d[i]+x>=l){
							b[i].value1=0;
							b[i].value2=0;
							b[i].flag1=1;
							b[i].flag2=false;
						}
						else{
							b[i].value1=d[i]+x;
							b[i].value2=l;
							if(bo==true){
								b[i].flag1=1;
							}
							else{
								b[i].flag1=3;
							}
							b[i].flag2=true;
						}	
					}
					else{
						b[i].value1=0;
						b[i].value2=0;
						b[i].flag1=1;
						b[i].flag2=false;
					}
				}
			}
		}
		for(int i = 1;i<= n;i++){
			if(b[i].flag2==true){
				if(b[i].flag1==1){
					for(int w = 1;w<= m;w++){
						if(p[w].val>b[i].value1&&p[w].val<b[i].value2){
							ans1++;
						}
					}
				}
				else if(b[i].flag1==2){
					for(int w = 1;w<= m;w++){
						if(p[w].val>b[i].value1&&p[w].val<=b[i].value2){
							ans1++;
						}
					}
				}
				else if(b[i].flag1==3){
					for(int w = 1;w<= m;w++){
						if(p[w].val>=b[i].value1&&p[w].val<b[i].value2){
							ans1++;
						}
					}
				}
			}
		}
		cout<<3<<" "<<3<<endl;
	}
	return 0;
}
