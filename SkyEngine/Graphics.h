#pragma once

#include "WinLib.h"
#include <d3d11.h>
#include <wrl.h>
#include "EngineException.h"
#include "Colors.h"
#include "Rect.h"
#include "Surface.h"
#include <cassert>

class Graphics
{
public:
	class Exception : public EngineException
	{
	public:
		Exception(HRESULT hr, const std::wstring& note, const wchar_t* file, unsigned int line);
		std::wstring GetErrorName() const;
		std::wstring GetErrorDescription() const;
		virtual std::wstring GetFullMessage() const override;
		virtual std::wstring GetExceptionType() const override;
	private:
		HRESULT hr;
	};
private:
	// vertex format for the framebuffer fullscreen textured quad
	struct FSQVertex
	{
		float x, y, z;		// position
		float u, v;			// texcoords
	};
public:
	Graphics(class HWNDKey& key);
	Graphics(const Graphics&) = delete;
	Graphics& operator=(const Graphics&) = delete;
	void EndFrame();
	void BeginFrame();
	Color GetPixel(int x, int y) const;
	void PutPixel(int x, int y, int r, int g, int b)
	{
		PutPixel(x, y, { unsigned char(r),unsigned char(g),unsigned char(b) });
	}
	void PutPixel(int x, int y, Color c);
	void DrawSp(int x, int y, const Surface& s)
	{
		const int width = s.GetWidth();
		const int height = s.GetHeight();
		for (int sy = 0; sy < height; sy++)
		{
			for (int sx = 0; sx < width; sx++)
			{
				PutPixel(x + sx, y + sy, s.GetPixel(sx, sy));
			}
		}
	}
	void DrawSp(int x, int y, RectI srcRect, const Surface& s)
	{
		const int width = srcRect.right - srcRect.left;
		const int height = srcRect.bottom - srcRect.top;
		for (int sy = 0; sy < height; sy++)
		{
			for (int sx = 0; sx < width; sx++)
			{
				PutPixel(x + sx, y + sy, s.GetPixel(sx, sy));
			}
		}
	}
	void DrawSprite(int x, int y, RectF srcRect, const RectI& clip, const Surface& s)
	{
		assert(srcRect.left >= 0);
		assert(srcRect.right <= (int)s.GetWidth());
		assert(srcRect.top >= 0);
		assert(srcRect.bottom <= (int)s.GetHeight());
		if (x < clip.left)
		{
			srcRect.left += (float)(clip.left - x);
			x = clip.left;
		}
		if (y < clip.top)
		{
			srcRect.top += (float)(clip.top - y);
			y = clip.top;
		}
		if (x + (int)srcRect.GetWidth() > clip.right)
		{
			srcRect.right -= (float)(x + srcRect.GetWidth() - clip.right);
		}
		if (y + (int)srcRect.GetHeight() > clip.bottom)
		{
			srcRect.bottom -= (float)(y + srcRect.GetHeight() - clip.bottom);
		}
		for (int sy = (int)srcRect.top; sy < (int)srcRect.bottom; sy++)
		{
			for (int sx = (int)srcRect.left; sx < (int)srcRect.right; sx++)
			{
				PutPixel(x + sx - (int)srcRect.left, y + sy - (int)srcRect.top, s.GetPixel(sx, sy));
			}
		}
	}
	void DrawRect(int x, int y, int width, int height, Color c)
	{
		for (int sy = y; sy < y + height; sy++)
		{
			for (int sx = x; sx < x + width; sx++)
			{
				PutPixel(sx, sy, c);
			}
		}
	}
	~Graphics();
private:
	Microsoft::WRL::ComPtr<IDXGISwapChain>				pSwapChain;
	Microsoft::WRL::ComPtr<ID3D11Device>				pDevice;
	Microsoft::WRL::ComPtr<ID3D11DeviceContext>			pImmediateContext;
	Microsoft::WRL::ComPtr<ID3D11RenderTargetView>		pRenderTargetView;
	Microsoft::WRL::ComPtr<ID3D11Texture2D>				pSysBufferTexture;
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView>	pSysBufferTextureView;
	Microsoft::WRL::ComPtr<ID3D11PixelShader>			pPixelShader;
	Microsoft::WRL::ComPtr<ID3D11VertexShader>			pVertexShader;
	Microsoft::WRL::ComPtr<ID3D11Buffer>				pVertexBuffer;
	Microsoft::WRL::ComPtr<ID3D11InputLayout>			pInputLayout;
	Microsoft::WRL::ComPtr<ID3D11SamplerState>			pSamplerState;
	D3D11_MAPPED_SUBRESOURCE							mappedSysBufferTexture;
	Color* pSysBuffer = nullptr;
public:
	static constexpr int ScreenWidth = 800;
	static constexpr int ScreenHeight = 600;
	static RectI GetScreenRect();
};