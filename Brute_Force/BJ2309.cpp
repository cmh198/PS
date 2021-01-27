#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int key = 100;
    int sum = 0;
    vector<int> tall(9, 0);

    vector<int> ans;

    for (int i = 0; i < 9; i++)
        cin >> tall[i];

    for (int i = 0; i < 8; i++)
    {
        for (int j = i + 1; j < 9; j++)
        {
            for (int k = 0; k < 9; k++)
            {
                if (k != i && k != j)
                    sum += tall[k];
            }
            if (sum == key)
            {
                for (int k = 0; k < 9; k++)
                {
                    if (k != i && k != j)
                        ans.push_back(tall[k]);
                }
                break;
            }
            else
            {
                sum = 0;
            }
        }
        if (sum == key)
        {
            break;
        }
    }

    sort(ans.begin(),ans.end());

    for(auto i : ans)
        cout<<i<<endl;
}