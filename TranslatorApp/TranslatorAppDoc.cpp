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

// TranslatorAppDoc.cpp : implementation of the CTranslatorAppDoc class
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

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CTranslatorAppDoc

IMPLEMENT_DYNCREATE(CTranslatorAppDoc, CRichEditDoc)

BEGIN_MESSAGE_MAP(CTranslatorAppDoc, CRichEditDoc)
	// Enable default OLE container implementation
	ON_UPDATE_COMMAND_UI(ID_OLE_EDIT_LINKS, &CRichEditDoc::OnUpdateEditLinksMenu)
	ON_UPDATE_COMMAND_UI(ID_OLE_VERB_POPUP, &CTranslatorAppDoc::OnUpdateObjectVerbPopup)
	ON_COMMAND(ID_OLE_EDIT_LINKS, &CRichEditDoc::OnEditLinks)
	ON_UPDATE_COMMAND_UI_RANGE(ID_OLE_VERB_FIRST, ID_OLE_VERB_LAST, &CRichEditDoc::OnUpdateObjectVerbMenu)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CTranslatorAppDoc, CRichEditDoc)
END_DISPATCH_MAP()

// Note: we add support for IID_ITranslatorApp to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the
//  dispinterface in the .IDL file.

// {c12c631b-c693-4b2d-a33d-179da1c7cfe5}
static const IID IID_ITranslatorApp =
{0xc12c631b,0xc693,0x4b2d,{0xa3,0x3d,0x17,0x9d,0xa1,0xc7,0xcf,0xe5}};

BEGIN_INTERFACE_MAP(CTranslatorAppDoc, CRichEditDoc)
	INTERFACE_PART(CTranslatorAppDoc, IID_ITranslatorApp, Dispatch)
END_INTERFACE_MAP()


// CTranslatorAppDoc construction/destruction

CTranslatorAppDoc::CTranslatorAppDoc() noexcept
{
	// Use OLE compound files
	EnableCompoundFile();

	// TODO: add one-time construction code here

	EnableAutomation();

	AfxOleLockApp();
}

CTranslatorAppDoc::~CTranslatorAppDoc()
{
	AfxOleUnlockApp();
}

BOOL CTranslatorAppDoc::OnNewDocument()
{
	if (!CRichEditDoc::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}

CRichEditCntrItem* CTranslatorAppDoc::CreateClientItem(REOBJECT* preo) const
{
	return new CTranslatorAppCntrItem(preo, const_cast<CTranslatorAppDoc*>(this));
}




// CTranslatorAppDoc serialization

void CTranslatorAppDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}

	// Calling the base class CRichEditDoc enables serialization
	//  of the container document's COleClientItem objects.
	// TODO: set CRichEditDoc::m_bRTF = FALSE if you are serializing as text
	CRichEditDoc::Serialize(ar);
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CTranslatorAppDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modify this code to draw the document's data
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Support for Search Handlers
void CTranslatorAppDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data.
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CTranslatorAppDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CTranslatorAppDoc diagnostics

#ifdef _DEBUG
void CTranslatorAppDoc::AssertValid() const
{
	CRichEditDoc::AssertValid();
}

void CTranslatorAppDoc::Dump(CDumpContext& dc) const
{
	CRichEditDoc::Dump(dc);
}
#endif //_DEBUG


// CTranslatorAppDoc commands
