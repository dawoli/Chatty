#include <iostream>
#include <conio.h>
using namespace std;
int f,T,n,k,q,l[100000],S[10000][10000],r[100000],c[100000];
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>T;
	while(T--)
	{
		cin>>n>>k>>q;
		for(int i=0;i<n;i++)
		{
			cin>>l[i];
			for(int j=0;j<l[i];j++)
			{
				cin>>S[i][j];
			}
		}
		for(int i=0;i<q;i++)
		{
			cin>>r[i]>>c[i];
			if(r[i]==1)
			{
				f=0;
				for(int k=0;k<n;k++)for(int j=1;j<l[i];j++)if(S[k][j]==c[i])f=1;
				if(f==1)
				{
					cout<<1<<endl;
					f=0;
				}
				else cout<<0<<endl;
			}
		}
	}
	return 0;
}
