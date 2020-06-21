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

// TranslatorAppView.h : interface of the CTranslatorAppView class
//

#pragma once

class CTranslatorAppCntrItem;

class CTranslatorAppView : public CRichEditView
{
protected: // create from serialization only
	CTranslatorAppView() noexcept;
	DECLARE_DYNCREATE(CTranslatorAppView)

// Attributes
public:
	CTranslatorAppDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CTranslatorAppView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnDestroy();
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in TranslatorAppView.cpp
inline CTranslatorAppDoc* CTranslatorAppView::GetDocument() const
   { return reinterpret_cast<CTranslatorAppDoc*>(m_pDocument); }
#endif

