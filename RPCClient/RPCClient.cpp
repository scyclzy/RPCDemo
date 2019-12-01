// RPCClient.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <locale.h>
#include "..\RPCDemo\RPCDemo_h.h"

int _tmain(int argc, _TCHAR* argv[])
{
	RPC_WSTR pszStringBinding = NULL;
	int x, y, rval;

	RpcStringBindingCompose(
		NULL,
		(RPC_WSTR)L"ncalrpc",
		NULL,
		(RPC_WSTR)L"RPCDemo",
		NULL,
		&pszStringBinding
		);

	// �󶨽ӿڣ�����Ҫ�� test.acf ������һ�£���ô����test_Binding
	RpcBindingFromStringBinding(pszStringBinding, &test_Binding);

	// �����ǵ��÷���˵ĺ�����
	RpcTryExcept
	{
		while (1)
		{
			printf("Input two integer: ");
			scanf_s("%d %d", &x, &y);
			rval = intAdd(x, y);
			printf("%d\n", rval);

			Sleep(2000);
		}

	}
	RpcExcept(1)
	{
		printf("RPC Exception %d\n", RpcExceptionCode());
		Sleep(2000);
	}
	RpcEndExcept


	// �ͷ���Դ
	RpcStringFree(&pszStringBinding);
	RpcBindingFree(&test_Binding);

	return 0;
}

