#include <iostream>
#include <vector>

using namespace std;


/* c++标准库有二分查找，这里只是为了自主实现来了解细节 */
/* 向量二分查找难点在于下标是size_t类型，注意无符号0-1类似情况避免 */
/*
左闭右开，只有+1,没有-1
[low, high)
[low, mid)
[mid + 1, high)
*/

template <typename T>
bool binary_search_vetcor(const T& key, typename vector<T>::const_iterator data, size_t N)
{
    size_t high = N;
    size_t low = 0;
    while(low < high)
    {
        size_t mid = low + (high - low) / 2;
        if(key < *(data + mid))
        {
            high = mid;
        }
        else if(*(data + mid) < key)
        {
            low = mid + 1;
        }
        else
        {
            return true;
        }
    }

    return false;
}
int main()
{
    vector<int> V = {1,2,3,4,5};
    cout << binary_search_vetcor(2, V.cbegin(), 5) << endl;
    cout << binary_search_vetcor(0, V.cbegin(), 5) << endl;
    cout << binary_search_vetcor(2, V.cbegin() + 2, 3) << endl;
    cout << binary_search_vetcor(0, V.cbegin(), 0) << endl;

    return 0;
}