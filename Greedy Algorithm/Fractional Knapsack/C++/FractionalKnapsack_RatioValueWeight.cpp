#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Item
{
    int value, weight;
    double ratio;
};

bool compare(Item i1, Item i2)
{
    return i1.ratio > i2.ratio;
}

double FractionalKnapsack(int W, vector<Item> Items)
{
    sort(Items.begin(), Items.end(), compare);

    double result = 0.0;
    int curWeight = 0;

    for (int i = 0; i < Items.size(); i++)
    {
        if (curWeight + Items[i].weight <= W)
        {
            curWeight += Items[i].weight;
            result += Items[i].value;
        }
        else
        {
            int remWeight = W - curWeight;
            result += Items[i].ratio * remWeight;
            break;
        }
    }

    return result;
}

int main()
{
    int W = 15;
    vector<Item> Items = {{5, 1}, {10, 3}, {15, 5}, {7, 4}, {8, 1}, {9, 3}, {4, 2}};

    for (int i = 0; i < Items.size(); i++)
        Items[i].ratio = Items[i].value / Items[i].weight;

    double maxVal = FractionalKnapsack(W, Items);

    cout << "Maximum Value we can obtain: " << maxVal << endl;

    return 0;
}
