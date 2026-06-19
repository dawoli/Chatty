#include<bits/stdc++.h>
using namespace std;
const int AWA=1e5+9;
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T;
	cin>>T;
	int d[AWA],p[AWA],x[AWA][2];
	short a[AWA],v[AWA];
	unsigned short op[3009][3009]={},po[3009]={};
	while(T--){
		for(int i=0;i<3008;i++){
			for(int j=0;j<3008;j++){
				op[i][j]=0;
			}
			po[i]=0;
		} 
		bool flag1=false,flag2=false,flag4=false;
		int n,m,l,k;
		cin>>n>>m>>l>>k;
		for(int i=0;i<n;i++){
			cin>>d[i]>>v[i]>>a[i];
			if(a[i]<0) flag1=true;
			if(a[i]>=0) flag2=true;
		}
		for(int i=0;i<m;i++){
			cin>>p[i];
		}
		for(int i=0;i<n;i++){
			if(a[i]==0){
				if(v[i]<=k) x[i][0]=-1;
				else x[i][0]=d[i],x[i][1]=l;
			}
			else if(a[i]>0){
				if(v[i]>=k){
					if(d[i]==l&&v[i]==k) x[i][1]=-1;
					else x[i][0]=d[i],x[i][1]=l;
				}
				else{
					double z=(k*k-v[i]*v[i])/2+0.5;
					int y=(double)(z/a[i])+0.5;
					if(((k*k-v[i]*v[i])%(2*a[i]))!=0) y++;
					if(d[i]+y>l) x[i][0]=-1;
					else x[i][0]=d[i]+y,x[i][1]=l;
				}
			}
			else if(a[i]<0){
				if(v[i]<=k) x[i][0]=-1;
				else{
					int y=(double)((k*k-v[i]*v[i])/2)/a[i];
					if((k*k-v[i]*v[i])%(2*a[i])!=0) y--;
					else x[i][0]=d[i],x[i][1]=min(d[i]+y,l);
				}
			}
		}//算一辆车的超速区间 
		if(flag1==false) {
			int maxn=-1,ans=0,ans2=0;
			for(int i=0;i<m;i++){
				if(p[i]>maxn) maxn=p[i];
			}
			if(a[i]>0){
				for(int i=0;i<n;i++){
				if(x[i][0]<=maxn&&x[i][0]!=-1) ans2++;
			}
			if(ans2==0) cout<<ans2<<" "<<m<<endl;
			else cout<<ans2<<" "<<m-1<<endl;
			continue;
			}
			for(int i=0;i<n;i++){
				if(x[i][0]<maxn&&x[i][0]!=-1) ans++;
			}
			if(ans==0) cout<<ans<<" "<<m<<endl;
			else cout<<ans<<" "<<m-1<<endl;
			continue;
		}
		else{
			int ans=0;
			bool flag3=false;
			for(int i=0;i<n;i++){
				for(int j=0;j<m;j++){
					if(x[i][0]!=-1&&p[j]>x[i][0]&&p[j]<x[i][1]){
						op[j][i]++;
						po[j]++;
						flag3=true;
					}
				}
				if(flag3==true){
					ans++;
				}
			}
			cout<<ans<<" ";
			int maxn=-1,ans2=0,maxm,lol;
			int opo[3009]={};
			for(int j=0;j<m;j++){
				maxn=-1,lol=0;
				for(int i=0;i<m;i++){
					if(po[i]>maxn){
						maxn=po[i];
						maxm=i;
					} 
				}
				if(maxn<=0) break;
				for(int i=0;i<m;i++){
					opo[i]=op[maxm][i];
					lol++;
				}
				po[maxm]=0;
				for(int i=0;i<m;i++){
					if(po[i]!=0){
						for(int r=0;r<lol;r++){
							op[i][opo[r]]=0;
						}
					}
				}
				ans2++;
			}
			cout<<ans2<<endl;
		}
	}
	return 0;
} 
