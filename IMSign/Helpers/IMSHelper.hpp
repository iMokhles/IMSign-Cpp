//
//  IMSHelper.hpp
//  IMSign
//
//  Created by iMokhles on 09/11/2018.
//  Copyright © 2018 iMokhles. All rights reserved.
//

#ifndef IMSHelper_hpp
#define IMSHelper_hpp

#include <stdio.h>
#include <string>
#include <wx/wx.h>
#include <wx/dir.h>
#include <wx/stdpaths.h>

using namespace std;

class IMSHelper
{
public:
    IMSHelper(void);
    ~IMSHelper(void);
    
public:
    void ExecuteCommand(const wxString &command, wxArrayString &output);
    wxArrayString getCertificates();
    wxArrayString getProfiles();

};


#endif /* IMSHelper_hpp */
