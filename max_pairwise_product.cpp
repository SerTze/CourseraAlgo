#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long MaxPairwiseProduct(const vector<int>& numbers) {
    long long max_product = 0;
    int n = numbers.size();

    for (int first = 0; first < n; ++first) {
        for (int second = first + 1; second < n; ++second) {
            max_product = max(max_product,
                (long long)numbers[first] * (long long)numbers[second]);
        }
    }

    return max_product;
}

long long MaxPairwiseProductFast(const vector<int>& numbers) {
    long long max_product = 0;
    int n = numbers.size();
    long long max1 = -1, max2 = -1;
    int duplicate = 1;
    for (int i = 0; i < n; i++) {
        if( (long long)numbers[i] > max1 ){
            max1 = numbers[i];
            duplicate = i;
        }
    }
    for (int i = 0; i < n; i++) {
        if( (long long)numbers[i] > max2 && i != duplicate){
            max2 = numbers[i];
        }
    }
    max_product = max1 * max2;
    return max_product;
}

int main() {

    // while(true){
    //     int n = rand() % 100 + 2;
    //     cout << n << "\n";
    //     vector<int> a;
    //     for(int i = 0; i < n; i++){
    //         a.push_back( rand() % 100000);
    //     }  
    //     for(int i = 0; i < n; i++){
    //         cout << a[i] << " ";
    //     }
    //     cout << "\n";
    //     long long res1 = MaxPairwiseProduct(a);
    //     long long res2 = MaxPairwiseProductFast(a);
    //     if(res1 != res2){
    //         cout << "Wrong answer: " << res1 << " " << res2 << "\n";
    //         break;
    //     }
    //     else{
    //         cout << "ok\n";
    //     }
        


    // }
    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    cout << MaxPairwiseProductFast(numbers) << "\n";
    return 0;
}
