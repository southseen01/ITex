#include <iostream>
#include <vector>
#include <algorithm>
#include <Windows.h>
using namespace std;

// Функція для знаходження добутку Р від'ємних елементів масиву з парними індексами, не більших за L
int calculateProductAndDividePositive(vector<int>& arr, int L) {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int product = 1;

    for (int i = 0; i < arr.size(); i += 2) {
        if (arr[i] < 0 && arr[i] <= L) {
            product *= arr[i];
        }
    }

    // Поділити всі додатні елементи на добуток Р
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] > 0) {
            arr[i] /= product;
        }
    }

    return product;
}

// Функція для знаходження мінімального та максимального елементів масиву
void findMinMax(const std::vector<int>& arr, int& minElement, int& maxElement) {
    minElement = *min_element(arr.begin(), arr.end());
    maxElement = *max_element(arr.begin(), arr.end());
}

// Функція для сортування елементів між мінімальним та максимальним за зростанням
void sortBetweenMinMax(vector<int>& arr, int minElement, int maxElement) {
    auto minPos = find(arr.begin(), arr.end(), minElement);
    auto maxPos = find(arr.begin(), arr.end(), maxElement);

    if (minPos != arr.end() && maxPos != arr.end()) {
        if (minPos > maxPos) {
            swap(minPos, maxPos);
        }
        sort(minPos + 1, maxPos);
    }
}

int main() {
    vector<int> array = { 4, 8, 2, -5, 10, 6, -3, 7 };
    int L = 5;

    int product = calculateProductAndDividePositive(array, L);
    cout << "Добуток від'ємних елементів з парними індексами, що не більші за " << L << ": " << product << endl;

    int minElement, maxElement;
    findMinMax(array, minElement, maxElement);
    cout << "Мінімальний елемент: " << minElement << endl;
    cout << "Максимальний елемент: " << maxElement << endl;

    sortBetweenMinMax(array, minElement, maxElement);

    cout << "Елементи масиву між мінімальним та максимальним елементами за зростанням: ";
    for (int num : array) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
