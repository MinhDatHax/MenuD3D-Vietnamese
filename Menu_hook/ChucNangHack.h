#include "IncludeAndLib.h"

void ChucNang0(LPDIRECT3DDEVICE9 lmd)
{
	if (Items[0].bat_tat)       // Nếu như bật chức năng thì thực hiện câu lệnh bên dưới 
	{
		VeTamAo(TrungTam_TrucX - 10, TrungTam_TrucY - 1, 20, 2, Xanhla, lmd);   // Tên dD3D9 có thể thay bằng tên của kiểu khai báo LPDIRECT3DDEVICE9 mà bạn đã đặt. Không nhất thiết phải để là dD3D9 (Để vậy có thể hệ thống báo lỗi).
		VeTamAo(TrungTam_TrucX - 1, TrungTam_TrucY - 10, 2, 20, Xanhla, lmd);
	}
}

// ======================================================================================

void ChucNang1()
{
	float tocdochay = 1.0f;
	DWORD64 cns;
	DWORD64 CShell = (DWORD64)GetModuleHandleA("CShell_x64.dll");
	cns = *(DWORD64*)(CShell + 0x21EFF88);
	float backup = *(float*)(cns + 0x8);

	if (Items[1].soItem == 2)
	{
		*(float*)(cns + 0x8) = tocdochay * 2; // Chỉnh 10.0f càng lên cao càng chạy nhanh (Bằng phím SHIFT)
	}
	if (Items[1].soItem == 3)
	{
		*(float*)(cns + 0x8) = tocdochay * 3; // Chỉnh 10.0f càng lên cao càng chạy nhanh (Bằng phím SHIFT)
	}
	if (Items[1].soItem == 4)
	{
		*(float*)(cns + 0x8) = tocdochay * 4; // Chỉnh 10.0f càng lên cao càng chạy nhanh (Bằng phím SHIFT)
	}
	if (Items[1].soItem == 5)
	{
		*(float*)(cns + 0x8) = tocdochay * 5; // Chỉnh 10.0f càng lên cao càng chạy nhanh (Bằng phím SHIFT)
	}
	if (Items[1].soItem == 6)
	{
		*(float*)(cns + 0x8) = tocdochay * 6; // Chỉnh 10.0f càng lên cao càng chạy nhanh (Bằng phím SHIFT)
	}
	if (Items[1].soItem == 1)
	{
		*(float*)(cns + 0x8) = backup;
	}
}