#include<bits/stdc++.h>
using namespace std;
int n,m,t,ansh=0,ansl=1;
int sc[1000];
int main(){
	freopen("seat","r",stdin);
	freopen("seat","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=m*n;i++){
		cin>>sc[i];
	}
	t=sc[1];
	sort(sc+1,sc+n*m+1);
	bool f=1;
	int beg=1;
	for(int i=m*n;i>0;i--)
	{
		
		if(((((ansh%m==0 and f) or (ansh==1 and f==0)) and ansh!=0) or m==1) and beg==0){
			ansl++;
			f?f=0:f=1;
		}
		else f?ansh++:ansh--;
		//printf("now in the line%d,queue%d,score is %d\n",ansh,ansl,sc[i]);
		if(beg>0)beg--;
		if(sc[i]==t)
		{
			cout<<ansl<<' '<<ansh;
			return 0;
		}
	}
	return 0;
}
