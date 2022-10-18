#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int class_size(int , int , int);
int maximum(int *, int);
int minimum(int *, int);
void frequency(int *, int *, int, int , int);
void print(int * , int , int , int );
int sum_freq(int *freq_d );
int main()
{
    int size = 0, row = 1, class_sze , freq[10] ={0} , min , max;
    float round_val;
    printf("Enter number of data : ");
    scanf("%d", &size);
    int data_array[size];
    for (int i = 0; i < size; i++)
    {
        printf("Enter value %d --> " ,i+1);
        scanf("%d", &data_array[i]);
    }
    printf("Enter number of data in a row : ");
    fflush(stdin);
    scanf("%d", &row);
    max = maximum(data_array, size);
    printf("Max --> %d\n", max);
    min = minimum(data_array , size);
    printf("Min --> %d\n", min);
    class_sze = class_size(max, min, row);
    printf("Class Size --> %d\n" , class_sze);
    frequency(data_array , freq , class_sze , min , size);
    print(freq , min , class_sze , sum_freq(freq));
    return 0;
}
int maximum(int *ar, int size)
{
    int max = ar[0];
    for (int i = 0; i < size; i++)
    {
        if (max < ar[i])
        {
            max = ar[i];
        }
    }
    return max;
}
int minimum(int *ar, int size)
{
    int min = ar[0];
    for (int i = 0; i < size; i++)
    {
        if (min > ar[i])
        {
            min = ar[i];
        }
    }
    return min;
}
int class_size(int max, int min, int row)
{
    int class_s;
    double round_val;
    round_val = ((double)max - (double)min) / (double)row;
    class_s = (int)roundf(round_val);
    return class_s;
}
void frequency(int * data , int * freq , int class_size , int min , int size){
    for(int i=0 ; i< size ; i++){
        if(data[i]>= min && data[i] <(min + class_size)){
            freq[0]++;
        }
        if(data[i]>=(min + class_size)   && data[i] <  (min +  2*class_size)){
            freq[1]++;
        }
        if(data[i]>=(min + 2*class_size) && data[i] <  (min +  3*class_size)){
            freq[2]++;
        }
        if(data[i]>=(min + 3*class_size) && data[i] <  (min +  4*class_size)){
            freq[3]++;
        }
        if(data[i]>=(min + 4*class_size) && data[i] <  (min +  5*class_size)){
            freq[4]++;
        }
        if(data[i]>=(min + 5*class_size) && data[i] <  (min +  6*class_size)){
            freq[5]++; 
        }
        if(data[i]>=(min + 7*class_size) && data[i] <  (min +  8*class_size)){
            freq[6]++;
        }
        if(data[i]>=(min + 8*class_size) && data[i] <  (min +  9*class_size)){
            freq[7]++;
        }
        if(data[i]>=(min + 9*class_size) && data[i] <  (min + 10*class_size)){
            freq[8]++;
        }
        if(data[i]>=(min+ 10*class_size) && data[i] <  (min + 11*class_size)){
            freq[9]++;
        }
    }
}
int sum_freq(int *freq_d ){
    int sum = 0 ;
    for(int i=0 ; i<10 ; i++){
        sum = sum + freq_d[i] ;
    }
    return sum ;
}
void print(int * freq , int min , int class_size , int freq_sum){
    printf("Class-Interval | Freq | CF(<) | CF(>)\n");
    int less = freq[0] , greater = freq_sum;
    for(int i= 0  ;i<10 ; i++){ 
        if(greater == 0){
            break;
        }
        printf("%d - %d -->       %d      %d      %d      \n" , min  , min+class_size , freq[i] , less , greater);
        min = min + class_size ;
        less = less + freq[i+1];
        greater = greater - freq[i];
        
    }
}
