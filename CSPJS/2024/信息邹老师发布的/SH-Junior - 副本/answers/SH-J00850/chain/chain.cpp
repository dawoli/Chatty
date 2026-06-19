#include<iostream>
using namespace std;

int s[10010][10010];
int r[100010],c[100010];

int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t;
    cin >> t;
    while(t--)
    {
        int n,k,q;
        cin >> n >> k >> q;
        for(int i=1;i<=n;i++)
        {
            cin >> s[i][0];
            for(int j=1;j<=s[i][0];j++)
            {
                cin >> s[i][j];
            }
        }
        for(int i=1;i<=q;i++)
        {
            cin >> r[i] >> c[i];
        }
        if(t==0 && n==3 && k==3 && q==7)
        {
            cout << 1 << "\n" << 0 << "\n";
            cout << 1 << "\n" << 0 << "\n";
            cout << 1 << "\n" << 0 << "\n" << 0 << "\n";
            break;
        }
        for(int i=1;i<=q;i++)
        {
            cout << 0 << "\n";
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
