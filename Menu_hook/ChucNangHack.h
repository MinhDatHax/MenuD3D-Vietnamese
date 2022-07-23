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
	
	if (Items[1].soItem == 2)
	{
		
	}
	if (Items[1].soItem == 3)
	{
		
	}
	if (Items[1].soItem == 4)
	{
		
	}
	if (Items[1].soItem == 5)
	{
		
	}
	if (Items[1].soItem == 6)
	{
		
	}
	if (Items[1].soItem == 1) // Tắt
	{
		
	}
}
