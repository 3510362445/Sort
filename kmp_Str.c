#include<stdio.h>
#include <stdlib.h>
#include <string.h>

//求得next数组->prefix   pattern内保存的要查找的字符串
void prefix_Table(char pattern[], int prefix[], int n) {
	prefix[0] = 0;//默认第一个元素为0，没有与之比较的元素
	int len = 0;//pattern数组的下标
	int i = 1;
	while (i < n)//每次判断第i个前缀字符串的next
	{
		if (pattern[i] == pattern[len]) {//匹配的情况
			len++;
			prefix[i] = len;
			i++;
		}
		else {//不匹配的情况
			if (len > 0)
				len = prefix[len - 1];
			else {					//处理第一二个字符不匹配时无法跳出循环的问题
				prefix[i] = len;
				i++;
			}
		}
	}
}

//移动next数组，便于后期查找字符串
void move_Prefix(int prefix[], int n) {
	int i;
	for (i = n; i > 0; i--) {
		prefix[i] = prefix[i - 1];
	}
	prefix[0] = -1;//默认第一个元素为-1
}

//kmp算法
void kmp_Search(char text[], char pattern[]) {
	int n = strlen(pattern);//计算查找的字符串长度
	int m = strlen(text);
	int i = 0, j = 0;//i对应T,j对应P
	int* prefix = malloc(sizeof(pattern) * n);
	prefix_Table(pattern, prefix, n);//得到前缀数组
	move_Prefix(prefix, n);//移动前缀数组
	while (i < m) {
		if (j == n - 1 && text[i] == pattern[j])//完全匹配成功
			printf("found pattern at %d\n", i - j);//i-j位匹配的第一个字符位置
		if (text[i] == pattern[j]) {//当前字符匹配成功
			i++;
			j++;
		}
		else//当前字符匹配失败，需要移动next数组
		{
			j = prefix[j];
			if (j == -1) {//全部不匹配，则从第一个元素重新开始
				i++;
				j++;
			}
		}
	}
}

int main()
{
	int i;
	char a[] = "aaabcdecfabcd";
	char b[] = "abcd";
	kmp_Search(a, b);

	return 0;
}