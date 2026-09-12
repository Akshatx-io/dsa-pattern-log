//inverted star pyramid

#include<bits/stdc++.h>
using namespace std;

void print_stars(int n)
{
    for(int i=0 ; i<n ; i++)
    {
        for( int j=0 ; j< i; j++) //for space
        {
            
            cout<<" "<<" ";
        }

        for( int j=0 ; j< 2*n - 2*i - 1; j++) //for stars
        {
            
            cout<<"* ";
        }

        for( int j=0 ; j< i; j++) //for spaces
        {
            
            cout<<" "<<" ";
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