/* Copyright (C) 2016 David 'Mokon' Bond,  All Rights Reserved */

#pragma once

#include <osgViewer/Viewer>

namespace osg {

template<class T, class... Args>
osg::ref_ptr<T> make_ref(Args&&... args)
{
    return new T(std::forward<Args>(args)...);
}

}
