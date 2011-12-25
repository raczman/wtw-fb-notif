#pragma once

#include "wtwProtocol.h"

int __inline wtwOutputChatInfo (
								WTWFUNCTIONS *pF, 
								const wchar_t * dstID,
								const wchar_t * netClass,
								int netId,
								const wchar_t * msg)
{
	wtwMessageDef lMsg;
	initStruct(lMsg);

	lMsg.contactData.id		= dstID;
	lMsg.contactData.netClass	= netClass;
	lMsg.contactData.netId	= netId;

	lMsg.msgMessage  = msg;
	lMsg.msgFlags	 = WTW_MESSAGE_FLAG_CHAT_MSG | WTW_MESSAGE_FLAG_INFO;

	lMsg.msgTime	 = time(NULL);

	return pF->fnCall(WTW_CHATWND_SHOW_MESSAGE, reinterpret_cast<WTW_PARAM>(&lMsg), NULL);
}