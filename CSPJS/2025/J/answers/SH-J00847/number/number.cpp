#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int main()
{
    freopen("r","number.in",stdin);
    freopen("w","number.out",stdout);
	string s;
    string k;
    cin >> s;
    int kum=0,m = s.size();
    for(int i = 0;i < m;i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            k[kum]=s[i];
            kum++;
        }
    }
    for(int i = 0;i < kum;i++)
    {
        for(int j = i+1;j < kum;j++)
        {
            if(k[i]<k[j])
			{
				swap(k[i],k[j]);
			}
        }
    }
    for(int i = 0;i < kum;i++) cout<<k[i];
    fclose(stdin);
    fclose(stdout);

    return 0;
}
