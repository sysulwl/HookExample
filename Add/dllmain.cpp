// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "stdafx.h"

//千万别忘记声明WINAPI,否则调用的时候回产生声明错误哦！
int WINAPI add(int a,int b)
{  
	return a+b;
}

BOOL APIENTRY DllMain( HANDLE hModule, 
					  DWORD  ul_reason_for_call, 
					  LPVOID lpReserved
					  )
{
	return TRUE;
}

