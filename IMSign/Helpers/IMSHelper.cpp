//
//  IMSHelper.cpp
//  IMSign
//
//  Created by iMokhles on 09/11/2018.
//  Copyright © 2018 iMokhles. All rights reserved.
//

#include "IMSHelper.hpp"

IMSHelper::IMSHelper(void)
{
    
}

IMSHelper::~IMSHelper(void)
{
    
}

void IMSHelper::ExecuteCommand(const wxString &command, wxArrayString &output)
{
#ifdef __WXMSW__
    wxExecute(command, output);
#elif __WXMAC__
    FILE *fp;
    char line[512];
    memset(line, 0, sizeof(line));
    fp = popen(command.mb_str(wxConvUTF8), "r");
    while ( fgets( line, sizeof line, fp)) {
        output.Add(wxString(line, wxConvUTF8));
        memset(line, 0, sizeof(line));
    }
    
    pclose(fp);
#endif
}

wxArrayString IMSHelper::getCertificates() {
    
    wxArrayString errors, output, retValue;
    wxString cmdMac = wxString::Format("/usr/bin/security find-identity -v -p codesigning");
#ifdef __WXMSW__
    IMSHelper().ExecuteCommand(cmdMac, output);
#elif __WXMAC__
    IMSHelper().ExecuteCommand(cmdMac, output);
    if(output.Count()>0 && errors.Count()==0) {
        for( int a = 0; a < output.Count()-1; a++ ) {
            
            // check if Distribution or Developer ( Name )
            wxString certNameFull = output.Item(a).ToStdString();
            wxString certHash = "";
            
            // i know that i could do it better than that ( but i'm lazy )
            wxUniChar certCar = ':';
            wxString certName = certNameFull.AfterFirst(certCar);
            certCar = '"';
            certName = certName.BeforeFirst(certCar);
            if (certNameFull.find("Distribution") == wxNOT_FOUND) {
                certName = wxString::Format("iPhone Developer:%s", certName);
            } else {
                certName = wxString::Format("iPhone Distribution:%s", certName);
            }
            
            certHash = certNameFull.substr(0, certNameFull.find(" \"iPhone"));
            certHash = certHash.substr(5, certHash.find_last_not_of(") "));
            
            printf("NAME: %s\n", certName.ToStdString().c_str());
            printf("HASH: %s\n", certHash.ToStdString().c_str());
            
            retValue.Add(certHash);
        }
    }
    
#endif
    
    return retValue;
}

wxArrayString IMSHelper::getProfiles() {
    
    wxArrayString profileNames;
    size_t pfs = -1;
    wxString homeFolder = ::wxGetUserHome();
    
    pfs = wxDir::GetAllFiles(wxString::Format("%s/Library/MobileDevice/Provisioning Profiles", homeFolder.ToStdString().c_str()), &profileNames, _T("*.mobileprovision"));
    
    if (profileNames.GetCount() > 0) {
        return profileNames;
    }
    return wxArrayString();
}

