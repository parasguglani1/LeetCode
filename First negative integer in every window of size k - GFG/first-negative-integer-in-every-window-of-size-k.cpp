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
                                                 
                                                 set<int> st;
                                                 
                                                 vector<ll> negs;
                                                 for(int i=0;i<n;i++)
                                                 {
                                                     if(a[i]<0)
                                                     {
                                                         negs.push_back(i);
                                                     }
                                                     
                                                 }
                                                 
                                                 vector<ll> ans(n-k+1);
                                                 int j=0;
                                                 int ngsz=negs.size();
                                                for(int i=0;i<n-k+1;i++)
                                                {
                                                    if(j<ngsz &&i<= negs[j] && negs[j]<i+k)
                                                    {
                                                        ans[i]=a[negs[j]];
                                                    }
                                                    else if(j>=ngsz ||(i<negs[j] &&negs[j]>i+k-1))
                                                    {
                                                        ans[i]=0;
                                                    }
                                                    else if(j<ngsz &&negs[j]<i)
                                                    {
                                                        j++;
                                                        i--;
                                                    }

                                                    
                                                }
                                                return ans;
                                                
                                                 
                                                 
                                                 
 }