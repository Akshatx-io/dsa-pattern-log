//character special lower triangle 

#include<bits/stdc++.h>
using namespace std;

//METHOD 1
// void print_triangle(int n)
// {   
//     for(int i=0 ; i<n ; i++)
//     {  
//         char ch='A' + n - i - 1;         // obvious logic
//         for(int j=0 ; j<=i ; j++)
//         {
//             cout<<ch<<" ";
//             ch++;       
//         }
//         cout<<endl;
//     }
// }

//METHOD 2
void print_triangle(int n)
{   
    for(int i=0 ; i<n ; i++)
    {
        for(char ch='E'-i ; ch<='E' ; ch++) //this is a good logic
        {                                   
            cout<<ch<<" ";       
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
        print_triangle(n);
        cout<<endl;
    }
    return 0;
}