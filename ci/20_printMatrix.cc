#include <iostream>
using namespace std;

/********************************************************************************** 
 * 
 * Given a matrix of m x n elements (m rows, n columns), print all elements of the 
 * matrix in spiral order.(clockwisely)
 * 
 * For example,
 * Given the following matrix:
 * 
 * [
 *  [ 1, 2, 3 ],
 *  [ 4, 5, 6 ],
 *  [ 7, 8, 9 ]
 * ]
 * 
 * You should print [1,2,3,6,9,8,7,4,5].
 *               
 **********************************************************************************/

void printMatrixClockwisely(int** matrix, int columns, int rows) {
    if (matrix == NULL || columns <= 0 || rows <= 0)
        return;
    int beginX = 0, endX = columns-1;
    int beginY = 0, endY = rows-1;

    while (true) {
        // left -> right: [1, 2, 3], [5]
        for (int j = beginX; j <= endX; ++j)     cout << matrix[beginY][j] << "\t";
        if (++beginY > endY)    break;
        // top -> bottom:  [6, 9]
        for (int i = beginY; i <= endY; ++i)     cout << matrix[i][endX] << "\t";
        if (beginX > --endX)    break;
        // right -> left: [8, 7]
        for (int j = endX; j >= beginX; --j)     cout << matrix[endY][j] << "\t";
        if (beginY > --endY)    break;
        // bottom -> top: [4]
        for (int i = endY; i >= beginY; --i)     cout << matrix[i][beginX] << "\t";
        if (++beginX > endX)    break;
    }
}


// =====================Test Code=====================
void Test(int columns, int rows)
{
    printf("Test Begin: %d columns, %d rows.\n", columns, rows);

    if(columns < 1 || rows < 1)
        return;

    int** numbers = new int*[rows];
    for(int i = 0; i < rows; ++i)
    {
        numbers[i] = new int[columns];
        for(int j = 0; j < columns; ++j)
        {
            numbers[i][j] = i * columns + j + 1;
        }
    }

    printMatrixClockwisely(numbers, columns, rows);
    printf("\n");

    for(int i = 0; i < rows; ++i)
        delete[] (int*)numbers[i];

    delete[] numbers;
}

int main()
{
    /*
    1    
    */
    Test(1, 1);

    /*
    1    2
    3    4
    */
    Test(2, 2);

    /*
    1    2    3    4
    5    6    7    8
    9    10   11   12
    13   14   15   16
    */
    Test(4, 4);

    /*
    1    2    3    4    5
    6    7    8    9    10
    11   12   13   14   15
    16   17   18   19   20
    21   22   23   24   25
    */
    Test(5, 5);

    /*
    1
    2
    3
    4
    5
    */
    Test(1, 5);

    /*
    1    2
    3    4
    5    6
    7    8
    9    10
    */
    Test(2, 5);

    /*
    1    2    3
    4    5    6
    7    8    9
    10   11   12
    13   14   15
    */
    Test(3, 5);

    /*
    1    2    3    4
    5    6    7    8
    9    10   11   12
    13   14   15   16
    17   18   19   20
    */
    Test(4, 5);

    /*
    1    2    3    4    5
    */
    Test(5, 1);

    /*
    1    2    3    4    5
    6    7    8    9    10
    */
    Test(5, 2);

    /*
    1    2    3    4    5
    6    7    8    9    10
    11   12   13   14    15
    */
    Test(5, 3);

    /*
    1    2    3    4    5
    6    7    8    9    10
    11   12   13   14   15
    16   17   18   19   20
    */
    Test(5, 4);

    return 0;
}
