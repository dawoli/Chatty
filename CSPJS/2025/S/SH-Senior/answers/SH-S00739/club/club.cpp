#include <bits/stdc++.h>
using namespace std;
const int N = 100005; 
int t,n,x;
int ans[N];
struct A{
	double p1,p2,p3;
}a[N];
bool cmp(A x,A y)
{
	return max(x.p1,max(x.p2,x.p3)) > max(y.p1,max(y.p2,y.p3));
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--)
	{		
		int v[4] = {0,0,0,0};
		int s[4] = {0,0,0,0};
		cin >> x;
		int lim = x/2;
		for(int i = 1; i <= x; i++)
		{
			cin >> a[i].p1 >> a[i].p2 >> a[i].p3;
			if(a[i].p1) s[1]++;
			if(a[i].p2) s[2]++;
			if(a[i].p3) s[3]++;
		}
		for(int i = 1; i <= 3; i++)
			if(s[i] == 0) s[i] = 1;
		sort(a+1,a+x+1,cmp);
		//cout << endl;
		//for(int i = 1; i <= x; i++)
			//cout <<"aÐòÁÐ "<<a[i].p1 << " " << a[i].p2 << " " << a[i].p3<< endl;
		for(int i = 1; i <= x; i++)
		{
			double ans1;
			double d1 = 0,d2 = 0,d3 = 0;
			if(v[1]<lim) d1 = a[i].p1/s[1];
			if(v[2]<lim) d2 = a[i].p2/s[2];
			if(v[3]<lim) d3 = a[i].p3/s[3];

			//cout << endl;
			//cout <<"d"<< d1 << " " << d2 << " " << d3 <<endl;
			//cout << endl;
			ans1 = max(d1,max(d2,d3));
			if(ans1 == d1 && v[1]<lim) v[1]++,ans1 = a[i].p1;
			else if(ans1 == d2 && v[2]<lim) v[2]++,ans1 = a[i].p2;
			else if(ans1 == d3 && v[3]<lim) v[3]++,ans1 = a[i].p3;	
			//cout << ans1 << endl;
			ans[i] = max(ans[i-1],int(ans1+ans[i-1]));
			//cout <<"v"<< v[1] << " " << v[2] << " " << v[3] << endl;
			//cout << endl;			
		}
		cout << int(ans[x]) << endl;	
	}	
}
 
