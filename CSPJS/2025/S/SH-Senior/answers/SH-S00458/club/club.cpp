#include <bits/stdc++.h>
using namespace std;

int T;
int n;
long long ans;

struct node
{
	int one, two, three;
};
vector <node> happiness;

bool cmp(node& a, node& b)
{
	return a.one > b.one;
}


void dfs(int stu_idx, long long cur_ans, int num_1, int num_2, int num_3)
{
    if (stu_idx == n) return;

    if (num_1 < (n / 2))
    {
        long long new_ans = cur_ans + happiness[stu_idx].one;
        ans = max(ans, new_ans);
        dfs(stu_idx + 1, new_ans, num_1 + 1, num_2, num_3);
    }
    if (num_2 < (n / 2))
    {
        long long new_ans = cur_ans + happiness[stu_idx].two;
        ans = max(ans, new_ans);
        dfs(stu_idx + 1, new_ans, num_1, num_2 + 1, num_3);
    }
    if (num_3 < (n / 2))
    {
        long long new_ans = cur_ans + happiness[stu_idx].three;
        ans = max(ans, new_ans);
        dfs(stu_idx + 1, new_ans, num_1, num_2, num_3 + 1);
    }
    return;
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
    cin >> T;
    while (T--)
    {
        cin >> n;
        happiness.clear();
        happiness.resize(n);
        ans = 0;
        
        bool have_a = true, have_b = true;
        
        for (int i = 0; i < n; i++)
        {
            cin >> happiness[i].one >> happiness[i].two >> happiness[i].three;
            if (happiness[i].one != 0 or happiness[i].three != 0)
            {
            	have_a = false;
			}
			if (happiness[i].three != 0)
			{
				have_b = false;
			}
        }
        
        
		if (have_a)
		{
			sort(happiness.begin(), happiness.end(), cmp);
			for (int i = 0; i < (n / 2); i++)
			{
				ans += happiness[i].one;
			}
			cout << ans;
		}
		else if (have_b)
		{
			dfs(0, 0, 0, 0, 0);
		}
		else
		{
			dfs(0, 0, 0, 0, 0);
		}
        
        cout << ans <<endl;
    }


    return 0;
}

