#include<bits/stdc++.h>
using namespace std;

// 他明白 
struct Ren{
	int gr, no;	
}grade[105];

bool cmp(Ren a, Ren b)
{
	if(a.gr>b.gr)return true;
	return false;
}

int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0); 
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n, m;
    cin>>n>>m;
    for(int i=0; i<n*m; i++)
    {
    	int x;
    	cin>>x;
    	grade[i].no=i;grade[i].gr=x;
	}
	sort(grade, grade+(n*m), cmp);
	int pos=0;
	for(int i=0; i<n*m; i++)
    {
    	if(grade[i].no==0){
    		pos=i;break;
		}
	}
	cout<<(pos/n)+1<<" ";
	if((pos/n)%2==0)
	{
		cout<<pos%n+1;
	}else{
		cout<<n-pos%n;
	}
    return 0;
}
// 他明白 
