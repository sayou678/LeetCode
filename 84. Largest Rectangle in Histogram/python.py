class Solution(object):
    def largestRectangleArea(self, heights):
        """
        :type heights: List[int]
        :rtype: int
        """
        index = []
        max = 0
        for i in range(0, len(heights)):
            while(index and heights[index[-1]] <= heights[i]):
                h = heights[index.pop()]
                x = i if not index else i - heights[index[-1]] - 1
                area = h * x
                if area > max: 
                    max = area
            index.append(i)
            print index
            
        return max

def stringToIntegerList(input):
    input = input.strip()
    input = input[1:-1]
    return [int(number) for number in input.split(",")]

import sys
def readlines():
    for line in sys.stdin:
        yield line.strip('\n')

def main():
    lines = readlines()
    while True:
        try:
            line = lines.next()
            heights = stringToIntegerList(line)
            
            ret = Solution().largestRectangleArea(heights)

            out = str(ret)
            print out
        except StopIteration:
            break

if __name__ == '__main__':
    main()
