/*
Adapted from Nikos M.'s answer on https://stackoverflow.com/questions/12991758/creating-all-possible-k-combinations-of-n-items-in-c
Oct. 07, 2020
*/


#include <algorithm>
#include <iostream>
#include <string>
#include <chrono>
#include <vector>


inline std::vector<int> combination(int N, int K)
{
    std::vector<int> result;
    int idx = 0;

    std::string bitmask(K, 1); // K leading 1's
    bitmask.resize(N, 0); // N-K trailing 0's

    // print integers and permute bitmask
    do {
        for (int i = 0; i < N; ++i) // [0..N-1] integers
        {
            if (bitmask[i])
            {
                std::cout << " " << i;
                result.push_back(i);
            }
        }
        std::cout << std::endl;

        idx++;
    } while (std::prev_permutation(bitmask.begin(), bitmask.end()));

    return result;
}


int main()
{
    auto t0 = std::chrono::high_resolution_clock::now();

    std::vector<int> result = combination(10, 2);

    auto t1 = std::chrono::high_resolution_clock::now();
    auto time_used = std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0).count();

    std::cout << time_used << "microseconds" << std::endl;
    for (unsigned long i = 0; i < result.size(); i++)
    {
        std::cout << result[i] << std::endl;
    }

}