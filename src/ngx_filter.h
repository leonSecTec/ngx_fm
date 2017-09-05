/*
 * ngx_filter.h
 *
 *  Created on: 2017年9月4日
 *      Author: leon
 */

#ifndef NGX_FILTER_H_
#define NGX_FILTER_H_

#include <stdio.h>
#include <stddef.h>
#include "ngx_config.h"
#include "ngx_core.h"
#include "ngx_http.h"

typedef struct {
	ngx_str_t fm_string;
	ngx_flag_t fm_enable;
} ngx_http_fm_loc_conf_t;

static char *ngx_http_fm_string(ngx_conf_t *cf, ngx_command_t *cmd, void *conf);

static char *ngx_http_fm_enable(ngx_conf_t *cf, ngx_command_t *cmd, void *conf);

static void *ngx_http_fm_create_loc_conf(ngx_conf_t *cf);

static ngx_int_t ngx_fm_module_init(ngx_conf_t *cf);

#endif /* NGX_FILTER_H_ */
