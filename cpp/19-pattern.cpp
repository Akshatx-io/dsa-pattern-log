//spaced kite in a star box 

#include<bits/stdc++.h>
using namespace std;

void print_upper_half(int n)
{   
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<n-i ; j++) //for stars
        {                                   
            cout<<"*"<<" ";       
        }

        for(int j=0 ; j< 2*i ; j++) //for spaces
        {                                   
            cout<<" "<<" ";       
        }

        for(int j=0 ; j<n-i ; j++) //for stars
        {                                   
            cout<<"*"<<" ";       
        }
        cout<<endl;
    }
}
void print_lower_half(int n)
{   
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<i+1 ; j++) // for stars
        {                                   
            cout<<"*"<<" ";       
        }

        for(int j=0 ; j< 2*n-2*(i+1) ; j++) //for spaces
        {                                   
            cout<<" "<<" ";       
        }

        for(int j=0 ; j<i+1 ; j++) // for stars
        {                                   
            cout<<"*"<<" ";       
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
        print_upper_half(n);
        print_lower_half(n);
        cout<<endl;
    }
    return 0;
}