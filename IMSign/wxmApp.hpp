//
//  wxmApp.hpp
//  IMSign
//
//  Created by iMokhles on 09/11/2018.
//  Copyright © 2018 iMokhles. All rights reserved.
//

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif


class wxmApp: public wxApp
{
public:
    virtual bool OnInit() override;
};
