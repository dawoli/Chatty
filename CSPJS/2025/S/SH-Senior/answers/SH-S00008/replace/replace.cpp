#include <bits/stdc++.h>

using namespace std;

vector <string> rep1,rep2,cha1,cha2,drt1,drt2;
int left1[1010000],left2[1010000],right1[1010000],right2[1010000];
string s1,s2;

int main()
{
	
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	scanf("%d%d",&n,&q);
	bool flag = 1;
	for(int i = 0; i<n; i++)
	{
		
		cin >> s1 >> s2;

		rep1.push_back(s1);
		rep2.push_back(s2);
	}
	
		for(int i = 0; i<rep1.size();i++)
		{
			string str;
			str = rep1[i];
			for(int j=0; j < str.size(); j++)
			{
				if(str[j] == 'b')
				{
					left1[i] = j-1;
					right1[i] = str.size() - j;
				}
			}
		}
		for(int i = 0; i<rep2.size();i++)
		{
			string str;
			str = rep2[i];
			for(int j=0; j < str.size(); j++)
			{
				if(str[j] == 'b')
				{
					left2[i] = j-1;
					right2[i] = str.size() - j;
				}
			}
		}
		
		while(q --)
		{
			cin >> s1 >> s2;
			int zuo1,you1,zuo2,you2;
			bool f=0;
			for(int i = 0; i < s1.size(); i ++)
			{
				if(s1[i] == 'b')
				{
					zuo1 = i-1;
					you1 = s1.size() - i;
				}
			}
			for(int i = 0; i < s2.size(); i ++)
			{
				if(s2[i] == 'b')
				{
					zuo2 = i-1;
					you2 = s1.size() - i;
				}
			}
			
			int ans=0;
			for(int i = 0; i<rep2.size();i++)
			{
				if((zuo1 >= left1[i])&&((you2 >= right2[i])&&(you1 >= right1[i])&&(zuo2 >= left2[i])&&zuo1 - zuo2 == left1[i] - left2[i]) && (you1 -you2 == right1[i] - right2[i])) ans++;
			}
			cout << ans << endl;
		}
	
	return 0;
}


