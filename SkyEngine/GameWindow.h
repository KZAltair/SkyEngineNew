#pragma once

#include "WinLib.h"
#include "Graphics.h"
#include "EngineException.h"
#include <string>


// for granting special access to hWnd only for Graphics constructor
class HWNDKey
{
	friend Graphics::Graphics(HWNDKey&);
public:
	HWNDKey(const HWNDKey&) = delete;
	HWNDKey& operator=(HWNDKey&) = delete;
protected:
	HWNDKey() = default;
protected:
	HWND hWnd = nullptr;
};

class GameWindow : public HWNDKey
{
public:
	class Exception : public EngineException
	{
	public:
		using EngineException::EngineException;
		virtual std::wstring GetFullMessage() const override { return GetNote() + L"\nAt: " + GetLocation(); }
		virtual std::wstring GetExceptionType() const override { return L"Windows Exception"; }
	};
	GameWindow(HINSTANCE hInst, wchar_t* pArgs);
	~GameWindow();

	bool ProcessMessage();
	void ShowMessageBox(const std::wstring& title, const std::wstring& message, UINT type = MB_OK) const;
	const std::wstring& GetArgs() const
	{
		return args;
	}

private:
	static LRESULT WINAPI _HandleMsgSetup(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	static LRESULT WINAPI _HandleMsgThunk(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	LRESULT HandleMsg(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

private:
	static constexpr const wchar_t* pWinClassName = L"Sky Engine Window";
	HINSTANCE hInst = nullptr;
	std::wstring args;
};
