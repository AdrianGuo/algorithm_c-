#include <iostream>
using namespace std;

template <typename T>
/* 返回查找元素的下标 */
int binary_search_array(const T& key, const T data[], int N)
{
    if(N <= 0)
    {
        return -1;
    }
    /* 真实存在的位置 */
    int low = 0;
    int high = N - 1;
    /* 查找区间不为空集 */
    while(low <= high)
    {
        /* 防止溢出 */
        int mid = low + (high - low) / 2;
        if(key < data[mid])
        {
            high = mid - 1;
        }
        else if(data[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            return mid;
        }
    }

    return -1;
}

int main()
{
    int a[5] = {1,2,3,4,5};
    cout << binary_search_array(2, a, 5) << endl;
    cout << binary_search_array(0, a, 5) << endl;
    cout << binary_search_array(2, a + 2, 3) << endl;
    cout << binary_search_array(0, a, 0) << endl;
}