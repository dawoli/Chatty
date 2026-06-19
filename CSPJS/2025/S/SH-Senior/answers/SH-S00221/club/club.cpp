#include <bits/stdc++.h>

using namespace std;

struct student
{
    long a[3];
    long now,first,second,third;
    long ftosv,stotv;
};

std::vector<student> s[3];

bool cmp(student a,student b)
{
    long ca,cb;
    if(a.now==a.second)
        ca=a.stotv;
    else
        ca=a.ftosv;
    if(b.now==b.second)
        cb=b.stotv;
    else
        cb=b.ftosv;
    return(ca>cb);
}

int main()
{
    FILE *fp_in=freopen("club.in","r",stdin);
    FILE *fp_out=freopen("club.out","w",stdout);
    long t,ti,fmax,maxpoint,sum;
    unsigned int i,n;
    bool done[3]={};
    student temp;
    cin>>t;
    for(ti=0;ti<t;ti++)
    {
        cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>temp.a[0]>>temp.a[1]>>temp.a[2];
            fmax=max(temp.a[0],max(temp.a[1],temp.a[2]));
            if(fmax==temp.a[0])
            {
                temp.first=0;
                temp.now=temp.first;
                if(max(temp.a[1],temp.a[2])==temp.a[1])
                {
                    temp.second=1;
                    temp.third=2;
                    temp.ftosv=temp.a[0]-temp.a[1];
                    temp.stotv=temp.a[1]-temp.a[2];
                }
                else
                {
                    temp.second=2;
                    temp.third=1;
                    temp.ftosv=temp.a[0]-temp.a[2];
                    temp.stotv=temp.a[2]-temp.a[1];
                }
                s[0].push_back(temp);
            }
            else if(fmax==temp.a[1])
            {
                temp.first=1;
                temp.now=temp.first;
                if(max(temp.a[0],temp.a[2])==temp.a[0])
                {
                    temp.second=0;
                    temp.third=2;
                    temp.ftosv=temp.a[1]-temp.a[0];
                    temp.stotv=temp.a[0]-temp.a[2];
                }
                else
                {
                    temp.second=2;
                    temp.third=0;
                    temp.ftosv=temp.a[1]-temp.a[2];
                    temp.stotv=temp.a[2]-temp.a[0];
                }
                s[1].push_back(temp);
            }
            else if(fmax==temp.a[2])
            {
                temp.first=2;
                temp.now=temp.first;
                if(max(temp.a[0],temp.a[1])==temp.a[0])
                {
                    temp.second=0;
                    temp.third=1;
                    temp.ftosv=temp.a[2]-temp.a[0];
                    temp.stotv=temp.a[0]-temp.a[1];
                }
                else
                {
                    temp.second=1;
                    temp.third=0;
                    temp.ftosv=temp.a[2]-temp.a[1];
                    temp.stotv=temp.a[1]-temp.a[0];
                }
                s[2].push_back(temp);
            }
        }
        s[0].shrink_to_fit();
        s[1].shrink_to_fit();
        s[2].shrink_to_fit();
        while(1)
        {
            fmax=0;
            maxpoint=-1;
            for(i=0;i<2;i++)
                if(s[i].size()>n/2&&s[i].size()>fmax)
                {
                    fmax=s[i].size();
                    maxpoint=i;
                }
            if(maxpoint==-1)
                break;
            sort(s[maxpoint].begin(),s[maxpoint].end(),cmp);
            done[maxpoint]=1;
            for(i=fmax-1;i>=(n/2);i++)
            {
                temp=s[maxpoint][i];
                if(!done[temp.first])
                {
                    temp.now=temp.first;
                    s[temp.first].push_back(temp);
                }
                else if(!done[temp.second])
                {
                    temp.now=temp.second;
                    s[temp.second].push_back(temp);
                }
                else
                {
                    temp.now=temp.third;
                    s[temp.third].push_back(temp);
                }
                s[maxpoint][i].a[maxpoint]=0;
            }
            s[maxpoint].resize(n/2);
        }
        sum=0;
        for(i=0;i<s[0].size();i++)
            sum+=s[0][i].a[0];
        for(i=0;i<s[1].size();i++)
            sum+=s[1][i].a[1];
        for(i=0;i<s[2].size();i++)
            sum+=s[2][i].a[2];
        cout<<sum<<'\n';
        s[0].clear();
        s[1].clear();
        s[2].clear();
        done[0]=0;
        done[1]=0;
        done[2]=0;
    }
    fclose(fp_in);
    fclose(fp_out);
    return(0);
}
