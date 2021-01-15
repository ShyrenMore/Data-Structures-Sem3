#include <stdio.h>
#include <stdlib.h>

// 5 4 3 2 1 
// valur = 1
// int search(int data[], int arrSize, int value)
// {
//     int idx;
//     for (idx = 0; idx < arrSize; idx++)
//     {
//         if(data[idx] == value)
//             return idx;
//     }
//     return -1;
// }

int main()
{
    int arr[10], num, i,j, beg, end, mid, noOfEl, found = 0;
    printf("\nEnter number of array elements :: ");
    scanf("%d", &noOfEl);
    printf("\nEnter elements :: ");
    for (i = 0; i < noOfEl; i++)
        scanf("%d", &arr[i]);

    
    // linear search
    // int temp = search(arr, noOfEl, num);
    // if(temp == -1)
    //     printf("Element not found ");
    // else
    //     printf("%d element found at position %d", num, (temp+1));

    // sorting block starts
    int temp;
    for ( i = 0; i < noOfEl; i++)
    {
        for ( j = 0; j < noOfEl - i -1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    // sorting block ends

    printf("Enter the number to be searched :: ");
    scanf("%d", &num);

    printf("\nSorted array is : \n");
    for ( i = 0; i < noOfEl; i++)
    {
        printf("%d ", arr[i]);
    }
    

    beg = 0;
    end = noOfEl - 1;
    while(beg <= end)   
    {
        mid = (beg + end) / 2;  
        if(arr[mid] == num)
        {
            printf("\n%d is present in array at position %d", num, mid + 1);
            found = 1;
            break;
        }
        else if(arr[mid]>num)
            end = mid - 1; 
        else
            beg = mid + 1;
    
        
    }
    if (beg > end && found == 0)
    {
        printf("\n%d does not exist in array", num);
    }
    return 0;
}
