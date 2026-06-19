#include<iostream>
#include<cstdio>
#include<cmath>
#define N 0x3fffffff
using namespace std;
FILE* fin=freopen("delect.in","r",stdin);
FILE* fout=freopen("detect.out","w",stdout);
int n,m,L,MaxS;
void guibing(int l,int y,int * power,int * a,bool *rd,bool *r){
	if (l==y)return;
	int mid=(l+y)>>1;
	int i=l,j=mid+1,k=l;
	guibing(l,mid,power,a,rd,r);
	guibing(mid+1,y,power,a,rd,r);
	while(i<=mid&&j<=y){
		if (power[i]<power[j]||rd[i]==false){
			a[k]=power[i];r[k]=rd[i];k++;i++;
		}
		else{
			a[k]=power[j];r[k]=rd[j];k++;j++;
		}
	}
	while(i<=mid){
		a[k]=power[i];
		r[k]=rd[i];
		k++;i++;
	}
	while(j<=y){
		a[k]=power[j];
		r[k]=rd[j];
		k++;
		j++;
	}
	for (int ii=l;ii<=y;ii++){
		power[ii]=a[ii];
		rd[ii]=r[ii];
	}
}
void calc(long double ** detect,int * speed,int * a,bool * founda,bool * found,bool *rd,int* d){
	int temp;
	for (int i=1;i<=n;i++){
		if(a[i]>0){
			if(speed[i]>MaxS){
				founda[i]=false;
				found[i]=true;
			}
			else{
				detect[i][0]=(MaxS-speed[i])/a[i];//when
				detect[i][1]=min(detect[i][0]*speed[i]+1/2*(long double)a[i]*detect[i][0]*detect[i][0]+d[i],(long double)L);//where
				rd[i]=false;
			}
			continue;
		}
		if(a[i]==0){
			if (speed[i]>MaxS){
				founda[i]=false;
				found[i]=true;			 
			}
			else{
				founda[i]=false;
				found[i]=false;
			}
		}
		else{
			if (speed[i]<MaxS){
				founda[i]=false;
				found[i]=false;
			}
			else{
				detect[i][0]=(MaxS-speed[i])/a[i];
				detect[i][1]=min(detect[i][0]*speed[i]+1/2*(long double)a[i]*detect[i][0]*detect[i][0]+d[i],(long double)L);
				rd[i]=true;
			}
		}
	}
}
int main(){
	int T;
	cin>>T;
	for (int iii=1;iii<=T;iii++){
	cin>>n>>m>>L>>MaxS;
	long double *detect[2];
	detect[0]=new long double[n+1];
	detect[1]=new long double[n+1];
	int *a=new int [n+1];
	int *speed=new int [n+1];
	bool *found=new bool [n+1];
	bool *founda=new bool [n+1];
	int * d=new int [n+1];
	int * p=new int [m+1];
	bool *rd=new bool [n+1];//true=left equal
	for (int i=1;i<=n;i++){
		found[i]=false;
		founda[i]=true;
		rd[i]=false;
	}
//	int *range[2];
//	range[0]=new int [n+1];
//	range[1]=new int [n+1];
//	set_init(range,rd);
	for (int i=1;i<=n;i++){
		cin>>d[i]>>speed[i]>>a[i];
	}
	for (int i=1;i<=m;i++){
		cin>>p[i];
	}
	calc(detect,speed,a,founda,found,rd,d);
	for (int i=1;i<=n;i++){
		if (founda[i]&&!found[i]){
			if(rd[i]){
				for (int j=1;j<=m;j++){
					if (p[j]>=d[i]&&p[j]<detect[i][1]){
						found[i]=true;
						break;
					}
					continue;
				}
			}
			else{
				for (int j=1;j<=m;j++){
					if (p[j]>detect[i][1]&&p[j]<=L){
						found[i]=true;
						break;
					}
				}
			}
		}
	}
	int ans=0;
	for (int i=1;i<=n;i++){
		if (found[i]){
			ans++;
		}
	}
	cout<<ans;
	int *end=new int [n+1];
	int nums=1;
	bool *rd2=new bool[n+1];
	int* begin=new int[n+1];
	for (int i=1;i<=n;i++){
		if(found[i]){
			if(rd[i]){
				begin[nums]=d[i];
				end[nums]=detect[i][1];
			}
			else{
				begin[nums]=detect[i][1];
				end[nums]=L;
			}
			rd2[nums]=rd[i];
			nums++;
		}
	}
	int *result=new int [n+1];
	bool *r=new bool [nums+1];
	bool *opened=new bool [n+1];
	bool *detected=new bool [n+1];
	for (int i=1;i<=n;i++){
		opened[i]=false;
		detected[i]=false;
	}
	guibing(1,nums,end,result,rd2,r);
	int temp=p[1];
	for (int i=1;i<=nums;i++){
		if(!detected[i]){
		if (rd[i]){
			int a=1;
			while(p[a+1]<end[i]){
				a++;
			}
			opened[a]=true;
			detected[i]=true;
			for (int j=i+1;j<=nums;j++){
				if(rd[i]){
					if (begin[j]>=p[a]){
						detected[j]=true;
					}
					else break;
				}
				else{
					if (begin[j]>p[a]){
						detected[j]=true;
					}
					else break;
				}
			}
		}
	}
	}
	int ans2=0;
	for (int i=1;i<=nums;i++){
		if(opened[i]){
			ans2++; 
		}
	}
	cout<<ans2;
	cout<<endl;
}
	return 0;
}
