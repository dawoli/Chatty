#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;

int n, m, L, V; // car amount, detector amount, road length, limit speed
int d[N], v[N], a[N], p[N], o[N]; // dis, speed, acc, detector, out_dis/latest_dis

vector<vector<int>> range;

int main()
{
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	int T;
	cin >> T; 
	for (int x = 0; x < T; x++)
	{
		cin >> n >> m >> L >> V; 
		for (int i = 0; i < n; i++)
		{
			cin >> d[i] >> v[i] >> a[i];
			o[i] = 0;
		}
		for (int i = 0; i < m; i++)
		{
			cin >> p[i];
		}
		sort(p, p+m);
		
		int res = 0;
		int V_sq = V * V; // constant V square 
		for (int i = 0; i < n; i++) // all cars
		{
			if (a[i] == 0 && v[i] > V && d[i] < p[m-1])
			{ // always too fast
				res += 1;
				int detector_loc = lower_bound(p, p+m, d[i]) - p; // find next detector
				o[i] = detector_loc;
			}
			else if (a[i] > 0)
			{ // speed increasing
				double lim_s = (V_sq - v[i] * v[i]) / 2.0 / a[i] + d[i]; // distance when too fast
				int detector_loc = 0; 
				if (lim_s > 0)
					detector_loc = upper_bound(p, p+m, floor(lim_s)) - p; // find next
				else
					detector_loc = upper_bound(p, p+m, d[i]) - p; // too fast when drive into this road
				if (detector_loc < 0 || detector_loc > m-1) // will never be detected 
					o[i] = -1;
				else
				{
					res += 1; 
					o[i] = detector_loc; // mark nearest detector
				}
			}
			else if (a[i] < 0)
			{ // speed decreasing
				double lim_s = (V_sq - v[i] * v[i]) / 2.0 / a[i] + d[i]; // need detect it before
				int  detector_loc = lower_bound(p, p+m, ceil(lim_s)) - p - 1;
				if (detector_loc < 0 || detector_loc > m-1 || p[detector_loc] < d[i] || lim_s < 0) // will never be detected 
					o[i] = -1;
				else
				{
					res += 1;
					o[i] = detector_loc;
				}
			}
			else
			{
				o[i] = -1;
			}
		} 
		cout << res << " ";
		
		for (int i = 0; i < n; i++) // all cars
		{
			if (o[i] == -1) // cannot be detected
				continue;
			int st = 0;
			int sp = m - 1;
			if (a[i] >= 0) // find after o[i]
			{
				st = o[i];
			}
			else
			{
				st = d[i];
				sp = o[i];
			}
			bool is_in_range = false;
			for (int j = 0; j < range.size(); j++)
			{
				if ((st <= range[j][0] && range[j][0] <= sp) || (st <= range[j][1] && range[j][1] <= sp) || (st <= range[j][0] && sp >= range[j][1]))
				{ // has same part
					range[j][0] = max(range[j][0], st);
					range[j][1] = min(range[j][1], sp);
					is_in_range = true;
					break;
				}
			}
			if (!is_in_range)
			{ // create new range if not in range
				vector<int> new_range;
				new_range.push_back(st);
				new_range.push_back(sp);
				range.push_back(new_range); 
			}
		}
		int total = range.size(); // range amount at last = fewest detector amount
		
		
		cout << m - total << endl; 
 	}
	
	return 0;
}
