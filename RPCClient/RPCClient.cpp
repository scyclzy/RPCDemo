// RPCClient.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <locale.h>
#include "..\RPCDemo\RPCDemo_h.h"

int _tmain(int argc, _TCHAR* argv[])
{
	if (argc < 2) {
		_wsetlocale(LC_ALL, L"chs");
		wprintf_s(L"请输入ip地址，格式为 testClient.exe xxx.xxx.xxx.xxx\n");
		Sleep(2000);
		return 0;
	}

	wprintf_s(L"server ip: %s\n", argv[1]);

	RPC_WSTR pszStringBinding = NULL;
	int x, y, rval;

	RpcStringBindingCompose(
		NULL,
		(RPC_WSTR)L"ncacn_ip_tcp",
		(RPC_WSTR)argv[1] /*NULL*/,
		(RPC_WSTR)L"13521",
		NULL,
		&pszStringBinding
		);

	// 绑定接口，这里要和 test.acf 的配置一致，那么就是test_Binding
	RpcBindingFromStringBinding(pszStringBinding, &test_Binding);

	// 下面是调用服务端的函数了
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


	// 释放资源
	RpcStringFree(&pszStringBinding);
	RpcBindingFree(&test_Binding);

	return 0;
}

