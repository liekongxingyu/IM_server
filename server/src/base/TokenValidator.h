/*
 * TokenValidator.h
 *
 *  Created on: 2013-10-2
 *      Author: ziteng@mogujie.com
 */
// 生成一个“随时间变化的 token”，并在服务端校验 token 是否有效。它本质是一个“基于时间窗口的签名/口令”，用来做简单鉴权（比如接口调用必须带 token）

#ifndef TOKENVALIDATOR_H_
#define TOKENVALIDATOR_H_

#include "util.h"

/**
 * return 0 if generate token successful
 */
int genToken(unsigned int uid, time_t time_offset, char *md5_str_buf);

bool IsTokenValid(uint32_t user_id, const char *token);

#endif /* TOKENVALIDATOR_H_ */
