#include<bits/stdc++.h>
using namespace std;
int t,n;
bool fw[100010];
int ba=1,bb=1,bc=1;
long long ans=0;
struct Node{
	int a;
	int b;
	int c,bianhao;
}yuangong[100010];
void shai(int lun,int shu)
{
	if(shu>ans) ans=shu;
	if(lun==n+1)return;
	int gj=n/2;
		if(fw[yuangong[lun].bianhao])
		{
			if(ba+1<=gj)
			{
				fw[yuangong[lun].bianhao]=0;
				ba++;
				shai(lun+1,shu+yuangong[lun].a);
				fw[yuangong[lun].bianhao]=1;
				ba--;
			}
			if(bb+1<=gj)
			{
				fw[yuangong[lun].bianhao]=0;
				bb++;
				shai(lun+1,shu+yuangong[lun].b);
				fw[yuangong[lun].bianhao]=1;
				bb--;
			}
			if(bc+1<=gj)
			{
				fw[yuangong[lun].bianhao]=0;
				bc++;
				shai(lun+1,shu+yuangong[lun].c);
				fw[yuangong[lun].bianhao]=1;
				bc--;
			}
		}
	}		
int main (){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		ans=0;
		ba=0,bb=0,bc=0;
		cin>>n;
		for(int j=1;j<=n;j++)
		{
			cin>>yuangong[j].a>>yuangong[j].b>>yuangong[j].c;
			yuangong[j].bianhao=j;
			fw[j]=1;
		}
		shai(1,0);
		cout<<ans<<endl;
	}
	return 0;
}
