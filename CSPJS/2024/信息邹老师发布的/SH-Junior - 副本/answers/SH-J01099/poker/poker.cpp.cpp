#include <bits/stdc++.h>
using namespace std;

int n,cnt;
bool a[55];
string s;

int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout); 
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> s;
		if (s == "DA")
		{
			a[1] = 1;
		}
		if (s == "D2")
		{
			a[2] = 1;
		}
		if (s == "D3")
		{
			a[3] = 1;
		}
		if (s == "D4")
		{
			a[4] = 1;
		}
		if (s == "D5")
		{
			a[5] = 1;
		}
		if (s == "D6")
		{
			a[6] = 1;
		}
		if (s == "D7")
		{
			a[7] = 1;
		}
		if (s == "D8")
		{
			a[8] = 1;
		}
		if (s == "D9")
		{
			a[9] = 1;
		}
		if (s == "DT")
		{
			a[10] = 1;
		}
		if (s == "DJ")
		{
			a[11] = 1;
		}
		if (s == "DQ")
		{
			a[12] = 1;
		}
		if (s == "DK")
		{
			a[13] = 1;
		}
		if (s == "CA")
		{
			a[14] = 1;
		}
		if (s == "C2")
		{
			a[15] = 1;
		}
		if (s == "C3")
		{
			a[16] = 1;
		}
		if (s == "C4")
		{
			a[17] = 1;
		}
		if (s == "C5")
		{
			a[18] = 1;
		}
		if (s == "C6")
		{
			a[19] = 1;
		}
		if (s == "C7")
		{
			a[20] = 1;
		}
		if (s == "C8")
		{
			a[21] = 1;
		}
		if (s == "C9")
		{
			a[22] = 1;
		}
		if (s == "CT")
		{
			a[23] = 1;
		}
		if (s == "CJ")
		{
			a[24] = 1;
		}
		if (s == "CQ")
		{
			a[25] = 1;
		}
		if (s == "CK")
		{
			a[26] = 1;
		}
		if (s == "HA")
		{
			a[27] = 1;
		}
		if (s == "H2")
		{
			a[28] = 1;
		}
		if (s == "H3")
		{
			a[29] = 1;
		}
		if (s == "H4")
		{
			a[30] = 1;
		}
		if (s == "H5")
		{
			a[31] = 1;
		}
		if (s == "H6")
		{
			a[32] = 1;
		}
		if (s == "H7")
		{
			a[33] = 1;
		}
		if (s == "H8")
		{
			a[34] = 1;
		}
		if (s == "H9")
		{
			a[35] = 1;
		}
		if (s == "HT")
		{
			a[36] = 1;
		}
		if (s == "HJ")
		{
			a[37] = 1;
		}
		if (s == "HQ")
		{
			a[38] = 1;
		}
		if (s == "HK")
		{
			a[39] = 1;
		}
		if (s == "SA")
		{
			a[40] = 1;
		}
		if (s == "S2")
		{
			a[41] = 1;
		}
		if (s == "S3")
		{
			a[42] = 1;
		}
		if (s == "S4")
		{
			a[43] = 1;
		}
		if (s == "S5")
		{
			a[44] = 1;
		}
		if (s == "S6")
		{
			a[45] = 1;
		}
		if (s == "S7")
		{
			a[46] = 1;
		}
		if (s == "S8")
		{
			a[47] = 1;
		}
		if (s == "S9")
		{
			a[48] = 1;
		}
		if (s == "ST")
		{
			a[49] = 1;
		}
		if (s == "SJ")
		{
			a[50] = 1;
		}
		if (s == "SQ")
		{
			a[51] = 1;
		}
		if (s == "SK")
		{
			a[52] = 1;
		}
	}
	for (int i = 1;i <= 52;i++)
	{
		if (a[i] == 1)
		{
			cnt++;
		}
	}
	cout << 52 - cnt;
	return 0;
} 
