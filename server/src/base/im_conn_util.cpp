//
//  im_conn_util.cpp
//  TeamTalk
//
//  Created by benqi on 15/8/5.
//  Copyright (c) 2015年 benqi. All rights reserved.
//

#include "im_conn_util.h"

#include "base/imconn.h"
#include "base/ImPduBase.h"

// 创建一个pdu对象，把消息塞进去
int SendMessageLite(CImConn *conn, uint16_t sid, uint16_t cid, const ::google::protobuf::MessageLite *message)
{
    CImPdu pdu;

    pdu.SetPBMsg(message);
    pdu.SetServiceId(sid);
    pdu.SetCommandId(cid);

    return conn->SendPdu(&pdu);
}

int SendMessageLite(CImConn *conn, uint16_t sid, uint16_t cid, uint16_t seq_num, const ::google::protobuf::MessageLite *message)
{
    CImPdu pdu;

    pdu.SetPBMsg(message);
    pdu.SetServiceId(sid);
    pdu.SetCommandId(cid);
    pdu.SetSeqNum(seq_num);

    return conn->SendPdu(&pdu);
}

int SendMessageLite(CImConn *conn, uint16_t sid, uint16_t cid, uint16_t seq_num, uint16_t error, const ::google::protobuf::MessageLite *message)
{
    CImPdu pdu;

    pdu.SetPBMsg(message);
    pdu.SetServiceId(sid);
    pdu.SetCommandId(cid);
    pdu.SetSeqNum(seq_num);
    pdu.SetError(error);

    return conn->SendPdu(&pdu);
}