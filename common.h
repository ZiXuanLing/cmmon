/*
 * @File Name: common.h
 * @Mail: 1.0
 * @Author: LH
 * @Created Time: Do not edit
 */
#ifndef __COMMON_H__
#define __COMMON_H__

int socket_create(int port);
int socket_connect(const char *ip, int port);
int make_block(int fd);
int make_nonblock(int fd);
#endif // !__COMMON_H__