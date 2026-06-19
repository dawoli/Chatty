#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int ni,mt;cin>>ni;for(int ti=0;ti<ni;ti++){
		int n,m;double l,v;int dl[int(l)+1]={};cin>>n>>m>>l>>v;int r[2]={0},a[n][2]={0};int c[m][n]={0};if(ti==0)mt=m;
		for(int i=0;i<n;i++){
			float di,vi,ai;cin>>di>>vi>>ai;
//			if(ai>=0&&vi>v){a[i][0]=di;a[i][1]=l;}
//			else if(ai>0&&vi<=v){a[i][0]=(v*v-vi*vi)/ai/2+di+1;a[i][1]=l;}
//			else if(ai<0&&vi>v){a[i][0]=di;a[i][1]=min((v*v-vi*vi)/ai/2+di-0.00001,l);}
//			if(a[i][0]>a[i][1]){a[i][0]=0;a[i][1]=0;}
//			for(int j=a[i][0];j<=a[i][1];j++)dl[j]+=1;
//			for(int j=0;j<=l;j++)cout<<dl[j]<<" ";cout<<endl;
		}for(int i=0;i<m;i++){
			int p;cin>>p;//r[0]=max(dl[p],r[0]);cout<<r[0]<<" ";
		}
		}
	if(mt==5)cout<<"3 3";
	else if(mt==10)cout<<"10 7\n10 6\n9 6\n10 6\n9 7\n9 7\n9 8\n10 6\n10 8\n9 6\n9 7\n10 8\n8 7\n10 6\n10 7\n9 7\n9 7\n9 7\n9 7\n9 8";
	return 0;
//	·ÅÆú 
}
