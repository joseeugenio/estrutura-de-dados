#include<iostream>
#include<stdio.h>

#define sf scanf
#define pf printf
using namespace std;
int main()
{
	int t;
	sf("%d",&t);
	while(t--)
	{
		int n,m;
		sf("%d%d",&n,&m);
		pf("%d",2*m*n-n-m);
	}
return 0;
}
