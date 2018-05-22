#include<cstdio>
#include<map>
#define max(a,b) a>b ? a:b

using namespace std;

int main(void)
{
  int arv, vi, vroot;
  long long int c = 0, val = 0;
  map <int,long long int> list;
  scanf("%d",&arv);
  while(arv--)
  {
    int right = 0, left = 0;
    scanf("%d",&vi);
    list[vi] = 0;
    if(list.size()==1)
    {
      vroot = vi;
      printf("%d\n",0);
      continue;
    }
    map<int,long long int>::iterator it = list.find(vi);
    map<int,long long int>::iterator it_copy = it;
    if(vi>vroot)
    {
      if(++it != list.end())
        right = it->second;
      left = (--it_copy)->second;
    }
    else
    {
      right = (++it)->second;
      if(it_copy != list.begin())
        left = (--it_copy)->second;
    }
    val = max(right,left);
    val += 1;
    list[vi] = val;
    c = c+val;
    printf("%lld\n",c);
  }
}
