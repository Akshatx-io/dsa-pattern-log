//kite

#include<bits/stdc++.h>
using namespace std;

void pyramid(int n)
{
    for(int i=0 ; i<n ; i++)
    {
        for( int j=0 ; j< n-i-1; j++) //for space
        {
            
            cout<<" "<<" ";
        }

        for( int j=0 ; j< 2*i+1; j++) //for stars
        {
            
            cout<<"* ";
        }

        for( int j=0 ; j< n-i-1; j++) //for spaces
        {
            
            cout<<" "<<" ";
        }
        cout<<endl;
    }
}

void inverted_pyramid(int n)
{
    for(int i=0 ; i<n ; i++)
    {
        for( int j=0 ; j< i+1; j++) //for space--> here j<i+1 cuz to increase
        {                           //one more space acc. to the upper pyramid
            
            cout<<" "<<" ";
        }

        for( int j=0 ; j< 2*n - 2*i - 1; j++) //for stars
        {
            
            cout<<"* ";
        }

        for( int j=0 ; j< i+1; j++) //for space--> here j<i+1 cuz to increase
        {                           //one more space acc. to the upper pyramid
            
            cout<<" "<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen( "input.txt" , "r" , stdin);
        freopen( "output.txt" , "w" , stdout);
    #endif

    //testcases
    int t;
    cin>>t;
    for( int i=0 ; i<t ; i++)
    {
        int n;
        cin>>n;
        pyramid(n);
        inverted_pyramid(n-1);
        cout<<endl;
    }
    return 0;
}