//
//  wxmView.hpp
//  IMSign
//
//  Created by iMokhles on 09/11/2018.
//  Copyright © 2018 iMokhles. All rights reserved.
//

#include <wx/wx.h>

class wxmView : public wxFrame {
public:
    wxmView();
    virtual ~wxmView();
protected:
    // top box
    wxBoxSizer* topSizer;
    
    // custom font
    wxFont fontTmp;
        
    wxArrayString certsArray;
    wxStaticBox* listCertsBox;
    wxStaticBoxSizer* listCertsBoxSizer;
    wxChoice *chooseCertsBox;
    
    wxArrayString profilesArray;
    wxStaticBox* listProfilesBox;
    wxStaticBoxSizer* listProfilesBoxSizer;
    wxChoice *chooseProfilesBox;
    
    // login button
    wxStaticBoxSizer* buttonBoxSizer;
    wxStaticBox* buttonBox;
    wxButton* buttonStart;
    
    // status alert
    wxStatusBar *processMsg;
private:
    void startTapped(wxCommandEvent& event);
    
private:
    DECLARE_EVENT_TABLE()
    
    enum
    {
        BUTTON_Login = wxID_HIGHEST + 1
    };
};
