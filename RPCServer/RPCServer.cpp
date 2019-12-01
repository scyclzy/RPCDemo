// RPCServer.cpp : �������̨Ӧ�ó������ڵ㡣
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
	// ����tcpЭ�飬13521�˿�
	RpcServerUseProtseqEp((RPC_WSTR)L"ncalrpc", RPC_C_PROTSEQ_MAX_REQS_DEFAULT,
		(RPC_WSTR)L"RPCDemo", NULL);
	// ע�ᣬHelloWorld_v1_0_s_ifspec������ͷ�ļ�test.h
	// ע�⣺��Windows XP SP2��ʼ����ǿ�˰�ȫ�Ե�Ҫ�������RpcServerRegisterIf()ע��ӿڣ��ͻ��˵���ʱ�����
	// RpcExceptionCode() == 5����Access Denied�Ĵ�����ˣ�������RpcServerRegisterIfEx��RPC_IF_ALLOW_CALLBACKS_WITH_NO_AUTH��־
	// ����ͻ���ֱ�ӵ���
	RpcServerRegisterIfEx(HelloWorld_v1_0_s_ifspec, NULL, NULL, RPC_IF_ALLOW_CALLBACKS_WITH_NO_AUTH, 0, NULL);
	// ��ʼ��������������һֱ����
	RPC_STATUS result = RpcServerListen(1, 20, FALSE);

	printf("end-------------RPC_STATUS: %d\n", result);

	return 0;
}

