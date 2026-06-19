#include <bits/stdc++.h>
using namespace std;
int t;
int n, m;
int a1[5005], q[5005];
char c[16][4096];
long long a[5005];
int po[16][4096][2];
struct node
{
	int idx;
	int power;
	int lun;
};
queue<node> qu;
int main()
{
	freopen("arena.in", "r", stdin);
	freopen("arena.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a1[i];
	for(int i = 0;i < m;i++) cin >> q[i];
	int li = 1;
	while((1 << li) < n) li++;
	for(int i = 1;i <= li;i++) cin >> c[i];
	cin >> t;
	while(t--)
	{
		int x[4];
		cin >> x[0] >> x[1] >> x[2] >> x[3];
		int ans = 0;
		for(int i = 0;i < m;i++)
		{
			memset(po, -1, sizeof(po));
			for(int j = 1;j <= q[i];j++)
			{
				a[i] = a1[i] ^ x[i % 4];
			}
			int lin = 0;
			while((1 << lin) < q[i]) lin++;
			if((1 << lin) == q[i])
			{
				node head, head2;
				for(int j = 1;j <= q[i];j++)
				{
					head.idx = j;
					head.power = a[j];
					head.lun = 1;
					qu.push(head);
				}
				while(qu.size() > 1)
				{
					head = qu.front();
					qu.pop();
					head2 = qu.front();
					qu.pop();
					node nxt;
					if(c[head.lun][(head.idx - 1) / 2] == '0')
					{
						if(head.power >= head.lun)
						{
							nxt.idx = head.idx;
							nxt.power = head.power;
						}
						else
						{
							nxt.idx = head2.idx;
							nxt.power = head2.power;
						}
					}
					else
					{
						if(head2.power >= head.lun)
						{
							nxt.idx = head2.idx;
							nxt.power = head2.power;
						}
						else
						{
							nxt.idx = head.idx;
							nxt.power = head.power;
						}
					}
					nxt.lun = head.lun + 1;
				}
				continue;
			}
			ans ^= (qu.front().idx * (i + 1));
		}
		cout << ans << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
