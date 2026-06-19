#include <bits/stdc++.h>
using namespace std;
#define debug cout<<"ok\n";
#define endl "\n"

const int N=1e5+7;
//mp[i][j] 表示的是在i索引，j的爱好//
//d[j][i]表示的是j聚类不，i人的上一个人的所应  
int mp[N][7],d[4][N],sz1=0,sz2=0,sz3=0;
int to1=0,to2=0,to3=0,ren1=0,ren2=0,ren3=0;
int n,a,b,c;
//4.1-2,5.2-3,6.1-3
//suoying to he
void intt()
{
	sz1=0;
	sz2=0;
	sz3=0;
	to1=0;
	to2=0;
	to3=0;
	ren1=0;
	ren2=0;
	ren3=0;
	memset(mp,0,sizeof(mp));
	memset(d,0,sizeof(d));
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>mp[i][1]>>mp[i][2]>>mp[i][3];
		mp[i][4]=mp[i][1]-mp[i][2];//1-2
		mp[i][5]=mp[i][2]-mp[i][3];//2-3
		mp[i][6]=mp[i][4]+mp[i][5];//1-3
		if(mp[i][1]>=mp[i][2] && mp[i][1]>=mp[i][3])
		{
			//上一个是第一个员工的索引 
			d[1][i]=sz1;
			sz1=i;//更新
			ren1++; 
			to1+=mp[i][1];
//			cout<<"dab "<<d[1][i]<<endl;
		}
		else if(mp[i][2]>=mp[i][1] && mp[i][2]>=mp[i][3])
		{
			d[2][i]=sz2;
			to2+=mp[i][2];
			sz2=i;
			ren2++;
		}
		else{
			d[3][i]=sz3;
			sz3=i;
			ren3++;
			to3+=mp[i][3];
		}
//		cout<<to1;
//		debug
//		cout<<to2;
//		debug
//		cout<<to3<<"\n";
	}	
}

void solve()
{
	
	intt();
	while(ren1>n/2)
	{
		//a is the 差额
		// b 缩影
		// c，换ren 
		a=N;
		b=sz1;
		c=b;
		while(b!=0)
		{
//			debug
//			cout<<mp[b][4]<<endl<<mp[b][5]<<endl<<mp[b][6]<<endl;
//			cout<<a<<endl<<b<<endl<<c<<endl;
//			debug
			if(mp[b][0]==1){
				b=d[1][b];
				continue;
			}
			if(a>mp[b][4]){
				a=mp[b][4];
				c=b;
			}
			if(a>mp[b][6])
			{
				c=b;
				a=mp[b][6];
			}
			b=d[1][b];//shangyigeren
//			debug
//			cout<<a<<endl<<b<<endl<<c<<endl;
//			debug
		}
		mp[c][0]=1;
		to1-=a;//suanshi
		ren1--;
	}
	//2
	while(ren2>n/2)
	{
		//a is the 差额
		// b 缩影
		// c，换ren 
		a=N;
		b=sz2;
		c=b;
		while(b!=0)
		{
//			debug
//			cout<<mp[b][4]<<endl<<mp[b][5]<<endl<<mp[b][6]<<endl;
//			cout<<a<<endl<<b<<endl<<c<<endl;
//			debug
			if(mp[b][0]==1){
				b=d[2][b];
				continue;
			}
			if(a>mp[b][5]){
				a=mp[b][5];
				c=b;
			}
			if(a>-mp[b][4])
			{
				c=b;
				a=-mp[b][4];
			}
			b=d[2][b];//shangyigeren
//			debug
//			cout<<a<<endl<<b<<endl<<c<<endl;
//			debug
		}
		mp[c][0]=1;
		to2-=a;//suanshi
		ren2--;
	} 
	 
	while(ren3>n/2)
	{
		//a is the 差额
		// b 缩影
		// c，换ren 
		a=N;
		b=sz3;
		c=b;
		while(b!=0)
		{
//			debug
//			cout<<mp[b][4]<<endl<<mp[b][5]<<endl<<mp[b][6]<<endl;
//			cout<<a<<endl<<b<<endl<<c<<endl;
//			debug
			if(mp[b][0]==1){
				b=d[3][b];
				continue;
			}
			if(a>-mp[b][5]){
				a=-mp[b][5];
				c=b;
			}
			if(a>-mp[b][6])
			{
				c=b;
				a=-mp[b][6];
			}
			b=d[3][b];//shangyigeren
//			debug
//			cout<<a<<endl<<b<<endl<<c<<endl;
//			debug
		}
		mp[c][0]=1;
		to3-=a;//suanshi
		ren3--;
	} 
	
	cout<<to1+to2+to3<<"\n";

}

int main()
{
	freopen("club5.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int T=1;
	cin>>T;
	while(T--)
	{
		solve();
	}
 	return 0;
}

