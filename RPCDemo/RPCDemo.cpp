// RPCDemo.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "RPCDemo_h.h"

int _tRPCDemoMain(int argc, _TCHAR* argv[])
{
	return 0;
}


// ����ĺ�����Ϊ������������Ҫ��д�ģ�û�еĻ���������Ӵ���
void __RPC_FAR* __RPC_USER midl_user_allocate(size_t len)
{
	return(malloc(len));
}
void __RPC_USER midl_user_free(void __RPC_FAR *ptr)
{
	free(ptr);
}