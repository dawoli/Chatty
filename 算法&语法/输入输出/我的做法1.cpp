#include<bits/stdc++.h>
using namespace std;
int main()
{
  int a,h;
  scanf("%o%d",&a,&h);
  for(int i=1;i<=h;i++)
  {
    for(int z=1;z<=h-i;z++)
    {
      printf("   ");
    }
    for(int y=1;y<=i;y++)
    {
      printf("%-6o",a);
      a+=i;
      if(y==i)a+=1;
    }
    printf("\n");
  }
  return 0;
}
