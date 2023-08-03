#include<stdio.h>
#include <stdlib.h>
#include <string.h>

//���next����->prefix   pattern�ڱ����Ҫ���ҵ��ַ���
void prefix_Table(char pattern[], int prefix[], int n) {
	prefix[0] = 0;//Ĭ�ϵ�һ��Ԫ��Ϊ0��û����֮�Ƚϵ�Ԫ��
	int len = 0;//pattern������±�
	int i = 1;
	while (i < n)//ÿ���жϵ�i��ǰ׺�ַ�����next
	{
		if (pattern[i] == pattern[len]) {//ƥ������
			len++;
			prefix[i] = len;
			i++;
		}
		else {//��ƥ������
			if (len > 0)
				len = prefix[len - 1];
			else {					//�����һ�����ַ���ƥ��ʱ�޷�����ѭ��������
				prefix[i] = len;
				i++;
			}
		}
	}
}

//�ƶ�next���飬���ں��ڲ����ַ���
void move_Prefix(int prefix[], int n) {
	int i;
	for (i = n; i > 0; i--) {
		prefix[i] = prefix[i - 1];
	}
	prefix[0] = -1;//Ĭ�ϵ�һ��Ԫ��Ϊ-1
}

//kmp�㷨
void kmp_Search(char text[], char pattern[]) {
	int n = strlen(pattern);//������ҵ��ַ�������
	int m = strlen(text);
	int i = 0, j = 0;//i��ӦT,j��ӦP
	int* prefix = malloc(sizeof(pattern) * n);
	prefix_Table(pattern, prefix, n);//�õ�ǰ׺����
	move_Prefix(prefix, n);//�ƶ�ǰ׺����
	while (i < m) {
		if (j == n - 1 && text[i] == pattern[j])//��ȫƥ��ɹ�
			printf("found pattern at %d\n", i - j);//i-jλƥ��ĵ�һ���ַ�λ��
		if (text[i] == pattern[j]) {//��ǰ�ַ�ƥ��ɹ�
			i++;
			j++;
		}
		else//��ǰ�ַ�ƥ��ʧ�ܣ���Ҫ�ƶ�next����
		{
			j = prefix[j];
			if (j == -1) {//ȫ����ƥ�䣬��ӵ�һ��Ԫ�����¿�ʼ
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