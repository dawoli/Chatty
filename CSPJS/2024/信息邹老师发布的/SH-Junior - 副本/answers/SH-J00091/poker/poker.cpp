#include <iostream> 
#include <string>
#include <cstdio> 
using namespace std;
int n;
int have[200][200];
int cnt;
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	string s;
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		have[s[0]][s[1]]++;
		if(have[s[0]][s[1]]==1)
		{
			cnt++;
		}
	}
	cout<<52-cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
