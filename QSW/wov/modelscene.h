#ifndef MODEL_SCENE_H
#define MODEL_SCENE_H

#include <QOpenGLWidget>
#include <QElapsedTimer>
#include <QOpenGLFunctions>

#include "mvp.h"

class QOpenGLShaderProgram;
class QOpenGLBuffer;

class Model;
class CameraShake;

Q_MOC_INCLUDE("../QSW/wov/model.h")

class ModelScene : public QOpenGLWidget
{
    Q_OBJECT
    Q_PROPERTY(float rotationX READ rotationX WRITE setRotationX)
    Q_PROPERTY(float rotationY READ rotationY WRITE setRotationY)
    Q_PROPERTY(float distance READ distance WRITE setDistance)
    Q_PROPERTY(Model * selectedModel READ selectedModel)
    Q_PROPERTY(float worldX READ worldX)
    Q_PROPERTY(float worldY READ worldY)
    Q_PROPERTY(float worldZ READ worldZ)

public:
    ModelScene(QWidget *parent = 0);

    void setRotationX(float rotation);
    void setRotationY(float rotation);
    void setDistance(float distance);

    float rotationX() const;
    float rotationY() const;
    float distance() const;

    Model * selectedModel();

    float worldX() const;
    float worldY() const;
    float worldZ() const;

    Q_INVOKABLE void addModel(Model *model);
    Q_INVOKABLE void removeModel(Model *model);

    void addCameraShake(quint32 id);

signals:
    void mousePressed(QMouseEvent *event);
    void mouseReleased(QMouseEvent *event);
    void mouseMoved(QMouseEvent *event);
    void wheelRotated(QWheelEvent *event);

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);

    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent *event);

private slots:
    void updateScene();

private:
    void renderGrid(int size, float step, MVP mvp);
    void updateMouseCoordinates(MVP mvp);

    QList<Model *> m_models;

    QElapsedTimer m_time;
    float m_rotationX;
    float m_rotationY;
    float m_distance;

    QList<CameraShake *> m_shakes;
    QVector3D m_shake;

    int m_mouseX, m_mouseY;
    int m_selection;

    float m_worldX, m_worldY, m_worldZ;

    QOpenGLShaderProgram *m_program;
    QOpenGLShaderProgram *m_particleProgram;

    QOpenGLBuffer *m_gridBuffer;

    QOpenGLFunctions* m_funcs;
};

#endif
