/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Eagleye
 *
 * Created on September 13, 2018, 2:15 AM
 */

#include <iostream>
#include <list>

const int N = 3;

void printArray(int*** arr) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k)
                std::cout << "i: " << i << " j: " << j << " k: " << k << "\t" << arr[i][j][k] << '\n';
        }
    }
}

///////////////////////// CREATE DYNAMIC ARRAY //////////////////////////////

int*** getArray() {
    int*** arr = new int**[N];
    for (int i = 0; i < N; ++i) {
        arr[i] = new int*[N];
        for (int j = 0; j < N; ++j) {
            arr[i][j] = new int[N];
            for (int k = 0; k < N; ++k) {
                arr[i][j][k] = i + j + k;
            }
        }
    }

    return arr;
}
////////////////////////////////////////////////////////////////////////////////

void printArr(int arr[][N][N]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k)
                std::cout << "i: " << i << " j: " << j << " k: " << k << "\t" << arr[i][j][k] << '\n';
        }
    }
}

////////////////// STATIC ARRAY ///////////////////////////////////////////////
typedef int (*getArr)[N][N];
// int (*(getArr)())[N][N] == (*getArry)[N][N]

getArr getArrr() {
    static int arr[N][N][N] = {
        {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        },
        {
            {10, 11, 12},
            {13, 14, 15},
            {16, 17, 18}
        },
        {
            {19, 20, 21},
            {22, 23, 24},
            {25, 26, 27}
        }
    };

    return arr;
}

int main(int argc, char** argv) {

    // int*** arr = getArray();

    // printArray(arr);

    int (*array)[N][N] = getArrr();

    printArr(array);


    //  int (*(*(array)())[N])[N];

    return 0;
}

