/*
 * ngx_search.h
 *
 *  Created on: 2017年9月5日
 *      Author: leon
 */

#ifndef NGX_SEARCH_H_
#define NGX_SEARCH_H_

#include <stddef.h>
#include <stdio.h>
#include <string.h>

const char* ngx_sunday(const char* str, const char* sub);

int ngx_search(unsigned char* str);

#endif /* NGX_SEARCH_H_ */
