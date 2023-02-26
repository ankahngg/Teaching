#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define sc second
#define ll long long
#define fr(i,a,b) for(int i=a;i>=b;i--)
#define fo(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int M=1e6+6;
    
    
int t,n,a[M];
    
int main(){
    //freopen("input.inp","r",stdin);
    //freopen("output.out","w",stdout);
    cin >> n;
    fo(i,1,n) cin >> a[i];

    stack<int> st;
    
    // Giống hệt cách làm của bài kiểm tra dãy ngoặc đúng
    // Xem lại vid để hiểu hơn tại sao lại làm vậy
    fo(i,1,n) {
        if(!st.empty() && st.top() % 2 == a[i] % 2) st.pop();
        else st.push(a[i]);
    }
    

    if(st.size() > 1) cout << "NO\n";
    else cout <<"YES\n";


}