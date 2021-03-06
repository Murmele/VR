/**************************************************************************
This file is part of JahshakaVR, VR Authoring Toolkit
http://www.jahshaka.com
Copyright (c) 2016  GPLv3 Jahshaka LLC <coders@jahshaka.com>

This is free software: you may copy, redistribute
and/or modify it under the terms of the GPLv3 License

For more information see the LICENSE file
*************************************************************************/

#ifndef SCENE_H
#define SCENE_H

#include <qwindow.h>
#include <qsurface.h>
#include <Qt3DRender/qcamera.h>
#include <Qt3DCore/qentity.h>
#include <Qt3DRender/qcameralens.h>

#include <Qt3DInput/QInputAspect>

#include <Qt3DExtras/qtorusmesh.h>
#include <Qt3DRender/qmesh.h>
#include <Qt3DRender/qtechnique.h>
#include <Qt3DRender/qmaterial.h>
#include <Qt3DRender/qeffect.h>
#include <Qt3DRender/qtexture.h>
#include <Qt3DRender/qrenderpass.h>
#include <Qt3DRender/qsceneloader.h>

#include <Qt3DCore/qtransform.h>
#include <Qt3DCore/qaspectengine.h>

#include <Qt3DRender/qrenderaspect.h>
//#include <Qt3DCore/qframegraph.h>
#include <Qt3DExtras/qforwardrenderer.h>

//Meshes and Material
#include <Qt3DExtras/QTorusMesh>
#include <Qt3DExtras/QCylinderMesh>
#include <Qt3DExtras/QCuboidMesh>
#include <Qt3DExtras/QSphereMesh>
#include <Qt3DExtras/QPhongMaterial>

#include <QOpenGLContext>
#include <qstandarditemmodel.h>
//#include <QNodeList>

#include <QVector3D>

class SceneNode;
class NodeKeyFrameAnimation;
class NodeKeyFrame;
class EndlessPlaneNode;
class JahRenderer;

namespace Qt3DCore
{
    class QEntity;
}

namespace Qt3DExtras
{
    class QSkyboxEntity;
    class QForwardRenderer;
}

class SceneManager
{

private:
    SceneNode* rootNode;
    Qt3DExtras::QSkyboxEntity* sky;
    //Qt3DExtras::QForwardRenderer* renderer;
    //EndlessPlaneNode* ground;
    JahRenderer* renderer;

    //fog properties
    float fogStart;
    float fogEnd;
    QColor fogColor;
    bool fogEnabled;

public:
    QColor bgColor;
    //explicit SceneManager(Qt3DCore::QAspectEngine* engine);
    explicit SceneManager(Qt3DCore::QEntity* rootEntity);
    void setCamera(Qt3DRender::QCamera* cam);
    SceneNode* getRootNode();

    //void setRenderer(Qt3DExtras::QForwardRenderer* renderer);
    //Qt3DExtras::QForwardRenderer* getRenderer();

    void setRenderer(JahRenderer* renderer);
    JahRenderer* getRenderer();

    void setRootNode(SceneNode* root);
    void createFakeSky();
    EndlessPlaneNode* getGround();
    static SceneManager* createDefaultMatrixScene(Qt3DCore::QEntity* rootEntity);
    static SceneManager* createDefaultGridScene(Qt3DCore::QEntity* rootEntity);

    void setSkyBoxTextures(QString path,QString extension);
    void clearSky();

    /**
     * @brief recursively updates fog params for all scene nodes
     * @param color
     * @param start
     * @param end
     */
    void updateFogParams(bool enabled, QColor color,float start,float end);
    void updateFogParams();

    float getFogStart();
    float getFogEnd();
    QColor getFogColor();
    bool getFogEnabled();

    void setFogStart(float fogStart);
    void setFogEnd(float fogEnd);
    void setFogColor(QColor color);
    void setFogEnabled(bool enabled);

private:
    void initSky();
};

#endif // SCENE_H
