#include<iostream>
#include<cstring>
using namespace std;

long long nCrRecursive(int n, int r)
{
    if(r>n)
        return 0;
    if(r==0 || r==n)
        return 1;
 
    return nCrRecursive(n-1, r-1)
           + nCrRecursive(n-1, r);
}

long long nCrIterative(int N, int R){
    long long mat[N+1][R+1];
    memset(mat, 0, sizeof(mat));
    mat[0][0] = 1;
    for(int n = 1; n<=N; n++){
        for(int r = 0; r<=n; r++){
            if(r==0 || r==n){
                mat[n][r] = 1;
            }
            else{
                mat[n][r] = mat[n-1][r-1] + mat[n-1][r];
            }
            if(n==N && r==R) return mat[N][R];
        }
    }
    return mat[N][R];
}

int main(){
    int n,r;
    cin>>n>>r;
    if(r>n){
        cout<<"Invalid input\n";
        return 0;
    }
    cout<<n<<" C "<<r<<":\n";
    cout<<"Recursive: "<<nCrRecursive(n,r)<<endl;
    cout<<"Iterative: "<<nCrIterative(n,r)<<endl;
    return 0;
}
