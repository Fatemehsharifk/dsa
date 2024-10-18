 #include <iostream>

#include <vector>

void printTruthTable(int numVariables, int currentIndex, std::vector<int>& values) {
    if (currentIndex == numVariables) {
        // اگر به انتهای متغیرها رسیدیم، مقادیر را چاپ می‌کنیم
        for (int i = 0; i < numVariables; ++i) {
            std::cout << values[i] << "\t";
        }
        std::cout << "\n";
        return;
    }

    // مقدار 0 برای متغیر فعلی
    values[currentIndex] = 0;
    printTruthTable(numVariables, currentIndex + 1, values);

    // مقدار 1 برای متغیر فعلی
    values[currentIndex] = 1;
    printTruthTable(numVariables, currentIndex + 1, values);
}

int main() {
    int numVariables;

    std::cout << "Enter the number of variables: ";
    std::cin >> numVariables;

    // ایجاد یک آرایه برای نگهداری مقادیر متغیرها
    std::vector<int> values(numVariables);

    // چاپ سرستون‌ها
    for (int i = 0; i < numVariables; ++i) {
        std::cout << "Var" << (i + 1) << "\t";
    }
    std::cout << "\n";

    // تولید و چاپ جدول ارزش درستی
    printTruthTable(numVariables, 0, values);

    return 0;
}