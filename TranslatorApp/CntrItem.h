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

// CntrItem.h : interface of the CTranslatorAppCntrItem class
//

#pragma once

class CTranslatorAppDoc;
class CTranslatorAppView;

class CTranslatorAppCntrItem : public CRichEditCntrItem
{
	DECLARE_SERIAL(CTranslatorAppCntrItem)

// Constructors
public:
	CTranslatorAppCntrItem(REOBJECT* preo = nullptr, CTranslatorAppDoc* pContainer = nullptr);
		// Note: pContainer is allowed to be null to enable IMPLEMENT_SERIALIZE
		//  IMPLEMENT_SERIALIZE requires the class have a constructor with
		//  zero arguments.  Normally, OLE items are constructed with a
		//  non-null document pointer

// Attributes
public:
	CTranslatorAppDoc* GetDocument()
		{ return reinterpret_cast<CTranslatorAppDoc*>(CRichEditCntrItem::GetDocument()); }
	CTranslatorAppView* GetActiveView()
		{ return reinterpret_cast<CTranslatorAppView*>(CRichEditCntrItem::GetActiveView()); }

// Implementation
public:
	~CTranslatorAppCntrItem();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
};

