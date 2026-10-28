#include<iostream>
using namespace std;

long long times(char a, char b, char c, int n);

int main(){
    int n;
    cin >> n;
    cout << times('A', 'B', 'C', n) << endl;
}

long long times(char src, char mid, char dist, int n){
    if (n == 0) return 0;

    long long count = 0;

    //运用递归解决汉诺塔
    count += times(src, dist, mid, n - 1);
    cout << src << "->" << dist << ' ';
    count++;
    count += times(mid, src, dist, n - 1);
    return count;
}

