short *shortarray(short int *array, short a, short int b, short signed int c, short d, short e);

int main()
{
    short signed int array[5] = {4, 23, 5, 6, 2};
    short *arr = shortarray(array, 39, 59, 145, 23, 329);
    return !( 329 == arr[3] );
}
