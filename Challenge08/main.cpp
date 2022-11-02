#include <iostream>

using namespace std;

int *apply_all(const int *const arr, const size_t size, const int *const arr_two, const size_t size_two);
void print(const int *const arr, const size_t size);

int *apply_all(const int *const arr, const size_t size, const int *const arr_two, const size_t size_two) {
    int *mul_ptr{nullptr};
    int count{};

    mul_ptr = new int[size * size_two];

    for(size_t j{}; j < size_two; j++)
        for(size_t i{}; i < size; i++){
            mul_ptr[count] = arr[i] * arr_two[j];
            count++;
        }
    return mul_ptr;
}

void print(const int *const arr, const size_t size) {
    cout << "[ ";
    for(size_t i{}; i < size; i++) 
        cout << arr[i] << " ";
    cout << "]" << endl;
}

int main() {
    const size_t arr_one_size {5};
    const size_t arr_two_size {3};

    int arr_one[] {1,2,3,4,5};
    int arr_two[] {10,20,30};

    cout << "First Array 1: ";
    print(arr_one, arr_one_size);

    cout << "Second Array 2: ";
    print(arr_two, arr_two_size);

    int *results = apply_all(arr_one, arr_one_size, arr_two, arr_two_size);
    constexpr size_t results_size {arr_one_size * arr_two_size};

    cout << "Result: ";
    print(results, results_size);

    delete [] results;

    cout << endl;
    return 0;
}
