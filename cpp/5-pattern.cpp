//depreciating star triangle

#include<bits/stdc++.h>
using namespace std;

void print_stars(int n)
{
    for(int i=1 ; i<=n ; i++)
    {
        for( int j=1 ; j<= n-i+1; j++)
        {
            cout<<"* ";
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
        print_stars(n);
        cout<<endl;
    }
    return 0;
}