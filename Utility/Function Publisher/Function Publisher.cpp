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

#include "Function Publisher.h"


#define FunctionPublisher_CLASS_ID Class_ID(0xa4fc1921, 0x767648f7)

class FunctionPublisher : public UtilityObj{
public:
	// Constructor/Destructor
	FunctionPublisher();
	virtual ~FunctionPublisher();

	void DeleteThis() override {}

	void BeginEditParams(Interface* ip, IUtil* iu) override;
	void EndEditParams(Interface* ip, IUtil* iu) override;

	virtual void Init(HWND hWnd);
	virtual void Destroy(HWND hWnd);

	// Singleton access
	static FunctionPublisher* GetInstance()
	{
		static FunctionPublisher theFunctionPublisher;
		return &theFunctionPublisher;
	}

private:
	static INT_PTR CALLBACK DlgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	HWND hPanel;

	IUtil* iu;
};


class FunctionPublisherClassDesc : public ClassDesc2 
{
public:
	int           IsPublic() override                               { return TRUE; }
	void*         Create(BOOL /*loading = FALSE*/) override         { return FunctionPublisher::GetInstance(); }
	const TCHAR*  ClassName() override                              { return GetString(IDS_CLASS_NAME); }
	const TCHAR*  NonLocalizedClassName() override                  { return _T("FunctionPublisher"); }
	SClass_ID     SuperClassID() override                           { return UTILITY_CLASS_ID; }
	Class_ID      ClassID() override                                { return FunctionPublisher_CLASS_ID; }
	const TCHAR*  Category() override                               { return GetString(IDS_CATEGORY); }

	const TCHAR*  InternalName() override                           { return _T("FunctionPublisher"); } // Returns fixed parsable name (scripter-visible name)
	HINSTANCE     HInstance() override                              { return hInstance; } // Returns owning module handle


};

ClassDesc2* GetFunctionPublisherDesc()
{
	static FunctionPublisherClassDesc FunctionPublisherDesc;
	return &FunctionPublisherDesc; 
}




//--- FunctionPublisher -------------------------------------------------------
FunctionPublisher::FunctionPublisher()
	: iu(nullptr)
	, hPanel(nullptr)
{

}

FunctionPublisher::~FunctionPublisher()
{

}

void FunctionPublisher::BeginEditParams(Interface* ip,IUtil* iu)
{
	this->iu = iu;
	hPanel = ip->AddRollupPage(hInstance, MAKEINTRESOURCE(IDD_PANEL), DlgProc, GetString(IDS_PARAMS), 0);
}

void FunctionPublisher::EndEditParams(Interface* ip, IUtil*)
{
	this->iu = nullptr;
	ip -> DeleteRollupPage(hPanel);
	hPanel = nullptr;
}

void FunctionPublisher::Init(HWND /*handle*/)
{

}

void FunctionPublisher::Destroy(HWND /*handle*/)
{

}

INT_PTR CALLBACK FunctionPublisher::DlgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_INITDIALOG:
		 FunctionPublisher::GetInstance() -> Init(hWnd);
		break;

	case WM_DESTROY:
		 FunctionPublisher::GetInstance() -> Destroy(hWnd);
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
