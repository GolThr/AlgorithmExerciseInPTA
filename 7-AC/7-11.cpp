#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int sum=0;
bool Check(int *a,string *ss,int n)
{
    int len=0;
    string l,s;
    int c;
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            c=min(ss[i].length(),ss[j].length());
            if(ss[i].substr(0,c)==ss[j].substr(0,c))//检查是否存在一个编码是另一个编码的前缀
            {
                return false;
            }
        }
        len+=a[i]*ss[i].length();
    }
    if(len!=sum)//如果长度不是最短长度
        return false;
    return true;
}
int main()
{
    priority_queue<int,vector<int>,greater<int> > Q;
    string ss[1001],s,code[1001];
    int n,n2,a[1001],t=0;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>ss[i];
        cin>>a[i];
        Q.push(a[i]);
    }
    while(Q.size()>1)//求最短编码的长度
    {
        t=0;
        t+=Q.top();
        Q.pop();
        t+=Q.top();
        Q.pop();
        sum+=t;
        Q.push(t);
    }
    cin>>n2;
    for(int i=0; i<n2; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>s;
            cin>>code[j];
        }
        if(Check(a,code,n)==true)
        {
            cout<<"Yes"<<endl;
        }
        else
        {
            cout<<"No"<<endl;
        }
    }
    return 0;
}

