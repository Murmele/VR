/**************************************************************************
This file is part of JahshakaVR, VR Authoring Toolkit
http://www.jahshaka.com
Copyright (c) 2016  GPLv3 Jahshaka LLC <coders@jahshaka.com>

This is free software: you may copy, redistribute
and/or modify it under the terms of the GPLv3 License

For more information see the LICENSE file
*************************************************************************/

#ifndef REFRACTIVEMATERIAL_H
#define REFRACTIVEMATERIAL_H

class RefractiveEffect:public Qt3DRender::QEffect
{
public:
    RefractiveEffect();

    Qt3DRender::QTechnique *tech;
};

class RefractiveMaterial:public Qt3DRender::QMaterial
{
    Qt3DRender::QAbstractTexture* texture;
    Qt3DRender::QAbstractTexture* normalTexture;
    Qt3DRender::QParameter* texParam;
    Qt3DRender::QParameter* normalTexParam;
    Qt3DRender::QParameter* iorParam;
public:
    RefractiveMaterial();
    void setTexture(Qt3DRender::QAbstractTexture* tex);
    void setTexture(Qt3DRender::QAbstractTextureImage* tex);
    void setNormalTexture(Qt3DRender::QAbstractTextureImage* tex);

    Qt3DRender::QAbstractTexture* getTexture()
    {
        return texture;
    }

    Qt3DRender::QAbstractTexture* getNormalTexture()
    {
        return normalTexture;
    }

    void setIoR(float ior);
    float getIoR();
};

#endif // REFRACTIVEMATERIAL_H
