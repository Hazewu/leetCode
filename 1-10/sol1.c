#include<stdio.h>
#include<stdlib.h>

int * twoSum(int* nums, int numsSize, int target){
	int i, j;
	int *result = NULL;			// int数组指针
	for(i = 0; i < numsSize-1; i++){
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

// 如何在Mac终端执行c
// 1、进入到所在文件夹目录
// 2、gcc -Wall -g -o test test.c
//    -Wall，代表编译器在编译过程中会输出警告信息
//	  -g，代表编译器会收集调试（debug）信息，如果程序出错，方便找到错误原因
//	  -o，代表编译器会将编译完成后的可执行文件以你指定的名称输出到指定的文件夹下，test，
//        如果不指定，可执行文件会被放到根目录下，名字叫做a.out
//    test.c，代表要变异的源代码的名称
// 3、./test，执行程序