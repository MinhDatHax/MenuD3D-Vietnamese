#include "IncludeAndLib.h"
// ========================================== Hỗ trợ cho cả file này và file MenuD3D.cpp
int a = 50;
int b = 80;
int c = 250;
int d = 500;
int e = 2;  // Tính phần viền
// ========================================== Hỗ trợ cho cả file này và file MenuD3D.cpp
int kichthuocbattat_kichthuocchu = 15;
int g = 20;
// ========================================== Hỗ trợ cho file BangDieuKhien.h
struct Item
{
	bool chon;
	bool bat_tat;
	int soItem = 1;
};
Item Items[200];

int TongSoItem = -1;
int index = -1;
// ========================================== Hỗ trợ cho file BangDieuKhien.h

LPD3DXFONT phongchu;     // Khai báo biến Phông chữ

// =========================================================================================================================

void VeChu(int x, int y, const char* vanban, DWORD Mau)
{
	RECT rect, rect2;
	SetRect(&rect, x, y, x, y);
	SetRect(&rect2, x - 0.1, y + 0.2, x - 0.1, y + 0.);
	phongchu->DrawTextA(NULL, vanban, -1, &rect2, DT_LEFT | DT_NOCLIP, 0x00000000);
	phongchu->DrawTextA(NULL, vanban, -1, &rect, DT_LEFT | DT_NOCLIP, Mau);
}

// =========================================================================================================================

void VeHop(int x, int y, int w, int h, D3DCOLOR Mau, LPDIRECT3DDEVICE9 dD3D9)
{
	struct Vertex
	{
		float x, y, z, ht;
		DWORD Mau;
	}
	V[4] =
	{
				{x,y + h, 0.0f, 0.0f, Mau},
				{x,y, 0.0f, 0.0f, Mau},
				{x + w,y + h, 0.0f, 0.0f, Mau},
				{x + w,y, 0.0f, 0.0f, Mau}
	};

	dD3D9->SetTexture(0, NULL);
	dD3D9->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1);
	dD3D9->SetRenderState(D3DRS_ALPHABLENDENABLE, true);
	dD3D9->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	dD3D9->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, V, sizeof(Vertex));
	return;
}

// =========================================================================================================================

void TaoPhongChu(LPDIRECT3DDEVICE9 dD3D9)
{
	if (!phongchu)
	{
		D3DXCreateFont(dD3D9, 15, 0, FW_BOLD, false, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Tahoma", &phongchu);
	}
}

// =========================================================================================================================

void ChaylaiPhongChu()
{
	phongchu->OnLostDevice();
	phongchu->OnResetDevice();
}

// =========================================================================================================================

void ThemItem(const char* Ten, int so, LPDIRECT3DDEVICE9 dD3D9, Item its)
{
	int g;
	g = b + 15 + (so * 20);

	TongSoItem++;
	if (its.chon) 
	{
		VeChu(a + ((e * 3) * 4), g, Ten, Vang);
	}
	else 
	{
		VeChu(a + ((e * 3) * 4), g, Ten, Trang);
	}

	if (its.bat_tat)
	{
		VeChu(a + (c - (e * 2)) - 35, g, "[Bat]", Xanhla);
		VeHop(a + (e * 3), g, kichthuocbattat_kichthuocchu, kichthuocbattat_kichthuocchu, Xanhla, dD3D9);
	}
	else 
	{
		VeChu(a + (c - (e * 2)) - 35, g, "[Tat]", Do);
		VeHop(a + (e * 3), g, kichthuocbattat_kichthuocchu, kichthuocbattat_kichthuocchu, Do, dD3D9);
	}
	
	//VeChu(a + ((e * 3) * 4), g, Ten, Trang);
}

// =========================================================================================================================

void ThemNhieuItem(const char* Ten, int so, LPDIRECT3DDEVICE9 dD3D9, Item its) 
{
	int g;
	g = b + 15 + (so * 20);

	TongSoItem++;
	if (its.chon)
	{
		VeChu(a + ((e * 3) * 4), g, Ten, Vang);
	}
	else
	{
		VeChu(a + ((e * 3) * 4), g, Ten, Trang);
	}

	if (its.soItem == 1)           // Tắt
	{
		VeChu(a + (c - (e * 2)) - 35, g, "[Tat]", Do);
		VeHop(a + (e * 3), g, kichthuocbattat_kichthuocchu, kichthuocbattat_kichthuocchu, Do, dD3D9);
	} 

	if (its.soItem == 2)          // x2
	{
		VeChu(a + (c - (e * 2)) - 35, g, "[x2]", Vang);
		VeHop(a + (e * 3), g, kichthuocbattat_kichthuocchu, kichthuocbattat_kichthuocchu, Xanhla, dD3D9);
	}

	if (its.soItem == 3)          // x3
	{
		VeChu(a + (c - (e * 2)) - 35, g, "[x3]", Vang);
		VeHop(a + (e * 3), g, kichthuocbattat_kichthuocchu, kichthuocbattat_kichthuocchu, Xanhla, dD3D9);
	}

	if (its.soItem == 4)          // x4
	{
		VeChu(a + (c - (e * 2)) - 35, g, "[x4]", Vang);
		VeHop(a + (e * 3), g, kichthuocbattat_kichthuocchu, kichthuocbattat_kichthuocchu, Xanhla, dD3D9);
	}

	if (its.soItem == 5)          // x5
	{
		VeChu(a + (c - (e * 2)) - 35, g, "[x5]", Vang);
		VeHop(a + (e * 3), g, kichthuocbattat_kichthuocchu, kichthuocbattat_kichthuocchu, Xanhla, dD3D9);
	}

	if (its.soItem == 6)          // x6
	{
		VeChu(a + (c - (e * 2)) - 35, g, "[x6]", Vang);
		VeHop(a + (e * 3), g, kichthuocbattat_kichthuocchu, kichthuocbattat_kichthuocchu, Xanhla, dD3D9);
	}
}

// =========================================================================================================================

int TrungTam_TrucX = GetSystemMetrics(SM_CXSCREEN) / 2;    // Trung tâm của trục X trên màn hình
int TrungTam_TrucY = GetSystemMetrics(SM_CYSCREEN) / 2;    // Trung tâm của trục Y trên màn hình

void VeTamAo(int x, int y, int w, int h, D3DCOLOR Mau, LPDIRECT3DDEVICE9 dD3D9)  // Lưu ý là chỉ dành cho game toàn màn hình
{
	D3DRECT rec = { x, y, x + w, y + h };
	dD3D9->Clear(1, &rec, D3DCLEAR_TARGET, Mau, 0, 0);

	// Muốn vẽ được tâm ảo thì code như sau :
	// VeTamAo(TrungTam_TrucX - 5, TrungTam_TrucY, 10, 1, Xanhla, dD3D9);   // Tên dD3D9 có thể thay bằng tên của kiểu khai báo LPDIRECT3DDEVICE9 mà bạn đã đặt. Không nhất thiết phải để là dD3D9 (Để vậy có thể hệ thống báo lỗi).
	// VeTamAo(TrungTam_TrucX, TrungTam_TrucY - 5, 1, 10, Xanhla, dD3D9);
}