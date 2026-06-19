#include<bits/stdc++.h>
using namespace std;

int n,P[4][14];

int main() {
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	scanf("%d",&n);
	for(int i = 1;i <= n;i++) {
		char s[11];
		scanf("%s",s);
		int a,b;
		if(s[0] == 'D')
			a = 0;
		else 
			if(s[0] == 'C')
				a = 1;
			else
				if(s[0] == 'H')
					a = 2;
				else
					a = 3;
		if(s[1] > '1' && s[1] <= '9')
			b = s[1] - '0';
		else 
			if(s[1] == 'A')
				b = 1;
			else 
				if(s[1] == 'T')
					b = 10;
				else 
					if(s[1] == 'J')
						b = 11;
					else 
						if(s[1] == 'Q')
							b = 12;
						else 
							b = 13;
		P[a][b] = 1;
	}
	int ans = 0;
	for(int i = 0;i < 4;i++)
		for(int j = 1;j <= 13;j++)
			if(!P[i][j])
				ans++;
	printf("%d",ans);
	return 0;
}
