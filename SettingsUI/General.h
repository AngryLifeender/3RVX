#pragma once
#include "afxwin.h"
#include "../3RVX/Settings.h"


// General dialog

class General : public CPropertyPage
{
	DECLARE_DYNAMIC(General)

public:
    General(Settings *settings);
	virtual ~General();

// Dialog Data
	enum { IDD = IDD_GENERAL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
    virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()

private:
    Settings *_settings;

    CButton _startup;
    CButton _notify;
    CButton _sounds;
    CComboBox _lang;

    void LoadSettings();
    CStatic _skinGrp;
    CStatic _behaviorGrp;
    CStatic _languageGrp;
    CStatic _author;
};