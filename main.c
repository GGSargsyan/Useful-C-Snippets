#include <stdio.h>
#include <stdlib.h>

void print_array(int *array, int count)
{
    while (count--)
        printf(" %i ", *(array++));
    printf("\n");
}

int comparer(const void *left, const void *right)
{
    return (*(int *)left) - (*(int *)right);
}

void search(int x, int *array, int length, int size)
{
    void *index = bsearch(&x, array, length, size, &comparer);
    
    if ( index == NULL )
        printf("The value %i was NOT found!\n", x);
    else 
    {
        index = (void *)( (index - (void *)array )/size);
        printf("The value %i was found at position %i\n", x, index);
    }
}

void printReverse(char str[], int length) 
{ 
    
    // Traverse string from end 
    int i; 
    for (i = length - 1; i >= 0; i--) 
    { 
        if (str[i] == ' ') 
        {          
            str[i] = '\0'; 
            // Start from next charatcer      
            printf("%s ", &(str[i]) + 1); 
        }
    } 
    // printing the last word 
    printf("%s\n", str); 
} 

void run_sort_and_search()
{
    int nums[10] = {9,5,7,1,8,5,10,12,4,2};
    int d_size = sizeof(int);
    int array_size = sizeof(nums)/d_size;
    
    print_array(nums, array_size);
    
    qsort(nums, array_size, d_size, &comparer);
    
    print_array( nums, array_size);
    
    search( 7, nums, array_size, d_size);
}

void run_string_reverse()
{
    char str[] = "I AM A GEEK"; 
    int strLength = sizeof(str)/sizeof(str[0]);
    printReverse(str, strLength); 
}

void run_in_out_file()
{
    char source[100];
    char out[100];
    
    printf("What is the name of the source file?\n");
    scanf("%s", source);
    
    printf("What is the name of the out file?\n");
    scanf("%s", out);
    
    FILE * sourcefile = fopen(source, "r");
    FILE * outfile = fopen(out, "w");
    
    char c = getc(sourcefile);
    
    while ( c != EOF )
    {
        putc(c, outfile);
        c = getc(sourcefile);
    }
}

void print_string_with_pointers()
{
    char *String = "My String Here!\n";
    
    char *s;
    s = String;
    int length = 0;
    while (*s)
    {
        putchar(*s++);
        length++;
    }
    
    printf("%d\n", length);
}

int main()
{
    run_sort_and_search();
    
    run_string_reverse();
    
    //run_in_out_file();
    
    print_string_with_pointers();
}
