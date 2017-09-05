# nginx filter module

Build nginx source and filter module
wget http://nginx.org/download/nginx-1.12.1.tar.gz
tar xzvf nginx-1.12.1.tar.gz
cd nginx-1.12.1
./configure --prefix=/opt/nginx --with-threads --with-http_addition_module --with-http_auth_request_module --with-http_dav_module --with-http_flv_module --with-http_gunzip_module --with-http_gzip_static_module --with-http_mp4_module --with-http_random_index_module --with-http_realip_module --with-http_secure_link_module --with-http_ssl_module --with-http_stub_status_module --with-http_sub_module --with-mail --with-mail_ssl_module --add-module=../ngx_fm
make -j4
make install

