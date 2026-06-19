#include <bits/stdc++.h>

using namespace std;

const int N=2e5+10;

string sfir[N],ssec[N];
string tf,tc;
int n,q;
int ans;
int cha[N];
map<int,int> mp1,mp2;

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q; 
	for (int i=1;i<=n;i++)
	{
		cin>>sfir[i]>>ssec[i];
		int t=sfir[i].find('b')-ssec[i].find('b');
		if (t>=0)
			mp1[sfir[i].find('b')-ssec[i].find('b')]++;
		else
			mp2[ssec[i].find('b')-sfir[i].find('b')]++;
	}
	if (q==1)
	{
		cin>>tf>>tc;
		for (int i=1;i<=n;i++)
		{
			int findone=tf.find(sfir[i]),findsec=tc.find(ssec[i]);
			if (findone!=-1 && findsec!=-1 && findone==findsec)
			{
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	else
	{
		for (int i=1;i<=q;i++)
		{
			cin>>tf>>tc;
			int t=tf.find('b')-tc.find('b');
			if (t>=0)
				cout<<mp1[tf.find('b')-tc.find('b')]<<endl;
			else
				cout<<mp2[tc.find('b')-tf.find('b')]<<endl;
		}
	}
	
	return 0;
}
