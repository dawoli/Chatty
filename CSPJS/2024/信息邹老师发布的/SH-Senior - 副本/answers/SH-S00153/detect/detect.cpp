#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct name{
	ll d,v,a;
};
struct qu{
	ll left,right;
};
qu f[100009];
name car[100009];
ll n,m,L,V,p[100009],T; 
bool cmp(const qu a,const qu b){
	if(a.left>b.left)
		return 0;
	else if(a.left==b.left&&a.right>b.right)
		return 0;
	else
		return 1;
}
void BF(){
	ll max1=0,sum=0;
	for(int i=1;i<=m;i++)	
		max1=max(p[i],max1);
	for(int i=1;i<=n;i++)
		if(car[i].d<=max1&&car[i].v>V)
			sum++;
	cout<<sum<<" "<<m-1<<endl;
}
double dd(int v0,int a0,int s0){
	double v5=1.0*v0*v0+1.0*2*a0*s0;
	v5=sqrt(v5);
	return v5;
}
int near(int t){
	for(int i=1;i<=m;i++)
		if(p[i]>=t)
			return i;
}
int find(int total){
	int da=1,rig=f[1].right;
	for(int i=2;i<=total;i++)
		if(rig<f[i].left){
			da++;
			rig=f[i].right;
		}
	return da;
}
void DD(){
	ll sum=0;
	for(int i=1;i<=m;i++){
		f[i].left=0;
		f[i].right=0;		
	}
	for(int i=1;i<=n;i++){
		if(car[i].d<=p[m]){
			if(car[i].a==0&&car[i].v>V){
				sum++;
				f[sum].left=near(car[i].d);
				f[sum].right=m;
			}
			if(car[i].a>0&&dd(car[i].v,car[i].a,p[m]-car[i].d)>V){
				sum++;				
				f[sum].right=m;				
				for(ll j=m;j>=1;j--)
					if(dd(car[i].v,car[i].a,p[j]-car[i].d)<=V){
						f[sum].left=j+1;			
						break;					
					}
			}
			if(car[i].a<0&&dd(car[i].v,car[i].a,p[near(car[i].d)]-car[i].d)>V){
				sum++;				
				f[sum].left=near(car[i].d);
				if(f[sum].left==m)
					f[sum].right=f[sum].left;
				else
					for(ll j=near(car[i].d);j<=m;j++)
						if(dd(car[i].v,car[i].a,p[j]-car[i].d)<=V){
							f[sum].right=j-1;			
							break;					
						}
				if(f[sum].right==0)
					f[sum].right=f[sum].left;
			}
		}			
	}
	sort(f,f+sum+1,cmp);
	cout<<sum<<" "<<m-find(sum)<<endl;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	for(int hh=1;hh<=T;hh++){
		int flag=0;
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;i++){
			cin>>car[i].d>>car[i].v>>car[i].a;		
			if(car[i].a!=0)
				flag=1;	
		}
		for(int i=1;i<=m;i++)
			cin>>p[i];
		if(flag==0)
			BF();
		else
			DD();
	}
	return 0;
} 
