//character lower triangle

#include<bits/stdc++.h>
using namespace std;

void print_char(int n)
{   
    
    for(int i=0 ; i<n ; i++)
    {   
        for( char ch='A' ; ch <= 'A' + i ; ch++) //nice logic
        {                                        // here the inner lopping is
            cout<<ch<<" ";                       //done on the characters.
        }
        cout<<endl;
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen( "input.txt", "r", stdin);
        freopen( "output.txt" , "w" , stdout);
    #endif

    int t;
    cin>>t;

    for( int i=0 ; i<t ; i++)
    {
        int n;
        cin>>n;
        print_char(n);
        cout<<endl;
    }
    return 0;
}