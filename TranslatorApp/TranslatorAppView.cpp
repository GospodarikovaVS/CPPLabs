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

// TranslatorAppView.cpp : implementation of the CTranslatorAppView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "TranslatorApp.h"
#endif

#include "TranslatorAppDoc.h"
#include "CntrItem.h"
#include "resource.h"
#include "TranslatorAppView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTranslatorAppView

IMPLEMENT_DYNCREATE(CTranslatorAppView, CRichEditView)

BEGIN_MESSAGE_MAP(CTranslatorAppView, CRichEditView)
	ON_WM_DESTROY()
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CRichEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CRichEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CTranslatorAppView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CTranslatorAppView construction/destruction

CTranslatorAppView::CTranslatorAppView() noexcept
{
	// TODO: add construction code here

}

CTranslatorAppView::~CTranslatorAppView()
{
}

BOOL CTranslatorAppView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CRichEditView::PreCreateWindow(cs);
}

void CTranslatorAppView::OnInitialUpdate()
{
	CRichEditView::OnInitialUpdate();


	// Set the printing margins (720 twips = 1/2 inch)
	SetMargins(CRect(720, 720, 720, 720));
}


// CTranslatorAppView printing


void CTranslatorAppView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CTranslatorAppView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}


void CTranslatorAppView::OnDestroy()
{
	// Deactivate the item on destruction; this is important
	// when a splitter view is being used
   COleClientItem* pActiveItem = GetDocument()->GetInPlaceActiveItem(this);
   if (pActiveItem != nullptr && pActiveItem->GetActiveView() == this)
   {
      pActiveItem->Deactivate();
      ASSERT(GetDocument()->GetInPlaceActiveItem(this) == nullptr);
   }
   CRichEditView::OnDestroy();
}


void CTranslatorAppView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CTranslatorAppView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CTranslatorAppView diagnostics

#ifdef _DEBUG
void CTranslatorAppView::AssertValid() const
{
	CRichEditView::AssertValid();
}

void CTranslatorAppView::Dump(CDumpContext& dc) const
{
	CRichEditView::Dump(dc);
}

CTranslatorAppDoc* CTranslatorAppView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTranslatorAppDoc)));
	return (CTranslatorAppDoc*)m_pDocument;
}
#endif //_DEBUG


// CTranslatorAppView message handlers
