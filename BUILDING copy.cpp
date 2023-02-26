#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define fi first
#define sc second
#define ll long long
#define fr(i,a,b) for(int i=a;i>=b;i--)
#define fo(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int M=1e6+6;
    
    
int t,n,a[M],l[M],r[M];
// l[i] : max of floors from 1 -> i if i is the peak
// r[i] : max of floors from i -> n if i is the peak

    
 main(){
    //https://codeforces.com/contest/1313/problem/C2
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    //freopen("input.inp","r",stdin);
    //freopen("output.out","w",stdout);
    cin >> n;
    fo(i,1,n) cin >> a[i];

    stack<int> st;

    // left to right
    fo(i,1,n) {
        while(!st.empty() && a[st.top()] >= a[i]) st.pop();

        // st.top() sẽ là posL[i] luôm
        if(!st.empty()) l[i] = l[st.top()] + (i-st.top())*a[i];
        // nếu stack rỗng có nghĩa là từ 1 -> i-1 toàn nhà cao hơn a[i] nên
        // tất cả nhà đấy cho cao = a[i] và số nhà là i mà mỗi nhà cao a[i]
        // nên tổng số tầng là i * a[i];
        else l[i] = i * a[i];

        st.push(i);
    }

    //reset stack
    while(!st.empty()) st.pop();

    // right to left
    fr(i,n,1) {
        while(!st.empty() && a[st.top()] >= a[i]) st.pop();
        
        // st.top() sẽ là posR[i] luôm
        if(!st.empty()) r[i] = r[st.top()] + (st.top()-i)*a[i];
        // nếu stack rỗng có nghĩa là từ i+1 -> n toàn nhà cao hơn a[i] nên
        // tất cả nhà đấy cho cao = a[i] và số nhà là n-i+1 mà mỗi nhà cao a[i]
        // nên tổng số tầng là (n-i+1) * a[i];
        else r[i] = (n-i+1) * a[i]; 

        st.push(i);
    }

    // Find max
    int peak, mx=-1;
    fo(i,1,n) {
        int val = l[i] + r[i] - a[i];
        if(val > mx) mx = val, peak = i;
    }


    // cout << peak<<"\n";
    // fo(i,1,n) cout << l[i]<<" "; cout <<"\n";
    // fo(i,1,n) cout << r[i]<<" "; cout <<"\n"; 

    deque<int> dq;
    dq.push_back(a[peak]);
        
    // contruct the right of peak
    int val = a[peak];
    fo(i,peak+1,n) {
        val = min(val, a[i]);
        dq.push_front(val);
    }

    // construct the left of peak
    val = a[peak];
    fr(i,peak-1,1) {
        val = min(val,a[i]);
        dq.push_back(val);
    }

    // print ans
    while(!dq.empty()) {
        cout << dq.back()<<" ";
        dq.pop_back();
    }
}