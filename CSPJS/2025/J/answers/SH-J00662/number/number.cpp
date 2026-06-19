#include <bits/stdc++.h>
using namespace std;
//小R正在学习字符串处理。小X给了小R一个字符串s，其中s仅包含小写英文
//字母及数字，且.包 .含 .至 .少 .一 .个 1 ～9 .中 .的 .数 .字。小 X 希望小 R 使用 s 中的 .任 .意 .多 .个数
//字，按.任 .意 .顺 .序拼成一个正整数。 .注 .意： .小 R .可 .以 .选 .择 s .中 .相 .同 .的 .数 .字， .但 .每 .个 .数 .字
//只.能 .使 .用 .一 .次。例如，若 s 为 1a01b，则小 R 可以同时选择第 1,3,4 个字符，分别为
//1, 0,1，拼成正整数101 或110；但小R不能拼成正整数111，因为s仅包含两个数字1。
//小R想知道，在他所有能拼成的正整数中，最大的是多少。你需要帮助小R求出
//他能拼成的正整数的最大值,1≤|s|≤106
//#Shang4Shan3Ruo6Shui4
char s[1000005];
long long a[1000005],ans,h;

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for (int i=0;s[i]>='0';i++)
	{
		if (s[i]-'0'<10&&s[i]-'0'>=0)
			a[++h]=s[i]-'0';
	}
	sort(a+1,a+1+h);
	for (int i=h;i>=1;i--)
	{
		cout<<a[i];
	}
	return 0;
}
