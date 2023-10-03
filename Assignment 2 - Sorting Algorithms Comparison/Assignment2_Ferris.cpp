#include <iostream>
#include <fstream>
using namespace std;

int countComp = 0;
int countMove = 0;

void BubbleSort(string* array, int size) {
    //Reseting counters not needed since Bubble Sort is called first

    //Copying elements of array to a copy so original can be used for next sorts
    string passedArray[10000];

    for (int i = 0; i < 10000; i++) {
        passedArray[i] = array[i];
    }

    for (int i = 0; i < size; i++) {
        int swaps = 0;                       //Flag to detect any swap is there or not
        for (int j = 0; j < size - i - 1; j++) {
            if (passedArray[j] > passedArray[j + 1]) {       //When the current item is bigger than next
                string temp = passedArray[j];
                passedArray[j] = passedArray[j + 1];
                passedArray[j + 1] = temp;
                countMove += 3;
                swaps = 1;                     //Set swap flag
            }
            countComp++;
        }
        if (!swaps)
            break;                            // No swap in this pass, so array is sorted
    }
}

void SelectionSort(string* items, int size) {
    //Reset counters
    countComp = 0;
    countMove = 0;

    //Copying elements of array to a copy so original can be used for next sorts
    string passedArray[10000];

    for (int i = 0; i < 10000; i++) {
        passedArray[i] = items[i];
    }

    for (int i = 0; i < size - 1; i++) {
        //Find index of smallest remaining element
        int indexSmallest = i;
        for (int j = i + 1; j < size; j++) {
            if (passedArray[j] < passedArray[indexSmallest]) {
                indexSmallest = j;
                
            }
            countComp++;
        }

        //Swap numbers[i] and numbers[indexSmallest]
        string temp = passedArray[i];
        passedArray[i] = passedArray[indexSmallest];
        passedArray[indexSmallest] = temp;
        countMove += 3;
    }
}

void InsertionSort(string* items, int size) {
    //Reset counters
    countComp = 0;
    countMove = 0;
    string passedArray[10000];

    for (int i = 0; i < 10000; i++) {
        passedArray[i] = items[i];
    }

    for (int i = 1; i < size; i++) {
        int j = i;
        while (j > 0 && passedArray[j] < passedArray[j - 1]) {
            //Swap numbers[j] and numbers [j - 1]
            string temp = passedArray[j];
            passedArray[j] = passedArray[j - 1];
            passedArray[j - 1] = temp;
            j--;
            countMove += 3;
            countComp++;
        }
    }
}

int Partition(string* items, int startIndex, int endIndex) {

    int midpoint = startIndex + (endIndex - startIndex) / 2;

    //Median of Three sorting (sorting startIndex, midpoint, and endIndex for faster sorting)
    if (items[startIndex] > items[midpoint]) {
        
        string temp = items[startIndex];
        items[startIndex] = items[midpoint];
        items[midpoint] = temp;
        countMove += 3;
    }
    countComp++;
    if (items[midpoint] > items[endIndex]) {
        
        string temp = items[midpoint];
        items[midpoint] = items[endIndex];
        items[endIndex] = temp;
        countMove += 3;

    }
    countComp++;
    if (items[startIndex] > items[midpoint]) {
        
        string temp = items[startIndex];
        items[startIndex] = items[midpoint];
        items[midpoint] = temp;
        countMove += 3;

    }
    countComp++;
    string pivot = items[midpoint];

    int low = startIndex;
    int high = endIndex;

    bool done = false;
    while (!done) {

        //Increments low until the item at low isn't < than pivot
        while (items[low] < pivot) {
            low++;
            countComp++;
        }
        
        //Decrements high until the item at high isn't > than pivot
        while (pivot < items[high]) {
            high--;
            countComp++;
        }
        
        //Partitioning ends when low is great than high
        if (low >= high) {
            done = true;
        }
        else {
            //Swap items at low and high then increment low and decrement high
            string temp = items[low];
            items[low] = items[high];
            items[high] = temp;
            countMove += 3;

            low++;
            high--;
        }
    }

    return high;
}

void QuickSort(string* items, int startIndex, int endIndex) {

    if (endIndex <= startIndex) {
        return;
    }

    int pivotIndex = Partition(items, startIndex, endIndex);

    //Sort low and high partitions
    QuickSort(items, startIndex, pivotIndex);
    QuickSort(items, pivotIndex + 1, endIndex);

}

void Merge(string* items, int leftFirst, int leftLast, int rightLast) {
    int mergedSize = rightLast - leftFirst + 1;       // Size of merged partition
    string* mergedNumbers = new string[mergedSize]; // Dynamically allocates temporary
    // array for merged numbers
    int mergePos = 0;                         // Position to insert merged number
    int leftPos = leftFirst;                  // Initialize left partition position
    int rightPos = leftLast + 1;              // Initialize right partition position

    // Add smallest element from left or right partition to merged numbers
    while (leftPos <= leftLast && rightPos <= rightLast) {
        if (items[leftPos] <= items[rightPos]) {
            mergedNumbers[mergePos] = items[leftPos];
            countMove++;
            leftPos++;
        }
        else {
            mergedNumbers[mergePos] = items[rightPos];
            countMove++;
            rightPos++;
        }
        countComp++;
        mergePos++;
    }

    // If left partition is not empty, add remaining elements to merged numbers
    while (leftPos <= leftLast) {
        mergedNumbers[mergePos] = items[leftPos];
        countMove++;
        leftPos++;
        mergePos++;
    }

    // If right partition is not empty, add remaining elements to merged numbers
    while (rightPos <= rightLast) {
        mergedNumbers[mergePos] = items[rightPos];
        countMove++;
        rightPos++;
        mergePos++;
    }

    // Copy merged numbers back to numbers
    for (mergePos = 0; mergePos < mergedSize; mergePos++) {
        items[leftFirst + mergePos] = mergedNumbers[mergePos];
        countMove++;
    }

    // Free temporary array
    delete[] mergedNumbers;
}

void MergeSort(string* numbers, int startIndex, int endIndex) {
    if (startIndex < endIndex) {
        // Find the midpoint in the partition
        int mid = (startIndex + endIndex) / 2;

        // Recursively sort left and right partitions
        MergeSort(numbers, startIndex, mid);
        MergeSort(numbers, mid + 1, endIndex);

        // Merge left and right partition in sorted order
        Merge(numbers, startIndex, mid, endIndex);
    }
}


int main() {

    string passwordArray[10000];
    fstream inFS;
    inFS.open("Passwords.txt");
    unsigned int i = 0;

    //Error check for opening input file
    if (!inFS.is_open()) {
        cout << "ERROR: File not found" << endl;
        return(1);
    }

    //Filling array with passwords
    while (!inFS.eof()) {
        inFS >> passwordArray[i];
        i++;
    }

    //Output of # of comparisons and movements of each sort
    BubbleSort(passwordArray, 10000);
    cout << "Bubble Sort:" << endl;
    cout << "Number of Comparisons: " << countComp << endl;
    cout << "Number of Movements: " << countMove << endl;


    SelectionSort(passwordArray, 10000);
    cout << "\nSelection Sort:" << endl;
    cout << "Number of Comparisons: " << countComp << endl;
    cout << "Number of Movements: " << countMove << endl;


    InsertionSort(passwordArray, 10000);
    cout << "\nInsertion Sort:" << endl;
    cout << "Number of Comparisons: " << countComp << endl;
    cout << "Number of Movements: " << countMove << endl;


    //Reseting counters outside since Merge Sort is recursive
    countComp = 0;
    countMove = 0;

    //Previous sorts copied the array in the function but since Merge Sort is recursive the real one is used because
    //only Quick Sort is after this so the array can be filled one more time from the .txt file for Quick Sort.
    MergeSort(passwordArray, 0, 9999);
    cout << "\nMerge Sort:" << endl;
    cout << "Number of Comparisons: " << countComp << endl;
    cout << "Number of Movements: " << countMove << endl;


    //Reseting counters outside since Quick Sort is recursive
    countComp = 0;
    countMove = 0;

    //Reset array to unsorted state for Quick Sort since Merge sort used the real array and not a copy
    i = 0;
    inFS.close();
    inFS.open("Passwords.txt");
    while (!inFS.eof()) {
        inFS >> passwordArray[i];
        i++;
    }

    QuickSort(passwordArray, 0, 9999);
    cout << "\nQuick Sort:" << endl;
    cout << "Number of Comparisons: " << countComp << endl;
    cout << "Number of Movements: " << countMove << endl;
    
    inFS.close();
    return 0;

}