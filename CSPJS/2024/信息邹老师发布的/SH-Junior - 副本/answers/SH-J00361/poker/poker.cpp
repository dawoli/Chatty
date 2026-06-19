#include <iostream>

int mp[26];

bool had[5][14];

int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;std::cin >> n;
	mp['D'-'A'] = 1;
	mp['C'-'A'] = 2;
	mp['H'-'A'] = 3;
	mp['S'-'A'] = 4;
	
	for(int i = 0;i<n;i++){
		char c, a;
		std::cin >> c >> a;
		if(a=='A')	had[mp[c-'A']][1] = true;
		else if(a=='T')	had[mp[c-'A']][10] = true;
		else if(a=='J')	had[mp[c-'A']][11] = true;
		else if(a=='Q')	had[mp[c-'A']][12] = true;
		else if(a=='K')	had[mp[c-'A']][13] = true;
		else	had[mp[c-'A']][a-'0'] = true;
	}
	
	int ans = 0;
	for(int i = 1;i<=4;i++)
		for(int j = 1;j<=13;j++)
			if(had[i][j])
				++ans;
	std::cout << 52-ans << std::endl;
}
