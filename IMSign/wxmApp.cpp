//
//  wxmApp.cpp
//  IMSign
//
//  Created by iMokhles on 09/11/2018.
//  Copyright © 2018 iMokhles. All rights reserved.
//

#include "wxmApp.hpp"
#include "wxmView.hpp"


bool wxmApp::OnInit() {
    auto frame = new wxmView;
    frame->Show(true);
    return true;
}
