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

// CntrItem.cpp : implementation of the CTranslatorAppCntrItem class
//

#include "pch.h"
#include "framework.h"
#include "TranslatorApp.h"

#include "TranslatorAppDoc.h"
#include "TranslatorAppView.h"
#include "CntrItem.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTranslatorAppCntrItem implementation

IMPLEMENT_SERIAL(CTranslatorAppCntrItem, CRichEditCntrItem, 0)

CTranslatorAppCntrItem::CTranslatorAppCntrItem(REOBJECT* preo, CTranslatorAppDoc* pContainer)
	: CRichEditCntrItem(preo, pContainer)
{
	// TODO: add one-time construction code here
}

CTranslatorAppCntrItem::~CTranslatorAppCntrItem()
{
	// TODO: add cleanup code here
}


// CTranslatorAppCntrItem diagnostics

#ifdef _DEBUG
void CTranslatorAppCntrItem::AssertValid() const
{
	CRichEditCntrItem::AssertValid();
}

void CTranslatorAppCntrItem::Dump(CDumpContext& dc) const
{
	CRichEditCntrItem::Dump(dc);
}
#endif

