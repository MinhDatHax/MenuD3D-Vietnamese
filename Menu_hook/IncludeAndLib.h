#ifndef _D3D9_H
#define _D3D9_H

#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")

#include <d3d9.h>
#include <d3dx9.h>

#include <Windows.h>
#include <ctime>
#include <string>
#include "kiero/kiero.h"
#include "kiero/minhook/include/MinHook.h"
//======================================================
#include "BangMau.h"
#include "VeMenu.h"
#include "BangDieuKhien.h"
#include "ChucNangHack.h"

using namespace std;

typedef long(__stdcall* EndScene)(LPDIRECT3DDEVICE9);
typedef LRESULT(CALLBACK* WNDPROC)(HWND, UINT, WPARAM, LPARAM);

#endif
