#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define sc second
#define ll long long
#define fr(i,a,b) for(int i=a;i>=b;i--)
#define fo(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int M=1e6+6;
    
    
int t,n,a[M],f[M],x[M],y[M],m;

 
int main(){
    cin >> t;
    while(t--) {
        cin >> n >> m;
        // f[i] là vị trí < i lớn nhất mà i với j không quen nhau
        fo(i,1,m) {
            cin >> x[i] >> y[i];
            if(x[i] < y[i]) swap(x[i],y[i]);
            f[x[i]] = max(f[x[i]],y[i]);
        }

        long long kq=0;
        deque<int> dq;

        fo(i,1,n) {
            dq.push_front(i);
             
            // Khi mà đoạn từ back -> i trong deque vẫn vướng thằng f[i] - thằng mà i không quen
            // thì ta sẽ xóa back đi
            while(!dq.empty() && dq.back() <= f[i]) dq.pop_back();
            
            // số dãy tốt mà kết thúc tại i
            // bằng độ dài của đoạn back -> i hay = dq.size() luôn            
            kq = 0ll + kq + (long long) dq.size();
        }

        cout << kq<<"\n";

        // reset
        fo(i,1,m) f[x[i]] = f[y[i]] = 0;
    }
}