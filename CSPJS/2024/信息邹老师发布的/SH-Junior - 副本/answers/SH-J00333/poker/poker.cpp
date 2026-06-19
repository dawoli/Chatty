#include <bits/stdc++.h>
using namespace std;

bool flags[52]={0};
int n, res = 52, tag;
char card[2];
map<char, int> cards;

int getTag(char* card)
{
	int t=0;
	if (card[0]=='C') t+=13;
	if (card[0]=='H') t+=26;
	if (card[0]=='S') t+=39;
	t += (cards[card[1]]-1);
	return t;
}
int main()
{
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	scanf("%d", &n);
	cards['A'] = 1; cards['2'] = 2; cards['3'] = 3; cards['4'] = 4; cards['5'] = 5; cards['6'] = 6; cards['7'] = 7;
	cards['8'] = 8; cards['9'] = 9; cards['T'] = 10; cards['J'] = 11; cards['Q'] = 12; cards['K'] = 13;
	for (int i=0; i<n; i++)
	{
		scanf("%s", card);
		tag = getTag(card);
		if (!flags[tag]) {
			flags[tag] = true;
			res--;
		}
	}
	printf("%d", res);
	return 0;
}
