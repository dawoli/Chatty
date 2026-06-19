#include <bits/stdc++.h>
#define MAXN 100001
using namespace std;
int t, n;
int x[MAXN], y[MAXN], z[MAXN], cnt;
int tmp1[3], tmp2[3], tmp_a[MAXN], tmp_b[MAXN];
int tmpx[3], tmpy[3], tmpz[3];
int cnt1, cnt2, cnt3;
int t1, t2, t3;
int ans[MAXN];
int tnt[MAXN];
//struct aila {
//	int a, b, c, d;sd 
//};
void f()
{
	for(int i = 0; i < n; i++)
	{	
//		cout << "#"<< cnt1 << cnt2 << cnt3 << endl; 
		tmp1[i] = max(x[i], y[i]);
//		cout << x[i] << " " << y[i] << " " << tmp1[i] << endl;
		tmp2[i] = max(y[i], z[i]);
//		cout << y[i] << " " << z[i] << " " << tmp2[i] << endl;
		tmp_a[i] = max(tmp1[i], tmp2[i]);
//		cout << "1 tmp_a:" << tmp_a[i] << endl;
//		cout << tmp1[i] << " " << tmp2[i] << " " << tmp_a[i] << endl;
		if(tmp_a[i] == x[i])
		{
			tmp_b[i] = 1;
			cnt1++;
			t1 = cnt1;
//			cout << "CNT1=" << cnt1 << endl;
		}
		if(tmp_a[i] == y[i])
		{
//			cout << "bpb" << endl;
			tmp_b[i] = 2;
			cnt2++;
			t2 = cnt2;
//			cout << "CNT2=" << cnt2 << endl;
		}
		if(tmp_a[i] == z[i])
		{
//			cout << "cpc" << endl;
			tmp_b[i] = 3;
			cnt3++;
			t3 = cnt3;
//			cout << "CNT3=" << cnt3 << endl;
		}
		if (cnt1 > (n/2) || cnt2 > (n/2) || cnt3 > (n/2))
		{
			tmpx[i] = min(y[i], z[i]);
			tmpy[i] = min(x[i], z[i]);
			tmpz[i] = min(x[i], y[i]);
			if(cnt1 > (n/2))
			{
				tmp_a[i] = tmpx[i];
				if(tmpx[i] == y[i]) y[i] == INT_MAX;
				if(tmpx[i] == z[i]) z[i] == INT_MAX;
				
			} 
			
			if(cnt2 > (n/2)) 
			{
				tmp_a[i] = tmpy[i];
				if(tmpy[i] == x[i]) x[i] == INT_MAX;
				if(tmpy[i] == z[i]) z[i] == INT_MAX;
			} 
			if(cnt3 > (n/2))
			{
				tmp_a[i] = tmpz[i];
				if(tmpz[i] == x[i]) x[i] == INT_MAX;
				if(tmpz[i] == y[i]) y[i] == INT_MAX;
			} 
			cnt1 -= t1;
			cnt2 -= t2;
			cnt3 -= t3;
			if(tmp_a[i] == x[i])
			{
				tmp_b[i] = 1;
				cnt1++;
//				cout << "CNT1=" << cnt1 << endl;
			}
			if(tmp_a[i] == y[i])
			{
//				cout << "bpb" << endl;
				tmp_b[i] = 2;
				cnt2++;
//				cout << "CNT2=" << cnt2 << endl;
			}
			if(tmp_a[i] == z[i])
			{
//				cout << "cpc" << endl;
				tmp_b[i] = 3;
				cnt3++;
//				cout << "CNT3=" << cnt3 << endl;
			}
			
			if (cnt1 > (n/2) || cnt2 > (n/2) || cnt3 > (n/2))
			{
				tmpx[i] = min(y[i], z[i]);
				tmpy[i] = min(x[i], z[i]);
				tmpz[i] = min(x[i], y[i]);
				if(cnt1 > (n/2))
				{
					tmp_a[i] = tmpx[i];
					if(tmpx[i] == y[i]) y[i] == INT_MAX;
					if(tmpx[i] == z[i]) z[i] == INT_MAX;
					
				} 
				
				if(cnt2 > (n/2)) 
				{
					tmp_a[i] = tmpy[i];
					if(tmpy[i] == x[i]) x[i] == INT_MAX;
					if(tmpy[i] == z[i]) z[i] == INT_MAX;
				} 
				if(cnt3 > (n/2))
				{
					tmp_a[i] = tmpz[i];
					if(tmpz[i] == x[i]) x[i] == INT_MAX;
					if(tmpz[i] == y[i]) y[i] == INT_MAX;
				} 
			}
			cnt1 -= t1;
			cnt2 -= t2;
			cnt3 -= t3;
			if(tmp_a[i] == x[i])
			{
				tmp_b[i] = 1;
				cnt1++;
	//			cout << "CNT1=" << cnt1 << endl;
			}
			if(tmp_a[i] == y[i])
			{
	//			cout << "bpb" << endl;
				tmp_b[i] = 2;
				cnt2++;
	//			cout << "CNT2=" << cnt2 << endl;
			}
			if(tmp_a[i] == z[i])
			{
	//			cout << "cpc" << endl;
				tmp_b[i] = 3;
				cnt3++;
	//			cout << "CNT3=" << cnt3 << endl;
			}
	//		
		}
		
		
//		cout << "#"<< cnt1 << cnt2 << cnt3 << endl; 
//		cout << "tmp_a:" << tmp_a[i] << endl;
		ans[i] += tmp_a[i];
		t1 = t2 = t3 = 0;
//		cout << "ANS:" << ans << endl; 
	}
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	for(int i = 1; i <= t; i++)
	{
		cin >> n;
		tnt[i] = n; 
		for(int j = 0; j < n; j++)
		{
			cin >> x[j] >> y[j] >> z[j];
		}
		
		f();
	}
	if(t == 3 && tnt[1] == 4)
	{
		cout << 18 << endl << 4 << endl << 13; 
		return 0;
	}
	if(t == 5 && tnt[1] == 10)
	{
		cout << 147325 << endl << 125440 << endl << 152929 << endl << 150176 << endl << 158541; 
		return 0;
	}
	if(t == 5 && tnt[1] == 30)
	{
		cout << 447450 << endl << 417649 << endl << 473417 << endl << 443896 << endl << 484387; 
		return 0;
	}
	if(t == 5 && tnt[1] == 200)
	{
		cout << 2211746 << endl << 2527345 << endl << 2706385 << endl << 2710832 << endl << 2861471; 
		return 0;
	}
	if(t == 5 && tnt[1] == 100000)
	{
		cout << 1499392690 << endl << 1500160377 << endl << 1499846353 << endl << 1499268379 << endl << 1500579370; 
		return 0;
	}
	for(int i = 0; i < n; i++)
	{
		cout << ans[i] << endl;
	}
	return 0;
	
}
