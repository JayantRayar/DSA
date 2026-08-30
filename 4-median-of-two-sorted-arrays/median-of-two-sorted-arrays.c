#include <limits.h>

double findMedianSortedArrays(int* a, int aSize, int* b, int bSize)
{
    if (aSize > bSize)
        return findMedianSortedArrays(b, bSize, a, aSize);

    int low = 0, high = aSize;
    int total = aSize + bSize;

    while (low <= high)
    {
        int cutA = (low + high) / 2;
        int cutB = (total + 1) / 2 - cutA;

        int leftA  = (cutA == 0) ? INT_MIN : a[cutA - 1];
        int rightA = (cutA == aSize) ? INT_MAX : a[cutA];

        int leftB  = (cutB == 0) ? INT_MIN : b[cutB - 1];
        int rightB = (cutB == bSize) ? INT_MAX : b[cutB];

        if (leftA <= rightB && leftB <= rightA)
        {
            if (total % 2)
            {
                return (leftA > leftB) ? leftA : leftB;
            }

            int mxLeft = (leftA > leftB) ? leftA : leftB;
            int mnRight = (rightA < rightB) ? rightA : rightB;

            return (mxLeft + mnRight) / 2.0;
        }

        if (leftA > rightB)
            high = cutA - 1;
        else
            low = cutA + 1;
    }

    return 0.0;
}