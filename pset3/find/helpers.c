/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */

#include <cs50.h>
#include <stdio.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
 // value is the 'needle' - the value to search for
 // the array 'values' is all the different values to seach through, the 'haystack'
 // n represents the number of values in the 'haystack'

 // i can assume that these values have been sorted from least to greatest.
 // so, values[0] is the smallest integer
 // values[n - 1] is the largest

 //search must return true if value is in values
 //search must return false if value in not in values

 /**
  * ABOUT BINARY SEARCH:
  *     Binary search assumes a list is in order.
  *     The goal of the search is to locate a target value.
  *     Binary search works by defining a 'search space' - the 'search space' is an interval defined by two values.  The low value, and the high value.
  *     On the first iteration, that 'search space' is the entire list.
  *     That means the low value is the first item in the list, and the high value is the last item in the list.
  *     The binary search will compare the target value to the median value.
  *     If those two values are the same, the search is complete.
  *     If not, the search can eliminate half of the search area.
  *     If the median value is less than the target value, the new 'search area' will be from the begining of the list to the value directly before the median.
  *     If the median value is larger than the target value, the new 'search area' will be from the value directly after the median until the end of the list.
  *
  **/

//algorithim is big-O(log n)
bool search(int value, int values[], int n)
{
    //if n is a non-positive number, return false
    if (n < 0){
        return false;
    }
    int high;
    int low;
    int median;
    bool finished;
    finished = false;
    high = n - 1;
    low = 0;
    median = (low + high) /2;

    while(finished == false){
        if (values[median] == value){
            printf("MATCH!");
            return true;
        }
        if (low > high || high < low){
            return false;
        }
        if (value < values[median]){
            high = median - 1;
            median = (low + high) /2;
        }
        if (value > values[median]){
            low = median + 1;
            median = (low + high) /2;
        }
    }


    return false;
}

/**
 * Sorts array of n values.
 */
 //algorithim is bigO(n^2)
 //int values contains the values within the haystack.  int n is the length of the haystack.
void sort(int values[], int n)
{
    // int outerSize;
    // int innerSize;
    // int searchProgress = 1;
    // int placeholder;
    // //Iterate basen on values length
    // for (outerSize = 0; outerSize < n; outerSize++){
    //     //Each iteration go one further
    //     for (innerSize = searchProgress; innerSize > 0; innerSize--){
    //             //Check to see if the comparison has reached the end of the string
    //             if (values[innerSize - 2]){
    //                 if (values[innerSize - 1] < values[innerSize - 2]){
    //                     placeholder = values[innerSize - 2];
    //                     values[innerSize - 2] = values[innerSize - 1];
    //                     values[innerSize - 1] = placeholder;
    //                 }
    //             }
    //     }
    //     searchProgress++;
    // }
    int place;
    int counter = 0;
    for (int i = 1; i < n; i++){
        for (int j = i; j >= 0; j--){

            if (values[j] < values[j - 1]){
                place = values[j];
                values[j] = values[j - 1];
                values[j - 1] = place;
            }
        }
    }
    return;
}
