#include <bits/stdc++.h>
using namespace std;
const int M = 1e5;
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int n, car[M], sp[M], m, v, T, x, maxn;
	cin>>T;
	while(T--)
	{
		maxn = 1;
		cin >> n >> m >> x >> v ;
		for(int i = 0;i < n;){
			cin >> car[i] >> sp[i] >> x;
			if (sp[i] <= v){n--;i--;}
			i++;
		}
		
		sort(car,car+n);
		x = 0;
		for(int i = 0;i < m;i ++ )
		{
			cin >> x;
			if(x>maxn)
			{
				maxn = x;
			}
		}
		int c = n;
		for(int i = 0;i < n;i ++ )
		{
			if(maxn < car[i])
			{
				c = i;
				break;
			}
		}
		cout << c;
		cout << " " ;
		if(n == 0){
			cout << m ;
		}else{
			cout << m - 1;
		}
		
		cout<<endl;
		
	}
	
	return 0;
}
