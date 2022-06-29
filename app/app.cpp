//
// Created by tanawin on 28/6/65.
//

#include "app.h"

netBench::app::APP::APP(netBench::app::APPID appId) : appId(appId) {}

netBench::app::APPID
netBench::app::APP::getAppId() const {
    return appId;
}
