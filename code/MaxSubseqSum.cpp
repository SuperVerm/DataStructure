#include <iostream>

using namespace std;

//原始办法，i指向子列头，全部遍历。时间复杂度O(n*2)。
int MaxSubseqSum01(int n, int a[])
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

//最优办法，一次遍历。前者累和小于0就抛弃。时间复杂度O(n)。
int MaxSubseqSum02(int n, int a[])
{
    int max = 0;
    int temp = 0;
    for(int i = 0; i < n; i++)
    {
        temp += a[i];
        if(temp < 0)
        {
            temp = 0;
        }else if(temp > max)
        {
            max = temp;
        }
    }
    return max;
}

int main()
{
    int a[] = {5, 2, -3, 6, -7, 8};   
    //计算数组的长度n。
    int n = sizeof(a) / sizeof(a[0]);
    //两种方式的结果。
    int result01 = MaxSubseqSum01(n, a);
    int result02 = MaxSubseqSum02(n, a);
    cout << "最大的子列和为" << result01 << endl;
    cout << "最大的子列和为" << result02 << endl;
    system("pause");
    return 0;
}
