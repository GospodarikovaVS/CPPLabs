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

// TrnAppFrm.cpp : implementation of the CTrnAppFrm class
//

#include "pch.h"
#include "framework.h"
#include "TranslatorApp.h"

#include "TrnAppFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CTrnAppFrm

IMPLEMENT_DYNCREATE(CTrnAppFrm, CMDIChildWndEx)

BEGIN_MESSAGE_MAP(CTrnAppFrm, CMDIChildWndEx)
	ON_COMMAND(ID_FILE_PRINT, &CTrnAppFrm::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CTrnAppFrm::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CTrnAppFrm::OnFilePrintPreview)
	ON_UPDATE_COMMAND_UI(ID_FILE_PRINT_PREVIEW, &CTrnAppFrm::OnUpdateFilePrintPreview)
END_MESSAGE_MAP()

// CTrnAppFrm construction/destruction

CTrnAppFrm::CTrnAppFrm() noexcept
{
	// TODO: add member initialization code here
}

CTrnAppFrm::~CTrnAppFrm()
{
}


BOOL CTrnAppFrm::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying the CREATESTRUCT cs
	if( !CMDIChildWndEx::PreCreateWindow(cs) )
		return FALSE;

	return TRUE;
}

// CTrnAppFrm diagnostics

#ifdef _DEBUG
void CTrnAppFrm::AssertValid() const
{
	CMDIChildWndEx::AssertValid();
}

void CTrnAppFrm::Dump(CDumpContext& dc) const
{
	CMDIChildWndEx::Dump(dc);
}
#endif //_DEBUG

// CTrnAppFrm message handlers

void CTrnAppFrm::OnFilePrint()
{
	if (m_dockManager.IsPrintPreviewValid())
	{
		PostMessage(WM_COMMAND, AFX_ID_PREVIEW_PRINT);
	}
}

void CTrnAppFrm::OnFilePrintPreview()
{
	if (m_dockManager.IsPrintPreviewValid())
	{
		PostMessage(WM_COMMAND, AFX_ID_PREVIEW_CLOSE);  // force Print Preview mode closed
	}
}

void CTrnAppFrm::OnUpdateFilePrintPreview(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck(m_dockManager.IsPrintPreviewValid());
}
