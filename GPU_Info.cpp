//Collect all GPU information using DirectX or other APIs
#include "GPU_Info.h"
#include <windows.h>
#include <iostream>
#include <d3d11.h>
#pragma comment(lib, "d3d11.lib")
#include <dxgi.h>
#pragma comment(lib, "dxgi.lib")

//Function to obtain GPU information
void PrintGPUInformation() {
	IDXGIFactory* pFactory = nullptr;
	if (FAILED(CreateDXGIFactory(__uuidof(IDXGIFactory), (void**)&pFactory))) {
		std::cerr << "Failed to create DXGIFactory." << std::endl;
		return;
	}
	IDXGIAdapter* pAdapter = nullptr;
	for (UINT adapterIndex = 0; pFactory->EnumAdapters(adapterIndex, &pAdapter) != DXGI_ERROR_NOT_FOUND; ++adapterIndex) {
		DXGI_ADAPTER_DESC adapterDesc;
		pAdapter->GetDesc(&adapterDesc);
		std::wcout << L"GPU " << adapterIndex + 1 << L": " << adapterDesc.Description << std::endl;
		std::wcout << L"  Dedicated Video Memory: " << adapterDesc.DedicatedVideoMemory / (1024 * 1024) << L" MB" << std::endl;
		std::wcout << L"  Dedicated System Memory: " << adapterDesc.DedicatedSystemMemory / (1024 * 1024) << L" MB" << std::endl;
		std::wcout << L"  Shared System Memory: " << adapterDesc.SharedSystemMemory / (1024 * 1024) << L" MB" << std::endl;
		pAdapter->Release();
	}
	pFactory->Release();
}