

//   (Q)why we used arr[mid]>=arr[0]{start=mid+1}    why not arr[mid]<arr[mid+1]{start=mid+1}


// ans:

// The line if(arr[mid] >= arr[0]) is used to determine whether the pivot element is in the right half of the array or the left half. 
//The pivot element is the smallest element in the rotated sorted array, which means that it is the element for which the element to its right is greater than
// it.

// In a rotated sorted array, the first element arr[0] should be greater than or equal to the pivot element. Therefore, if arr[mid]
 //is greater than or equal to arr[0], it means that the pivot element lies in the right half of the array. Otherwise, the pivot element 
 //lies in the left half of the array.

// The if statement updates the start index s and end index e based on whether the pivot element is in the left or right half of the array. 
//If arr[mid] is greater than or equal to arr[0], the pivot element lies in the right half of the array, so we update s to mid + 1 (i.e., we move 
//the start index to the right of mid). Otherwise, the pivot element lies in the left half of the array, so we update e to mid (i.e., we move the
 //end index to the left of mid).
///////////////////////////////////////////

using namespace std;


//more explanation for 1st question

// Certainly! Let's take a closer look at why we need to update start to mid+1 instead of end to mid-1 in the case of finding the pivot point of a mountain array.

// In the binary search algorithm, we maintain a search range [start, end] for the target value that we're searching for. In each iteration of 
// the while loop, we calculate the midpoint mid of the search range and compare the value at mid with the target value. If the value at mid is 
// greater than the target value, we update end to mid-1 to exclude the right half of the search range from consideration. If the value at mid is 
// less than the target value, we update start to mid+1 to exclude the left half of the search range from consideration.

// In the case of finding the pivot point of a mountain array, we're not searching for a specific target value. Instead, we're looking for
//  a pattern in the array - the point where the elements start decreasing after increasing up to a peak. Therefore, we need to keep both mid
//   and mid+1 in the search range in order to determine whether the pivot point lies to the left or right of mid.

// Suppose we were to update end to mid-1 in the while loop instead of start to mid+1. This would exclude mid+1 from the search range, 
// which means we would no longer be considering it when determining the location of the pivot point. If mid is not the pivot point, this could cause
// us to miss the pivot point and return
// the wrong result.

// Therefore, in order to ensure that we consider both mid and mid+1 in the search range, we need to update start to mid+1 when the value
//  at mid is less than the value at mid+1. This way, both mid and mid+1 remain in the search range, and we can correctly determine whether 
//  the pivot point lies to the left or right of mid


int getPivot(int arr[], int n) {

    int s = 0;
    int e = n-1;
    int mid = s + (e-s)/2;

    while(s<e) {

        if(arr[mid] >= arr[0])
        {
            s = mid+1;
        }
        else{
            e = mid;
        }
        mid = s + (e-s)/2;
    }
    return s;
}

int main() {
    int arr[5] = {8,10,17,1,3};
    cout << "Pivot is " << getPivot(arr, 5) << endl;
}
