// 题目描述
// 给定一个整数数组 nums 和一个整数目标值 target， 请你在该数组中找出 和为目标值 的那 两个 整数，并返回它们的数组下标
// 可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。
// 可以按任意顺序返回答案

#include<vector>
#include<string>
#include<iostream>
#include<map>
using namespace std;



// // 方法一：两层遍历，暴力解法
// class Solution{
// public:
// 	vector<int> twoSum(vector<int>& nums, int target){
//         int i, j;
//         for(i = 0; i < nums.size() - 1; i++){
//         	for(j = i + 1; j < nums.size(); j++){
//         		if(nums[i] + nums[j] == target){
//         			return {i, j};						//中括号，才返回vector
//         		}
//         	}
//         }
//         return {};
// 	}
// };

// 时间复杂度O(n^2)
// 空间复杂度O(1)
// 运行速度慢，且内存空间消耗大


// 方法二：两遍哈希表
// class Solution{
// 	vector<int> twoSum(vector<int>& nums, int target){
// 		map<int, int> a;				// 建立hash表存放数组元素
// 		vector<int> result(2, -1);		// 存放结果，初始值为[-1, -1]
        
//         // 存入字典，并且是索引作为value，可能会有问题，key可能会重复，这在map中是不允许的
// 		for(int i = 0; i < nums.size(); i++){
// 			a.insert(map<int, int>::value_type(nums[i], i));		// 字典类型？必须添加字典对象吗？可以a.insert(nums[i], i)吗
// 		}

// 		for(int i = 0; i < nums.size(); i++){
//             if(a.count(target - nums[i]) > 0 && (a[target-nums[i]] != i)){		// a.count(target - nums[i]) > 0， 什么意思，map.count(key)，存在返回1，不存在返回0
//             	                                                                // 因为map中的所有key数据都是不同的，要么有一个，要么不存在
//             																	// a[target-nums[i]] != i， 表示找到的这个数不能是nums[i]同一个数字
//             	result[0] = i;
//             	result[1] = a[target-nums[i]];
//             	break;
//             }
// 		}

// 		return result;
// 	}
// };

// 时间复杂度O(n)
// 空间复杂度O(n)

// 方法三：一遍哈希表
class Solution{
public:
	vector<int> twoSum(vector<int>& nums, int target){
		map<int, int> a; 
		vector<int> result(2, -1);
		for(int i = 0; i < nums.size(); i++){
			if(a.count(target - nums[i])==1 && a[target - nums[i]] != i){
				// 字典中存在目标值
				result[0] = a[target - nums[i]];
				result[1] = i;
				break;
			}
			else{
				// 不存在，则存放它
				a.insert({nums[i], i});		// 用花括号括起来也是可以的
			}
		}		
		return result;
	}
};




int main(){
	cout << "hello, world" << endl;
	return 0;
}





// vector知识点
// 1、vector中的圆括号和花括号

// int main{
// 	vector<int> v_int{10};			// 花括号，一个数初始化（赋值）表示赋一个值，所以构造用花括号
// 	vector<int> v_int2(10);			// 圆括号，一个数表示用几个相同元素初始化，

// 	cout << "vector v_int:" << endl;
// 	for(auto & i: v_int)			// 类似于迭代器？iter
// 		cout << i << endl;
//     cout << endl;

//     cout << "vector v_int2:" << endl;
//     for(auto & i : v_int2)
//     	cout << i << endl;

//     return 0;
// }



