// RPCDemo.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "RPCDemo_h.h"

int _tRPCDemoMain(int argc, _TCHAR* argv[])
{
	return 0;
}


// 下面的函数是为了满足链接需要而写的，没有的话会出现链接错误
void __RPC_FAR* __RPC_USER midl_user_allocate(size_t len)
{
	return(malloc(len));
}
void __RPC_USER midl_user_free(void __RPC_FAR *ptr)
{
	free(ptr);
}