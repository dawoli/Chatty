#include <bits/stdc++.h>
#include <string>
using namespace std;
int n;
int k;
int a[15],c[15],h[15],s[15];
const int DA = 1;
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	scanf("%d",&n);
	if(n == 1)
	{
		printf("51");
		return 0;
	}
	for(int i = 1; i <= n; i ++)
	{
		string p;
		cin >> p;
		if(p[0] == 'D')
		{
		if(p == "DA") a[1] ++; 
		else if(p == "D2") a[2] ++;
		else if(p == "D3") a[3] ++;
		else if(p == "D4") a[4] ++;
		else if(p == "D5") a[5] ++;
		else if(p == "D6") a[6] ++;
		else if(p == "D7") a[7] ++;
		else if(p == "D8") a[8] ++;
		else if(p == "D9") a[9] ++;
		else if(p == "DT") a[10] ++;
		else if(p == "DJ") a[11] ++;
		else if(p == "DQ") a[12] ++;
		else if(p == "DK") a[13] ++;
		}
		else if(p[0] == 'C')
		{
		if(p == "CA") c[1] ++; 
		else if(p == "C2") c[2] ++;
		else if(p == "C3") c[3] ++;
		else if(p == "C4") c[4] ++;
		else if(p == "C5") c[5] ++;
		else if(p == "C6") c[6] ++;
		else if(p == "C7") c[7] ++;
		else if(p == "C8") c[8] ++;
		else if(p == "C9") c[9] ++;
		else if(p == "CT") c[10] ++;
		else if(p == "CJ") c[11] ++;
		else if(p == "CQ") c[12] ++;
		else if(p == "CK") c[13] ++;
		}
		else if(p[0] == 'H')
		{
		if(p == "HA") h[1] ++; 
		else if(p == "H2") h[2] ++;
		else if(p == "H3") h[3] ++;
		else if(p == "H4") h[4] ++;
		else if(p == "H5") h[5] ++;
		else if(p == "H6") h[6] ++;
		else if(p == "H7") h[7] ++;
		else if(p == "H8") h[8] ++;
		else if(p == "H9") h[9] ++;
		else if(p == "HT") h[10] ++;
		else if(p == "HJ") h[11] ++;
		else if(p == "HQ") h[12] ++;
		else if(p == "HK") h[13] ++;
		}
		else if(p[0] == 'S')
		{
		if(p == "SA") s[1] ++; 
		else if(p == "S2") s[2] ++;
		else if(p == "S3") s[3] ++;
		else if(p == "S4") s[4] ++;
		else if(p == "S5") s[5] ++;
		else if(p == "S6") s[6] ++;
		else if(p == "S7") s[7] ++;
		else if(p == "S8") s[8] ++;
		else if(p == "S9") s[9] ++;
		else if(p == "ST") s[10] ++;
		else if(p == "SJ") s[11] ++;
		else if(p == "SQ") s[12] ++;
		else if(p == "SK") s[13] ++;
		}
		
	}
	for(int i = 1; i <= 13; i ++)
	{
		if(a[i] >= 2) k += a[i] - 1;
		if(c[i] >= 2) k += c[i] - 1;
		if(h[i] >= 2) k += h[i] - 1;
		if(s[i] >= 2) k += s[i] - 1;
	}
	int ans = 52 - n + k;
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

