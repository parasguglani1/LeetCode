//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends

#define ll long long
vector<long long> printFirstNegativeInteger(long long int a[],
                                             long long int n, long long int k) {
                                                 
                                                 vector<ll> negs;
                                                 for(int i=0;i<n;i++)
                                                 {
                                                     if(a[i]<0)
                                                     {
                                                         negs.push_back(i);
                                                     }
                                                     
                                                 }
                                                 
                                                 vector<ll> ans(n-k+1);
                                                 int j=0,i=0;
                                                 int ngsz=negs.size();
                                                 while(i<n-k+1)
                                                {
                                                    if(j>=ngsz)
                                                    {
                                                        ans[i++]=0;
                                                        continue;
                                                    }
                                                    int curneg=negs[j];
                                                     if(i<curneg &&curneg>i+k-1)
                                                    {
                                                        ans[i++]=0;
                                                    }
                                                    else if(i<= curneg && curneg<i+k)
                                                    {
                                                        ans[i++]=a[curneg];
                                                    }
                                                    else if(curneg<i)
                                                    {
                                                        j++;
                                                    }

                                                    
                                                }
                                                return ans;
                                                
                                                 
                                                 
                                                 
 }