#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
class Course
{
  public:
  int a,d;
  long double b,c;
  string e;
  void swap(Course &a,Course &b)
  {
    Course c;
    a=c;
    a=b;
    b=c;
  };
};
int main()
{
  int n;
  cin>>n;
  Course course[n]; 
  for(int i=0;i<n;i++)
  {
    scanf("%d%f%f%d%s",&course[i].a,&course[i].b,&course[i].c,&course[i].d,&course[i].e);
  }
  bool flag;
  for (int i=n-1;i>=1;i--)
  {
    for(int j=0;j<i;j++)
    {
   		flag=false;
   		if(course[j].b<course[j+1].b){swap(course[j],course[j+1]);flag=true;}
	}
	if(flag==false)break;
  }
  for(int i=0;i<n;i++)
  {
    printf("%8d%10.2f%10.2f%8d%-s\n",&course[i].a,&course[i].b,&course[i].c,&course[i].d,&course[i].e);
  }
  return 0;
}
