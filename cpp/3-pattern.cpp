//lower triangle progressive counting

#include<bits/stdc++.h>
using namespace std;

void print_num(int n)
{
    for(int i=1 ; i<=n ; i++)
    {
        for( int j=1 ; j<=i ; j++)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt" , "r" , stdin);
        freopen( "output.txt" , "w" , stdout);
    #endif


    //testcases
    int t;
    cin>>t;
    
    for( int i=0 ; i<t ; i++)
    {
        int n;
        cin>>n;
        print_num(n);
        cout<<endl;
    }
    return 0;
}