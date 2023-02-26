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
string s;
stack<int> st;
bool exist[30];
int cnt[30];
    
int main(){
    //freopen("DUPLICATE.inp","r",stdin);
    //freopen("DUPLICATE.out","w",stdout);
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin >> n >> s;

    // khởi tạo
    for(int i=0;i<=25;i++) exist[i] = false, cnt[i] = 0;
    // Tao mang cnt
    for(auto x : s) cnt[x-'a'] ++;

    for(auto x : s) {
        // ta sẽ làm việc với number , ta coi 'a' là 0, 'b' là 1 , ..., 'z' là 25
        int num = x-'a';

        // Kiem tra xem s[i] da ton tai trong xau chua
        if(!exist[num]){
            // Khi top > num và cnt của top !=0 
            // Anh viết cnt[st.top()] tương đương với cnt[st.top()] != 0
            while(!st.empty() && st.top() > num && cnt[st.top()]) 
                exist[st.top()] = false ,st.pop(); // xóa nó và đánh dấu nó đã không còn ở trong stack nx
            st.push(num); // Đẩy s[i] của mình vô
            exist[num] = true; // đánh dấu nó là nó đã ở trong stack
        }

        // cập nhật số lượng
        cnt[num] --;
    }

    string kq="";

    while(!st.empty()) {
        char x = 'a' + st.top();
        kq = kq + x;
        st.pop();
    }
    // reverse lại
    reverse(kq.begin(),kq.end());

    cout << kq;
}