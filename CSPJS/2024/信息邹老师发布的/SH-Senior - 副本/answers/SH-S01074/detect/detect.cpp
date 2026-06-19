#include <bits/stdc++.h>
using namespace std;
struct car
{
    int d, v, a;
};
struct cmp
{
    bool operator()(vector<int> a, vector<int> b)
    {
        return a.size() > b.size();
    }
};
int main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int ld;
    cin >> ld;
    for (int asd = 0; asd < ld; asd++)
    {
        int n, m, l, v;
        cin >> n >> m >> l >> v;
        vector<car> crs;
        for (int i = 0; i < n; i++)
        {
            car tmp;
            cin >> tmp.d >> tmp.v >> tmp.a;
            crs.push_back(tmp);
        }
        priority_queue<vector<int>, vector<vector<int>>, cmp> detecter;
        map<int,bool> mp;
        for (int i = 0; i < m; i++)
        {
            vector<int> tmp;
            int t2;
            cin>>t2;
            for(int j=0;j<n;j++){
                if(crs[j].v*crs[j].v+2*crs[j].a*(t2-crs[j].d)>=0&&(!((v>=crs[j].v)&&(crs[j].d==0)))&&(double)v<sqrt(crs[j].v*crs[j].v+2*crs[j].a*(t2-crs[j].d))){
                    tmp.push_back(j);
                    mp[j]=true;
                }
            }
        }
        int a1=0;
        for(auto it=mp.begin();it!=mp.end();it++){
            if(it->second){a1++;}
        }
        cout<<a1<<endl<<a1;
    }
    fclose(stdin);
    fclose(stdout);
}
