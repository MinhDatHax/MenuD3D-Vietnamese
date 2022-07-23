#include "IncludeAndLib.h"

bool hienthimenu = false;

void BanPhim()
{
	if (GetAsyncKeyState(VK_UP) & 1 && hienthimenu == true)        // Điều khiển mũi tên đi lên
	{
		if (index > 0)
		{
			Items[index].chon = false;
			index--;
		}
		else
		{
			Items[index].chon = false;
			index = TongSoItem - 1;
		}
	}

	if (GetAsyncKeyState(VK_DOWN) & 1 && hienthimenu == true)       // Điều khiển mũi tên đi xuống
	{
		if (index < TongSoItem - 1)
		{
			Items[index].chon = false;
			index++;
		}
		else
		{
			Items[index].chon = false;
			index = 0;
		}
	}

	if (GetAsyncKeyState(VK_LEFT) & 1 && hienthimenu == true)      // Nếu như bấm mũi tên sang trái là tắt chức năng
	{
		Items[index].bat_tat = false;

		if (Items[index].soItem > 1)
		{
			Items[index].soItem--;
		}
	}

	if (GetAsyncKeyState(VK_RIGHT) & 1 && hienthimenu == true)     // Nếu như bấm mũi tên sang phải là bật chức năng
	{
		Items[index].bat_tat = true;

		if (Items[index].soItem < 6)
		{
			Items[index].soItem++;
		}
	}
	Items[index].chon = true;
}
