//
//  wxmView.cpp
//  IMSign
//
//  Created by iMokhles on 09/11/2018.
//  Copyright © 2018 iMokhles. All rights reserved.
//

#include "wxmView.hpp"

#include <wx/grid.h>
#include <wx/clipbrd.h>
#include <wx/url.h>
#include <wx/stdpaths.h>
#include <wx/filename.h>
#include <wx/combo.h>
#include <wx/odcombo.h>
#include <wx/valgen.h>

#include "IMSHelper.hpp"

#define frameWidth 500
#define frameHeight 500


wxmView::wxmView()
: wxFrame(NULL, wxID_ANY, "IMSign")
{
    this->SetForegroundColour(wxColour(51,47,47));
    this->wxWindow::SetBackgroundColour(wxColour(51,47,47));
    this->SetSize(frameWidth, frameHeight);
    SetMinSize(GetSize());
    SetMaxSize(GetSize());
    
    // add bottom status bar
    CreateStatusBar();
    SetStatusText( "Status...!!!" );
    
    processMsg = GetStatusBar();
    certsArray = IMSHelper().getCertificates();
    profilesArray = IMSHelper().getProfiles();

    topSizer = new wxBoxSizer(wxVERTICAL);
    topSizer->SetMinSize(frameWidth, -1);
    this->SetSizer(topSizer);
    
    fontTmp = wxFont(17,wxFONTFAMILY_MODERN ,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD);
    
//    CERTS
    listCertsBox = new wxStaticBox(this, wxID_ANY, _("Certs"));
    listCertsBox->SetFont(fontTmp);
    listCertsBoxSizer = new wxStaticBoxSizer( listCertsBox, wxHORIZONTAL);

    int cert_selection_setting;
    
    topSizer->Add(listCertsBoxSizer, 0, wxALL|wxEXPAND, 1);
    
    chooseCertsBox = new wxChoice (this, wxID_ANY, wxPoint(298,57), wxSize(115,21), certsArray, 0, wxGenericValidator(&cert_selection_setting), wxT(""));

    listCertsBoxSizer->Add(chooseCertsBox, 1, wxALL, 1);
    
    
//    PROFILES
    listProfilesBox = new wxStaticBox(this, wxID_ANY, _("Profile"));
    listProfilesBox->SetFont(fontTmp);
    listProfilesBoxSizer = new wxStaticBoxSizer( listProfilesBox, wxHORIZONTAL);
    
    int profile_selection_setting;
    
    topSizer->Add(listProfilesBoxSizer, 0, wxALL|wxEXPAND, 1);
    
    chooseProfilesBox = new wxChoice (this, wxID_ANY, wxPoint(298,57), wxSize(115,21), profilesArray, 0, wxGenericValidator(&profile_selection_setting), wxT(""));
    
    listProfilesBoxSizer->Add(chooseProfilesBox, 1, wxALL, 1);
    
    buttonBox = new wxStaticBox(this, wxID_ANY, _("Process Button"));
    buttonBox->SetFont(fontTmp);
    buttonBoxSizer = new wxStaticBoxSizer( buttonBox, wxHORIZONTAL);
    
    buttonStart = new wxButton(this, BUTTON_Login, wxT("Start"));
    buttonBoxSizer->Add(buttonStart);
    
    
    topSizer->Add(buttonBoxSizer, 0, wxALIGN_RIGHT | wxTOP | wxRIGHT | wxBOTTOM, 10);
    
    // center application frame after opening it
    this->Center();
}

void wxmView::startTapped(wxCommandEvent& event)
{
    wxString certHash = certsArray[chooseCertsBox->GetCurrentSelection()];
    processMsg->PushStatusText("Selected Cert: "+certHash);
    
    
}
wxmView::~wxmView() {}

BEGIN_EVENT_TABLE(wxmView, wxFrame)
EVT_BUTTON(BUTTON_Login, wxmView::startTapped)
wxEND_EVENT_TABLE()
