// Merge Sort
// Method we following + pseudocode:
// 1. Divide the array into two halves until each sub-array contains a single element.
// 2. Merge the sub-arrays back together in sorted order.

#include <stdio.h>
int arr[] = {17, 6, 19, 26, 39, 48, 9, 29, 31, 37, 45, 50};
int n = sizeof(arr)/sizeof(arr[0]);

void merge(int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        merge_sort(left, mid);
        merge_sort(mid + 1, right);

        merge(left, mid, right);
    }
}

int main() {
    merge_sort(0, n - 1);

    for(int i=0; i<n; i++){ printf("%d ", arr[i]); }
    return 0;
}


/*
    Visual walk-through of the first partition on the original array

Starting array:
[17, 6, 19, 26, 39, 48, 9, 29, 31, 37, 45, 50] with indices 0..11. Pivot = arr[0] = 17.

We use the corrected Hoare partition behavior:
	•	Initial: low=0, high=11. So left = -1, right = 12.
	•	Step 1: increment left until arr[left] >= pivot:
	•	left -> 0: arr[0] = 17, 17 < 17? No. So left stops at 0.
	•	Step 2: decrement right until arr[right] <= pivot:
	•	right -> 11: arr[11] = 50, 50 > 17 so continue.
	•	right -> 10: 45 > 17 continue.
	•	right -> 9: 37 > 17 continue.
	•	right -> 8: 31 > 17 continue.
	•	right -> 7: 29 > 17 continue.
	•	right -> 6: 9 <= 17 stop. So right = 6.
	•	Since left (0) < right (6), swap arr[0] and arr[6].
	•	Swap 17 and 9. Array becomes:
[9, 6, 19, 26, 39, 48, 17, 29, 31, 37, 45, 50]
	•	Continue:
	•	Move left from current position 0:
	•	left -> 1: arr[1] = 6, 6 < 17 continue.
	•	left -> 2: arr[2] = 19, 19 < 17? No. Stop left at 2.
	•	Move right from current position 6:
	•	right -> 5: arr[5] = 48, 48 > 17 continue.
	•	right -> 4: arr[4] = 39, >17 continue.
	•	right -> 3: arr[3] = 26, >17 continue.
	•	right -> 2: arr[2] = 19, >17 continue.
	•	right -> 1: arr[1] = 6, 6 <= 17 stop. right = 1.
	•	Now left (2) >= right (1), so partition stops and returns right = 1.

After partition, array is
[9, 6, 19, 26, 39, 48, 17, 29, 31, 37, 45, 50]
Left partition indices 0..1 (values 9,6) and right partition indices 2..11.

Then quicksort recurses on left part (0..1) and right part (2..11). The left part will get sorted into [6,9]. The right part continues partitioning, eventually sorting the entire array.

That first partition example shows how swapping the pivot value into the correct side happens implicitly through swaps with other elements. You do not explicitly place the pivot at the end like Lomuto partition; Hoare’s method moves pairs of out-of-place items and the pivot may move during swaps.

⸻

Complexity and notes
	•	Average time: O(n log n). Worst-case: O(n^2) when the pivot is always the smallest or largest (for example, already sorted input).
	•	Hoare partition performs fewer swaps than Lomuto on average and often faster in practice.
	•	Hoare returns a split index p that should be used as low..p and p+1..high for recursive calls.

⸻

If you want, I can:
	•	Show the whole sort trace step-by-step for this particular array (every swap and recursive call).
	•	Convert this to the Lomuto partition style (where pivot ends at its final index explicitly).
	•	Provide a version that randomizes the pivot to avoid worst-case behavior.
*/