#include<cstdio>
#include<algorithm>
using namespace std;
struct yue
{
	double p,num;
	double x;
};
int cmp(yue a, yue b) 
{
	return a.x>b.x;
}
int main()
{
	int n, d; 
	struct yue s[10000];
	scanf("%d%d", &n,&d);
	for (int i = 0; i < n; i++) scanf("%lf", &s[i].num);
	for (int i = 0; i < n; i++) scanf("%lf", &s[i].p);
	for (int i = 0; i < n; i++) s[i].x = s[i].p / (s[i].num * 1.0);
	sort(s, s + n, cmp);
	double sum=0;
	for(int i=0;i<n;i++)
	{		
		if(d>s[i].num)
		{
			sum+=s[i].p;
			d-=s[i].num;
		}		
		else 
		{
			sum+=s[i].x*d;
			d=0;
			break;
		}
	}
	printf("%.2f\n",sum);
	return 0;
}