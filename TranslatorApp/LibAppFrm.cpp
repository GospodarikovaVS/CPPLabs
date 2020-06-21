// This MFC Samples source code demonstrates using MFC Microsoft Office Fluent User Interface 
// (the "Fluent UI") and is provided only as referential material to supplement the 
// Microsoft Foundation Classes Reference and related electronic documentation 
// included with the MFC C++ library software.  
// License terms to copy, use or distribute the Fluent UI are available separately.  
// To learn more about our Fluent UI licensing program, please visit 
// https://go.microsoft.com/fwlink/?LinkId=238214.
//
// Copyright (C) Microsoft Corporation
// All rights reserved.

// LibAppFrm.cpp : implementation of the CLibAppFrm class
//

#include "pch.h"
#include "framework.h"
#include "TranslatorApp.h"

#include "LibAppFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CLibAppFrm

IMPLEMENT_DYNCREATE(CLibAppFrm, CMDIChildWndEx)

BEGIN_MESSAGE_MAP(CLibAppFrm, CMDIChildWndEx)
	ON_COMMAND(ID_FILE_PRINT, &CLibAppFrm::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CLibAppFrm::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CLibAppFrm::OnFilePrintPreview)
	ON_UPDATE_COMMAND_UI(ID_FILE_PRINT_PREVIEW, &CLibAppFrm::OnUpdateFilePrintPreview)
END_MESSAGE_MAP()

// CLibAppFrm construction/destruction

CLibAppFrm::CLibAppFrm() noexcept
{
	// TODO: add member initialization code here
}

CLibAppFrm::~CLibAppFrm()
{
}


BOOL CLibAppFrm::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying the CREATESTRUCT cs
	if( !CMDIChildWndEx::PreCreateWindow(cs) )
		return FALSE;

	return TRUE;
}

// CLibAppFrm diagnostics

#ifdef _DEBUG
void CLibAppFrm::AssertValid() const
{
	CMDIChildWndEx::AssertValid();
}

void CLibAppFrm::Dump(CDumpContext& dc) const
{
	CMDIChildWndEx::Dump(dc);
}
#endif //_DEBUG

// CLibAppFrm message handlers

void CLibAppFrm::OnFilePrint()
{
	if (m_dockManager.IsPrintPreviewValid())
	{
		PostMessage(WM_COMMAND, AFX_ID_PREVIEW_PRINT);
	}
}

void CLibAppFrm::OnFilePrintPreview()
{
	if (m_dockManager.IsPrintPreviewValid())
	{
		PostMessage(WM_COMMAND, AFX_ID_PREVIEW_CLOSE);  // force Print Preview mode closed
	}
}

void CLibAppFrm::OnUpdateFilePrintPreview(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck(m_dockManager.IsPrintPreviewValid());
}
