/*
 * ngx_search.c
 *
 *  Created on: 2017年9月5日
 *      Author: leon
 */

#include "ngx_search.h"

int ngx_search(unsigned char* str) {
	const char *keyword[] = { "alert", "or", "and", "../" };
	int i;

	for(i = 0; i < 4; i++) {
		if(ngx_sunday((const char*)str, keyword[i]) != NULL) {
			return 1;
		}
	}

	return 0;
}

const char* ngx_sunday(const char* str, const char* sub) {
	const int maxSize = 256;
	int next[maxSize];
	int strLen = strlen(str);
	int subLen = strlen(sub);
	int i, j, pos;

	for (i = 0; i < maxSize; i++) {
		next[i] = subLen + 1;
	}

	for (i = 0; i < subLen; i++) {
		next[(unsigned char) sub[i]] = subLen - i; //计算子串中的字符到字符串结尾的\0之间的距离
	}

	pos = 0;
	while (pos <= (strLen - subLen)) {
		i = pos;
		for (j = 0; j < subLen; j++, i++) {
			if (str[i] != sub[j]) {
				pos += next[(unsigned char) str[pos + subLen]]; //向后移动
				break;
			}

		}

		if (j == subLen) {	//找到字串，返回
			return str + pos;
		}
	}

	return NULL;
}
