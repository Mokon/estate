/* Copyright (C) 2016 David 'Mokon' Bond,  All Rights Reserved */

#pragma once

#include "Measurement.hpp"
#include <osgViewer/Viewer>

namespace estate {

class BluePrints {

  public:

    BluePrints();

    virtual ~BluePrints() = default;

    BluePrints(const BluePrints&) = delete;

    BluePrints& operator=(const BluePrints&) = delete;

    BluePrints(const BluePrints&&) = delete;

    BluePrints& operator=(const BluePrints&&) = delete;
    
    int run();

    void sketch();

    void addRoom(const osg::Vec3& center, const Measurement& width,
                 const Measurement& length, const Measurement& height);

  private:

    void initSceneGraph();
       
    osgViewer::Viewer viewer ;
    
    osg::ref_ptr<osg::Group> root;

};

}
