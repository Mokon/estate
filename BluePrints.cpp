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
    addRoom(osg::Vec3f(), {1,1}, {2,1}, {1,1});
    addRoom(osg::Vec3f(), {2,1}, {1,1}, {1,1});
}

void
BluePrints::addRoom(const osg::Vec3& center, const Measurement& width,
                    const Measurement& length, const Measurement& height)
{
    auto geode = osg::make_ref<osg::Geode>();
    auto box = osg::make_ref<osg::Box>(center, width.getNormalized(),
                                       length.getNormalized(),
                                       height.getNormalized());
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
