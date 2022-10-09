#include <iostream>

using namespace std;

//原始办法，i指向子列头，j指向子列尾，全部遍历。
int MaxSubseqSum1(int n, int a[])
{
    int max = 0;
    for(int i = 0; i < n; i++)
    {
        int temp = 0;
        for(int j = i; j < n; j++)
        {
            temp += a[j];
            if(temp > max)
            {
                max = temp;
            }
        }
    }
    return max;
}

int main()
{
    int a[] = {1,2,-3,6};
    //计算数组的长度n。
    int n = sizeof(a) / sizeof(a[0]);

    int result = MaxSubseqSum1(n,a);
    cout << "最大的子列和为" << result << endl;
    system("pause");
    return 0;
}