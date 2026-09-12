//character symmetric pyramid

#include<bits/stdc++.h>
using namespace std;

void print_pyramid(int n)
{   
    
    for(int i=0 ; i<n ; i++)
    {  
         char ch='A';

        for(int j=0 ; j<n-i-1 ; j++)  //for spaces
        {
            cout<<" "<<" ";          
        }

        for( int j=0 ; j< 2*i+1; j++) //for symmetric pyramid
        {
            if( j < (2*i + 1)/2 )
            {
                cout<<ch<<" ";
                ch++;
            }
            else
            {
                cout<<ch<<" ";
                ch--;
            }
        }

        for(int j=0 ; j<n-i-1 ; j++)  //for spaces
        {
            cout<<" "<<" ";          
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
        print_pyramid(n);
        cout<<endl;
    }
    return 0;
}