/*
 * ngx_filter.c
 *
 *  Created on: 2017年9月4日
 *      Author: leon
 */

#include "ngx_filter.h"

static ngx_command_t ngx_http_fm_commands[] = { {
ngx_string("ngx_http_fm_string"),
NGX_HTTP_MAIN_CONF | NGX_HTTP_SRV_CONF | NGX_HTTP_LOC_CONF | NGX_HTTP_SIF_CONF |
NGX_HTTP_LMT_CONF | NGX_CONF_FLAG, ngx_http_fm_string,
NGX_HTTP_LOC_CONF_OFFSET, offsetof(ngx_http_fm_loc_conf_t, fm_string), NULL },

{
ngx_string("ngx_http_fm_enable"),
NGX_HTTP_MAIN_CONF | NGX_HTTP_SRV_CONF | NGX_HTTP_LOC_CONF | NGX_HTTP_SIF_CONF |
NGX_HTTP_LMT_CONF | NGX_CONF_FLAG, ngx_http_fm_enable,
NGX_HTTP_LOC_CONF_OFFSET, offsetof(ngx_http_fm_loc_conf_t, fm_enable), NULL },

ngx_null_command };

static ngx_http_module_t ngx_http_fm_module_ctx = {
		NULL, ngx_fm_module_init, NULL, NULL, NULL, NULL, ngx_http_fm_create_loc_conf, NULL
};

ngx_module_t ngx_http_fm_module = {
		NGX_MODULE_V1, &ngx_http_fm_module_ctx, ngx_http_fm_commands, NGX_HTTP_MODULE, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NGX_MODULE_V1_PADDING
};

static void *ngx_http_fm_create_loc_conf(ngx_conf_t *cf) {
	ngx_http_fm_loc_conf_t *local_conf = NULL;
	local_conf = ngx_pcalloc(cf->pool, sizeof(ngx_http_fm_loc_conf_t));
	if(local_conf == NULL) {
		return NULL;
	}

	ngx_str_null(&local_conf->fm_string);
	local_conf->fm_enable = NGX_CONF_UNSET;

	return local_conf;
}

static char *ngx_http_fm_string(ngx_conf_t *cf, ngx_command_t *cmd, void *conf) {
	ngx_http_fm_loc_conf_t *local_conf;

	local_conf  = conf;
	char *rv = ngx_conf_set_str_slot(cf, cmd, conf);

	ngx_conf_log_error(NGX_LOG_EMERG, cf, 0, "fm_string:%s", local_conf->fm_string);

	return rv;
}

static char *ngx_http_fm_enable(ngx_conf_t *cf, ngx_command_t *cmd, void *conf) {
	ngx_http_fm_loc_conf_t *local_conf;
	local_conf = conf;
	char *rv = NULL;

	rv = ngx_conf_set_num_slot(cf, cmd, conf);

	ngx_conf_log_error(NGX_LOG_EMERG, cf, 0, "fm_enable:%d", local_conf->fm_enable);

	return rv;
}

static ngx_int_t ngx_http_fm_handler(ngx_http_request_t *r) {
	ngx_log_error(NGX_LOG_EMERG, r->connection->log, 0, "r->method : %d",(int) r->method);
	ngx_log_error(NGX_LOG_EMERG, r->connection->log, 0, "r->http_version: %d",(int) r->http_version);
	ngx_log_error(NGX_LOG_EMERG, r->connection->log, 0, "r->uri.data: %s",r->uri.data);
	ngx_log_error(NGX_LOG_EMERG, r->connection->log, 0, "ngx_behavior_filter");

	return NGX_OK;
}

static ngx_int_t ngx_fm_module_init(ngx_conf_t *cf) {
	ngx_http_handler_pt			*h;
	ngx_http_core_main_conf_t	*cmcf;

	cmcf = ngx_http_conf_get_module_main_conf(cf, ngx_http_core_module);

	h = ngx_array_push(&cmcf->phases[NGX_HTTP_POST_READ_PHASE].handlers);
	if(h == NULL) {
		return NGX_ERROR;
	}

	*h = ngx_http_fm_handler;

	return NGX_OK;
}


