#include<bits/stdc++.h>
#define maxn 200020
#define maxl 5000020
#define ull unsigned long long
#define modd 131
using namespace std;

int n, q, ans;

struct st {
	string s1, s2, s1szm;
}s[maxn];

vector <int> szm[150];

int lenstr(string sss) 
{
	int res=0;
	for (int i = 0;;i++)
	{
		if (sss[i] == '\0')
			break;
		else 
			res++;
	}
	return res;
}

bool strequal (string ss1, string ss2) 
{
	if (lenstr(ss1)!=lenstr(ss2))
		return 0;
	for (int i = 0; i < lenstr(ss1); i++) 
	{
		if (ss1[i] != ss2[i])
			return 0;
	}
	return 1;
}

string qiepian (string sss, int l, int r) 
{
	string res="";
	for (int i = l; i <= r; i++)
	{
		res+=sss[i];
	}
	return res;
}

char t1[maxl], t2[maxl];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	
	
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	
	scanf ("%d%d", &n, &q);
	
	
	for (int i = 1; i <= n; i++) 
	{
		cin >> s[i].s1 >> s[i].s2;
		s[i].s1szm = s[i].s1;
		
		szm[(int)(s[i].s1szm[0]-'a')].push_back(i);
	}
	
	while (q--) 
	{
		ans=0;
		scanf ("%s%s", t1, t2);
		
		if (strlen(t1) != strlen (t2))
			printf ("0\n");
		else 
		{
			for (int i = 0; i < strlen(t1); i++) 
			{
				int cur = (int) (t1[i]-'a');
				
				for (int j = 0; j < szm[cur].size(); j++) 
				{
					string sss1 = s[szm[cur][j]].s1, sss2 = s[szm[cur][j]].s2;
					
					if (strequal (sss1, qiepian (t1, i, i+lenstr(sss1)-1) ))
					{
						if (strequal(qiepian(t1,0,i-1)+sss2+qiepian(t1,i+lenstr(sss1),lenstr(t1)-1), t2 )) 
						
							ans++;
						
					}
					
					
				}
				
			}
			printf ("%d\n", ans);
		}
		
	}
	
	return 0;
	
}





