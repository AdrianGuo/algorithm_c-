#include <iostream>
#include <vector>

using namespace std;

/* 了解语言基础，学习算法技巧的一个比较好的问题 */


/* 计算迭代长度 */
size_t iterative_collatz(size_t n)
{
    if(n < 1)
    {
        return 0;
    }
    size_t l = 1;
    /* 注意循环条件，若是！=0则无法跳出循环 */
    while(n != 1)
    {
        /* n是偶数or奇数 */
       if(n % 2 == 0)
       {
           n = n /2;
       }
       else
       {
           n = 3*n+1;
       }
       ++l;
    }
    return l;
}

size_t memoized_collatz(vector<size_t>& v, size_t n)
{
    //前提 n > 0，先做几次，直到n处于v的范围
    size_t l = 1;
    /* n是否在向量范围内了 */
    while(n >= v.size())
    {
        n = (n % 2 == 0) ? n/2 : 3*n+1;
        ++l;
    }
    /* 初始值为0，未算出 */
    if(v[n] == 0)
    {
        v[n] = memoized_collatz(v, ((n % 2 == 0) ? n/2 : 3*n+1) ) + l;
    }
    return v[n];
}

int main()
{
    size_t n;
    cin >> n;
    const size_t m = 10000;

    vector<size_t> v(m,0);

    /* v[2*a]都可以预先赋值，a>=1，且2*a < size_t */

    /* v[0]不用管，n的有效范围是n>=1 */
    v[1] = 1;
    
    if(n<1)
    {
        cout << 0 << endl;
    }
    else
    {
        cout << memoized_collatz(v, n) << endl;
    }
    return 0;
}