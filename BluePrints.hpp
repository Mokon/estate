/* Copyright (C) 2016 David 'Mokon' Bond,  All Rights Reserved */

#pragma once

namespace estate {

class BluePrints {

  public:

    BluePrints();

    virtual ~BluePrints() = default;

    BluePrints(const BluePrints&) = delete;

    BluePrints& operator=(const BluePrints&) = delete;

    BluePrints(const BluePrints&&) = delete;

    BluePrints& operator=(const BluePrints&&) = delete;

};

}
