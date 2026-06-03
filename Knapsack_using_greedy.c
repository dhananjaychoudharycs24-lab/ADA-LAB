#include <stdio.h>

struct Item {
    int profit;
    int weight;
    float ratio;
};

void sortItems(struct Item items[], int n) {
    int i, j;
    struct Item temp;

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (items[i].ratio < items[j].ratio) {
                temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }
}

int main() {
    int n, capacity;
    float totalProfit = 0.0;

    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item items[n];

    printf("Enter profit and weight of each item:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &items[i].profit, &items[i].weight);
        items[i].ratio = (float)items[i].profit / items[i].weight;
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    sortItems(items, n);

    printf("\nSelected items:\n");

    for (int i = 0; i < n && capacity > 0; i++) {
        if (items[i].weight <= capacity) {
          
            capacity -= items[i].weight;
            totalProfit += items[i].profit;

            printf("Item %d: 100%% taken\n", i + 1);
        } else {
            
            float fraction = (float)capacity / items[i].weight;
            totalProfit += items[i].profit * fraction;

            printf("Item %d: %.2f%% taken\n", i + 1, fraction * 100);

            capacity = 0;
        }
    }

    printf("\nMaximum Profit = %.2f\n", totalProfit);

    return 0;
}
