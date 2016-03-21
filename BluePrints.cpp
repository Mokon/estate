/* Copyright (C) 2016 David 'Mokon' Bond,  All Rights Reserved */

#include "OsgExtensions.hpp"

#include "BluePrints.hpp"

#include <osgViewer/ViewerEventHandlers>
#include <osgGA/StateSetManipulator>
#include <osg/ShapeDrawable>

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
    auto myshapegeode = osg::make_ref<osg::Geode>();
    auto myCapsule = osg::make_ref<osg::Capsule>(osg::Vec3f(), 1, 2);
    auto capsuledrawable = osg::make_ref<osg::ShapeDrawable>(myCapsule.get());
    myshapegeode->addDrawable(capsuledrawable.get());
    root->addChild(myshapegeode.get());
}

int
BluePrints::run()
{
    return viewer.run();
}

}

int
main()
{
    estate::BluePrints estate;
    estate.sketch();

    return estate.run();
}
