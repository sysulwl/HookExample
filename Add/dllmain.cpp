// dllmain.cpp : ���� DLL Ӧ�ó������ڵ㡣
#include "stdafx.h"

//ǧ�����������WINAPI,������õ�ʱ��ز�����������Ŷ��
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

