#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main()
{
    freopen("r","seat.in",stdin)
    freopen("w","seat.out",stdout);
    int n,m,g[105]={},k[12][12]={},cnt=0;
    cin >> n >> m;
    for(int i = 1;i <= n*m;i++)
    {
        cin >> g[i];
    }
    int niubi=g[1];
	sort(g+1,g+n*m+1,cmp);
    for(int i = 1;i <= m;i++)
    {
    	int x=i%2;
        if(x==1)
        {
            for(int j = 1;j <= n;j++)
            {
                cnt++;
                k[j][i]=g[cnt];
            }
        }
        else
        {
            for(int j = n;j >= 1;j--)
            {
                cnt++;
                k[j][i]=g[cnt];
        	}
        }
    }
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= m;j++)
        {
            if(k[i][j]==niubi)
            {
                cout << j << " " << i;
                return 0;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
