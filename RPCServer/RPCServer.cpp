// RPCServer.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "..\RPCDemo\RPCDemo_h.h"

int intAdd(int x, int y) {
	printf("%d + %d = %d\n", x, y, x + y);
	return x + y;
}

boolean shutdownServer() {
	return true;
}


int _tmain(int argc, _TCHAR* argv[])
{
	// 采用tcp协议，13521端口
	RpcServerUseProtseqEp((RPC_WSTR)L"ncalrpc", RPC_C_PROTSEQ_MAX_REQS_DEFAULT,
		(RPC_WSTR)L"RPCDemo", NULL);
	// 注册，HelloWorld_v1_0_s_ifspec定义域头文件test.h
	// 注意：从Windows XP SP2开始，增强了安全性的要求，如果用RpcServerRegisterIf()注册接口，客户端调用时会出现
	// RpcExceptionCode() == 5，即Access Denied的错误，因此，必须用RpcServerRegisterIfEx带RPC_IF_ALLOW_CALLBACKS_WITH_NO_AUTH标志
	// 允许客户端直接调用
	RpcServerRegisterIfEx(HelloWorld_v1_0_s_ifspec, NULL, NULL, RPC_IF_ALLOW_CALLBACKS_WITH_NO_AUTH, 0, NULL);
	// 开始监听，本函数将一直阻塞
	RPC_STATUS result = RpcServerListen(1, 20, FALSE);

	printf("end-------------RPC_STATUS: %d\n", result);

	return 0;
}

