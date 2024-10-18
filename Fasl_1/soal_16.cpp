 #include <iostream>

using namespace std;
void generateSubsets(int set[], int n, int index, int current[], int currentSize) {
    // اگر به انتهای مجموعه رسیدیم، زیرمجموعه فعلی را چاپ می‌کنیم
    if (index == n) {
        cout << "{ ";
        for (int i = 0; i < currentSize; i++) {
            cout << current[i] << " ";
        }
        cout << "}" << endl;
        return;
    }

    // شامل کردن عنصر فعلی
    current[currentSize] = set[index];
    generateSubsets(set, n, index + 1, current, currentSize + 1);

    // شامل نکردن عنصر فعلی
    generateSubsets(set, n, index + 1, current, currentSize);
}

int main() {

    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int* set = new int[n]; // ایجاد آرایه دینامیک

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        cin >> set[i];
    }

    int current[n]; // آرایه برای نگهداری زیرمجموعه فعلی

    generateSubsets(set, n, 0, current, 0);
    delete[] set; // آزادسازی حافظه
    return 0;
}