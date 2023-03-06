int binarySearch(int searchItem, int arrayToSearchIn[], int arraySize)
{
    int low,high,mid;
    low = 0;
    high = arraySize - 1;
    mid = (low+high)/2;
    while (low <= high && searchItem != arrayToSearchIn[mid])
    {
        mid = (low+high)/2;
        if (searchItem < arrayToSearchIn[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    if (searchItem == arrayToSearchIn[mid])
        return mid;
    return -1;
}