/* Copyright (C) 2016 David 'Mokon' Bond,  All Rights Reserved */

#pragma once

namespace estate {

using Feet = unsigned int;
using Inches = unsigned int;

class Measurement {

  public:

    Measurement() = delete;

    Measurement(Feet feet, Inches inches)
        : normalized(feet*12 + inches)
    {
    }

    virtual ~Measurement() = default;

    Measurement(const Measurement&) = delete;

    Measurement& operator=(const Measurement&) = delete;

    Measurement(const Measurement&&) = delete;

    Measurement& operator=(const Measurement&&) = delete;

    auto
    getNormalized() const
    {
        return normalized;
    }

  private:

    const float normalized;

};

}
