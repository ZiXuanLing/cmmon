/*
 * @File Name: your project
 * @Mail: 1.0
 * @Author: LH
 * @Created Time: Do not edit
 */
#ifndef __HEAD_H__
#define __HEAD_H__

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <sys/errno.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/epoll.h>
#include <poll.h>

#include "color.h"
#include "common.h"
#include "thread_pool.h"

#ifdef _D   /* 在编译的时候加上-D定义宏_D即可 */
#define DBG(fmt, args...) printf(fmt, ##args)
#else
#define DBG(fmt, args...)
#endif

#endif // !__HEAD_H__