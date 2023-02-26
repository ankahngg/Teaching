#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define sc second
#define ll long long
#define fr(i,a,b) for(int i=a;i>=b;i--)
#define fo(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int M=1e6+6;
    
    
int t,n,a[M],kq=INT_MAX;
long long k,sum;
    
int main(){
   
    //freopen("MSUM.inp","r",stdin);
    //freopen("MSUM.out","w",stdout);
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin >> n >> k;
    
    fo(i,1,n) cin >> a[i];

    deque<int> dq;

    fo(i,1,n) {
        int x = a[i];
        // đẩy a[i] vô đầu
        dq.push_front(x);
        // cập nhật sum
        sum = 0ll + sum + x;
        
        // khi sum - back >= k thì ta sẽ rút back ra để cực tiểu hóa độ dài
        // mà tổng vẫn >= k
        while(!dq.empty() && 0ll + sum - dq.back() >= k) {
            // cập nhật sum mỗi lần xóa
            sum = 0ll + sum - dq.back();
            // bỏ nó ra khỏi deque
            dq.pop_back();
        }

        // kiểm tra nếu >= k thì ta cập nhật vào kết quả
        if(sum >= k) kq = min(kq,(int)dq.size());
    }

    if(kq == INT_MAX) cout << 0;
    else cout << kq;
}