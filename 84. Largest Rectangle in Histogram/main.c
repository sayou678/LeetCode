// 84
// hello world!

#define NULL 0

int calcArea(int *heights, int size)
{
    int min = heights[0];
    int i = 0;
   
    for(i = 0; i < size; i++)
    {
        if(heights[i] < min)
            min = heights[i];
    }
    return min * size;
}

int calcAreaNo0(int *heights, int heightsSize)
{
    int i = 0, j = 0;
    int max = 0;
   
    if(heightsSize == 1)
    {
        return heights[0];
    }
   
    for(i = 0; i < heightsSize - 1; i++)
    {
        for(j = i + 1; j < heightsSize; j++)
        {
            int area = calcArea(heights + i, j - i + 1);
            if(area > max)
                max = area;
        }
    }
    return max;  
}

int largestRectangleArea(int* heights, int heightsSize) {
    int max = 0;
    int i = 0;
    int j = -1;
   
    if(heights == NULL || heightsSize == 0)
        return 0;
   
    if(heightsSize == 1)
    {
        return heights[0];
    }
   
    for(i = 0; i < heightsSize; i++)
    {
        if(heights[i] == 0 || i == heightsSize - 1)
        {
            if(j < 0)
                continue;
           
            printf("%d, %d\n", i, j);
            int area = calcAreaNo0(heights + j, i - j + 1);
            if(area > max)
                max = area;
           
            j = -1;
        }
        else
        {
            if(j < 0)
                j = i;
        }
    }
   
    return max;
}

int main()
{
	int test[] = {2,1,5,6,2,3};
	int max = largestRectangleArea(test, sizeof(test) / sizeof(int));
	
	printf("%d\n", max);
	return 0;
}
