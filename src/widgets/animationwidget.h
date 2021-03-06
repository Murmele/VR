/**************************************************************************
This file is part of JahshakaVR, VR Authoring Toolkit
http://www.jahshaka.com
Copyright (c) 2016  GPLv3 Jahshaka LLC <coders@jahshaka.com>

This is free software: you may copy, redistribute
and/or modify it under the terms of the GPLv3 License

For more information see the LICENSE file
*************************************************************************/

#ifndef ANIMATIONWIDGET_H
#define ANIMATIONWIDGET_H

#include <QWidget>
#include <QTime>
#include "ui_animationwidget.h"

class QWidget;
class QElapsedTimer;
class TimelineWidget;

class AnimationWidget : public QWidget
{
    Q_OBJECT
    SceneNode* node;
    QTimer* timer;
    //http://stackoverflow.com/questions/17571717/accessing-the-elapsed-seconds-of-a-qtimer
    QElapsedTimer* elapsedTimer;

    float startedTime;
    bool loopAnim;

    TimelineWidget* mainTimeline;

    QMenu* addMenu;
    QMenu* deleteMenu;
public:
    explicit AnimationWidget(QWidget *parent = 0);
    ~AnimationWidget();

    void setSceneNode(SceneNode* node);

    void setMainTimelineWidget(TimelineWidget* tl)
    {
        mainTimeline = tl;
    }

    void showHighlight()
    {
        if(node==nullptr)
            return;

        if(mainTimeline==nullptr)
            return;
        mainTimeline->showHighlight(node->animStartTime,node->animStartTime+node->animLength);
    }

    void hideHighlight()
    {
        if(node==nullptr)
            return;
        mainTimeline->hideHighlight();
    }

    void setAnimStartTime(int second)
    {
        if(node!=nullptr)
            node->setAnimStartTime(second);
    }

    void setAnimLength(float length)
    {
        //todo
        int scaleRatio = 30;
        ui->values->setGeometry(0,0,length*scaleRatio,ui->values->height());
        this->showHighlight();
    }

    void stopAnimation()
    {
        stopTimer();
    }

    void fixLayout()
    {
        ui->values->adjustSize();
        //ui->values->update();

        ui->timeControls->adjustSize();
        //ui->timeControls->update();
    }
    void repaintViews();
private:

    void removeNodeSpecificActions();

    //add actions
    QAction* addLightColorKeyAction;
    QAction* addLightIntensityKeyAction;
    QAction* addSceneBackgroundColorKeyAction;
    QAction* addSceneActiveCameraKeyAction;

    //deletion actions
    QAction* deleteLightColorKeysAction;
    QAction* deleteLightIntensityKeysAction;

public slots:
    void setLooping(bool loop)
    {
        loopAnim = loop;
        node->loopAnim = loop;
    }

private slots:
    void addPosKey();
    void addRotKey();
    void addScaleKey();
    void addPosRotKey();
    void addPosRotScaleKey();

    void addLightColorKey();
    void addLightIntensityKey();
    void deleteLightColorKeys();
    void deleteLightIntensityKeys();

    void addSceneBackgroundColorKey();
    void addSceneActiveCameraKey();

    void deletePosKeys();
    void deleteScaleKeys();
    void deleteRotKeys();
    void deleteAllKeys();

    void updateAnim();
    void startTimer();
    void stopTimer();

    void timeEditChanged(QTime);
    void setAnimLength(int lengthInSeconds)
    {
        node->animLength = lengthInSeconds;
        //ui->timeline->setMaxTimeInSeconds(lengthInSeconds);
        ui->timeline->setTimeRange(0,lengthInSeconds);
        //ui->keywidgetView->setMaxTimeInSeconds(lengthInSeconds);
        ui->keywidgetView->setTimeRange(0,lengthInSeconds);
        /*
        int scaleRatio = 30;
        ui->values->setGeometry(
                    ui->values->x(),
                    ui->values->y(),
                    lengthInSeconds*scaleRatio,
                    ui->values->height());
        ui->values->setMinimumWidth(lengthInSeconds*scaleRatio);
        */
        this->showHighlight();
    }
    void setAnimstart(int time);

private:
    float time;
    float timerSpeed;
    Ui::AnimationWidget *ui;
};

#endif // ANIMATIONWIDGET_H
