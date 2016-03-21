/* Copyright (C) 2016 David 'Mokon' Bond,  All Rights Reserved */

#include "BluePrints.hpp"
#include "OsgExtensions.hpp"
#include <osg/PolygonMode>
#include <osg/ShapeDrawable>
#include <osg/Shape>
#include <osgViewer/ViewerEventHandlers>

namespace estate {

BluePrints::BluePrints()
{
    initSceneGraph();
}

void
BluePrints::initSceneGraph()
{
    root = osg::make_ref<osg::Group>();
    viewer.setSceneData(root.get());
    viewer.setThreadingModel(osgViewer::Viewer::ThreadingModel::SingleThreaded);
    viewer.addEventHandler(osg::make_ref<osgViewer::WindowSizeHandler>());
}

void
BluePrints::sketch()
{
    #include "Sketch.hpp"
}

void
BluePrints::addRoom(const std::string& name,
                    const osg::Vec3& floorFrontLeft, const Measurement& width,
                    const Measurement& length, const Measurement& height)
{
    (void)name;
    // TODO add vec3 using measurements
    auto y = width.getNormalized();
    auto x = length.getNormalized();
    auto z = height.getNormalized();
    auto center = osg::Vec3(floorFrontLeft.y()*12 + x/2.0f,
                            floorFrontLeft.x()*12 + y/2.0f,
                            floorFrontLeft.z()*12 + z/2.0f);
    auto geode = osg::make_ref<osg::Geode>();
    auto box = osg::make_ref<osg::Box>(center, x, y, z);
    auto drawable = osg::make_ref<osg::ShapeDrawable>(box.get());
    geode->addDrawable(drawable.get());

    auto stateset = osg::make_ref<osg::StateSet>();
    auto polymode = osg::make_ref<osg::PolygonMode>();
    polymode->setMode(osg::PolygonMode::FRONT_AND_BACK,osg::PolygonMode::LINE);
    stateset->setAttributeAndModes(polymode,
                                   osg::StateAttribute::OVERRIDE|
                                    osg::StateAttribute::ON);

    geode->setStateSet(stateset.get());
    root->addChild(geode.get());
}

int
BluePrints::run()
{
    return viewer.run();
}

}
