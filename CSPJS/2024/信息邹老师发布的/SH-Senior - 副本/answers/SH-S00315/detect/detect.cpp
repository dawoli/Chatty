#include<bits/stdc++.h>
using namespace std;
int t,n,m,l,v,c[100005][5],su[1000005],ans,xian[100005],duan[1000005],cnt,num;
int d(int x,int y,int z,int k){
	int sun=k*k-y*y;
	if(sun%(2*abs(z))==0){
		sun=sun/(2*abs(z));
	}else{
		sun=sun/(2*abs(z))+1;
		if(z<0){
			sun--;
		}
	}
	sun+=x;
	return sun;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>m>>l>>v;
		for(int i=1;i<=l;i++){
			su[i]=0;
			duan[i]=0;
		}
		for(int i=1;i<=n;i++){
			int x,y,z;
			ans=0;
			cnt=0;
			num=0;
			cin>>x>>y>>z;
			if(z>0){
				if(y>v){
					c[i][1]=x;
					c[i][2]=l;
				}else{
					c[i][1]=min(d(x,y,z,v),l);
					c[i][2]=l;
				}
			}
			if(z<0){
				if(y>v){
					c[i][1]=x;
					c[i][2]=min(d(x,v,z,y),l);
				}else{
					c[i][1]=0;
					c[i][2]=0;
				}
			}
			if(z==0){
				if(y>v){
					c[i][1]=x;
					c[i][2]=l;
				}else{
					c[i][1]=0;
					c[i][2]=0;
				}
			}
			//cout<<c[i][1]<<" "<<c[i][2]<<endl;
		}
		for(int i=1;i<=m;i++){
			cin>>xian[i];
			su[xian[i]]++; 
		}
		for(int i=1;i<=l;i++){
			su[i]+=su[i-1];
		} 
		for(int i=1;i<=n;i++){
			if(su[c[i][2]]>su[c[i][1]-1]){
				ans++;
				c[ans][1]=c[i][1];
				c[ans][2]=c[i][2];
				duan[c[ans][2]]++;
			}
		}
		cout<<ans<<" ";
		for(int i=1;i<=l;i++){
			duan[i]+=duan[i-1];
		}
		for(int i=1;i<=m;i++){
			if(duan[xian[i+1]-1]-duan[xian[i-1]]==0){
				xian[i]=xian[i-1];
				cnt++;
			}else{
				xian[i]=xian[i+1];
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
