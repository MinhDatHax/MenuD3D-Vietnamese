// Menu is coded by Minh Dat Hax
// Menu run in x64 & x32bit
// Thanks for using
// My profile : https://github.com/MinhDatHax


#include "IncludeAndLib.h"

#ifdef _WIN64
#define GWL_WNDPROC GWLP_WNDPROC
#endif

//extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

void Menu(LPDIRECT3DDEVICE9 lmdDevice);
void MenuChinh(LPDIRECT3DDEVICE9 lmdDevice);


EndScene BanGoc_EndScene = NULL;
WNDPROC oWndProc;
static HWND window = NULL;

// Khai báo bật tắt chức năng hack

// Khai báo bật tắt chức năng hack

bool init = false;
long __stdcall EndSceneCuaToi(LPDIRECT3DDEVICE9 lmdDevice)                // Hàm được Hook vào file d3d9
{
	Menu(lmdDevice);        // Chạy hàm Menu
	BanPhim();
	TongSoItem = 0;

	return BanGoc_EndScene(lmdDevice);
}

void Menu(LPDIRECT3DDEVICE9 lmdDevice)                                   // Cái này để vẽ menu đó ai muốn thêm gì thì viết ở đây
{
	if (GetAsyncKeyState(VK_INSERT) & 1) 
	{
		hienthimenu = !hienthimenu;        // Chức năng bật tắt menu. Biến hienthimenu nằm ở file BangDieuKhien.h
		!phongchu;
		TaoPhongChu(lmdDevice);
	}

	TaoPhongChu(lmdDevice);   // Load phông chữ
	//===================================================================================== Đây là cái bảng (Đừng sửa nó)
	VeChu(50, 10, "ADMIN : MINH DAT (DARK.STAR) | CHAO MOI NGUOI NHA !! | 2022 - 2023", Do);

	if (hienthimenu == true) 
	{
		MenuChinh(lmdDevice);
	}

	if (Items[2].bat_tat)       // Nếu như bật chức năng thì thực hiện câu lệnh bên dưới
	{
		VeHop(a, b - g - 30 + 15, c, b - g - 30, Xammo, lmdDevice);
		VeChu(a + 10, (b - g - 10), "Hack & Mod CF OFFLINE by Minh Dat", Do);
		// Menu nhỏ
	}

	ChucNang0(lmdDevice);	 // Chạy biến ChucNang0(LPDIRECT3DDEVICE9 lmdDevice) bên ChucNangHack.h
	ChucNang1();             // Chạy biến ChucNang1() bên ChucNangHack.h
	
	ChaylaiPhongChu();        // Chạy lại phông chữ


	// Nếu muốn sửa tọa độ hay độ dài rộng menu thì sửa ở VeMenu.h nhé !
	// a và b là tọa độ đặt Menu
	// c và d là độ dài rộng menu
}

void MenuChinh(LPDIRECT3DDEVICE9 lmdDevice) 
{
	TaoPhongChu(lmdDevice);
	//=====================================================================================
	VeHop(a, b, c, d, Xanhla, lmdDevice);
	VeHop(a + e, b + e, c - (e * 2), d - (e * 2), Xam, lmdDevice);
	//=====================================================================================
	VeChu(a + e + 10, b + e + 6, "Menu hack by Minh Dat", Vang);    // Tiêu đề menu

	ThemItem("Tam ao", 1, lmdDevice, Items[0]);                // Đây là các chức năng để mình chọn đó
	ThemNhieuItem("Chuc Nang 1", 2, lmdDevice, Items[1]);                   // Ở 2 cái ThemItem đấy có thấy số 1 và 2 không ? Đó chính là thứ tự của chức năng đó
	ThemItem("Menu nho", 3, lmdDevice, Items[2]);
	//=====================================================================================
	ChaylaiPhongChu();
}

void TaoThietBi() 
{
	//=======================================================================================================================================================
	IDirect3D9* MenuD3D = Direct3DCreate9(D3D_SDK_VERSION);
	if (!MenuD3D)
		return;

	D3DPRESENT_PARAMETERS dellbiet = { 0 };
	dellbiet.SwapEffect = D3DSWAPEFFECT_DISCARD;
	dellbiet.hDeviceWindow = GetForegroundWindow();
	dellbiet.Windowed = true;

	IDirect3DDevice9* lmdDevice = nullptr;

	HRESULT ketqua = MenuD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, dellbiet.hDeviceWindow, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &dellbiet, &lmdDevice);
	if (FAILED(ketqua) || !lmdDevice) {
		MenuD3D->Release();
		return;
	}

	void** dTable = *reinterpret_cast<void***>(lmdDevice);

	lmdDevice->Release();
	MenuD3D->Release();
	//============================================================================================================================================================================================================================================
}



// KHÔNG CẦN QUAN TÂM CÁI EnumWindowsCallback và GetProcessWindow đâu


BOOL CALLBACK EnumWindowsCallback(HWND handle, LPARAM lParam)
{
	DWORD wndProcId;
	GetWindowThreadProcessId(handle, &wndProcId);

	if (GetCurrentProcessId() != wndProcId)
		return TRUE; // Bỏ qua cửa sổ tiếp theo

	window = handle;
	return FALSE; // Tìm thấy cửa sổ sẽ hủy bỏ tìm kiếm
}

HWND GetProcessWindow()
{
	window = NULL;
	EnumWindows(EnumWindowsCallback, NULL);
	return window;
}

DWORD WINAPI LyMinhDatThread(LPVOID lpReserved)
{
	TaoThietBi();     // Chạy biến TaoThietBi trước khi inject

	bool attached = false;
	do
	{
		if (kiero::init(kiero::RenderType::D3D9) == kiero::Status::Success)
		{
						
			kiero::bind(42, (void**)& BanGoc_EndScene, EndSceneCuaToi);    // Inject vào hàm EndScene của file d3d9.dll
			do
				window = GetProcessWindow();
			while (window == NULL);
			attached = true;
		}
	} while (!attached);
	return TRUE;
}

BOOL WINAPI DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpReserved)
{
	switch (dwReason)
	{
	case DLL_PROCESS_ATTACH:
		DisableThreadLibraryCalls(hModule);
		CreateThread(nullptr, 0, LyMinhDatThread, hModule, 0, nullptr);
		break;
	case DLL_PROCESS_DETACH:
		kiero::shutdown();
		break;
	}
	return TRUE;
}
