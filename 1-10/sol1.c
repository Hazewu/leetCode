#include<stdio.h>
#include<stdlib.h>

int * twoSum(int* nums, int numsSize, int target){
	int i, j;
	int *result = NULL;			// int数组指针
	for(i = 0;, i < numsSize-1; i++){
		for(j = i + 1; j < numsSize; j++){
			if(nums[i] + nums[j] == target){
				result = (int*)malloc(sizeof(int)*2);			// sizeof(int)*2，表示申请两个int字节大的空间，一个int有4个字节，返回值为void型
																// int*，表示将申请到的空间返回值void，强制转换为int*类型
				result[0] = i;
				result[1] = j;
				return result;
			}
		}
	}
	return result;
}

int main(){
	int nums[6] = {1, 2, 3, 4, 5, 6};
	int numsSize = 6;
	int target = 9;
	int *result = twoSum(nums, numsSize, target);
	printf("[%d, %d]\n", result[0], result[1]);
    return 0;
}