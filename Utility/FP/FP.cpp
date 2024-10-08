//**************************************************************************/
// Copyright (c) 1998-2020 Autodesk, Inc.
// All rights reserved.
// 
// Use of this software is subject to the terms of the Autodesk license 
// agreement provided at the time of installation or download, or which 
// otherwise accompanies this software in either electronic or hard copy form.
//**************************************************************************/
// DESCRIPTION: Plugin Wizard generated plugin
// AUTHOR: 
//***************************************************************************/

#include "FP.h"


#define FP_CLASS_ID Class_ID(0xd2b649f4, 0x507ad822)

class FP : public UtilityObj{
public:
	// Constructor/Destructor
	FP();
	virtual ~FP();

	void DeleteThis() override {}

	void BeginEditParams(Interface* ip, IUtil* iu) override;
	void EndEditParams(Interface* ip, IUtil* iu) override;

	virtual void Init(HWND hWnd);
	virtual void Destroy(HWND hWnd);

	// Singleton access
	static FP* GetInstance()
	{
		static FP theFP;
		return &theFP;
	}

private:
	static INT_PTR CALLBACK DlgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	HWND hPanel;

	IUtil* iu;
};


class FPClassDesc : public ClassDesc2 
{
public:
	int           IsPublic() override                               { return TRUE; }
	void*         Create(BOOL /*loading = FALSE*/) override         { return FP::GetInstance(); }
	const TCHAR*  ClassName() override                              { return GetString(IDS_CLASS_NAME); }
	const TCHAR*  NonLocalizedClassName() override                  { return _T("FP"); }
	SClass_ID     SuperClassID() override                           { return UTILITY_CLASS_ID; }
	Class_ID      ClassID() override                                { return FP_CLASS_ID; }
	const TCHAR*  Category() override                               { return GetString(IDS_CATEGORY); }

	const TCHAR*  InternalName() override                           { return _T("FP"); } // Returns fixed parsable name (scripter-visible name)
	HINSTANCE     HInstance() override                              { return hInstance; } // Returns owning module handle


};

ClassDesc2* GetFPDesc()
{
	static FPClassDesc FPDesc;
	return &FPDesc; 
}




//--- FP -------------------------------------------------------
FP::FP()
	: iu(nullptr)
	, hPanel(nullptr)
{

}

FP::~FP()
{

}

void FP::BeginEditParams(Interface* ip,IUtil* iu)
{
	this->iu = iu;
	hPanel = ip->AddRollupPage(hInstance, MAKEINTRESOURCE(IDD_PANEL), DlgProc, GetString(IDS_PARAMS), 0);
}

void FP::EndEditParams(Interface* ip, IUtil*)
{
	this->iu = nullptr;
	ip -> DeleteRollupPage(hPanel);
	hPanel = nullptr;
}

void FP::Init(HWND /*handle*/)
{

}

void FP::Destroy(HWND /*handle*/)
{

}

INT_PTR CALLBACK FP::DlgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_INITDIALOG:
		 FP::GetInstance() -> Init(hWnd);
		break;

	case WM_DESTROY:
		 FP::GetInstance() -> Destroy(hWnd);
		break;

	case WM_COMMAND:
#pragma message(TODO("React to the user interface commands.  A utility plug-in is controlled by the user from here."))
		break;

	case WM_LBUTTONDOWN:
	case WM_LBUTTONUP:
	case WM_MOUSEMOVE:
		GetCOREInterface()->RollupMouseMessage(hWnd, msg, wParam, lParam);
		break;

	default:
		return 0;
	}
	return 1;
}
