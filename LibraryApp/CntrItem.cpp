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

// CntrItem.cpp : implementation of the CLibraryAppCntrItem class
//

#include "pch.h"
#include "framework.h"
#include "LibraryApp.h"

#include "LibraryAppDoc.h"
#include "LibraryAppView.h"
#include "CntrItem.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CLibraryAppCntrItem implementation

IMPLEMENT_SERIAL(CLibraryAppCntrItem, CRichEditCntrItem, 0)

CLibraryAppCntrItem::CLibraryAppCntrItem(REOBJECT* preo, CLibraryAppDoc* pContainer)
	: CRichEditCntrItem(preo, pContainer)
{
	// TODO: add one-time construction code here
}

CLibraryAppCntrItem::~CLibraryAppCntrItem()
{
	// TODO: add cleanup code here
}


// CLibraryAppCntrItem diagnostics

#ifdef _DEBUG
void CLibraryAppCntrItem::AssertValid() const
{
	CRichEditCntrItem::AssertValid();
}

void CLibraryAppCntrItem::Dump(CDumpContext& dc) const
{
	CRichEditCntrItem::Dump(dc);
}
#endif

