#pragma once
#include"VECTOR2.h"
class CREATURE
{
    int Img = 0;
    float Angle=0;
    float RotSpeed = 0;
    VECTOR2 Pos;
    VECTOR2 Vel;
    VECTOR2 Acc;
    float MaxSpeed=0;
    float MaxForce=0;
    float NearDistance=0;
public:
    void setPos(float x, float y);
    void setImg(int img);
    void setMaxSpeed(float maxSpeed);
    void setMaxForce(float maxForce);
    void setNearDistance(float nearDistance);
    void setRotSpeed(float rotSpeed);
    void seek(const VECTOR2& target);
    void chase(const VECTOR2& target);
    void runAway(const VECTOR2& target);
    void applyForce(const VECTOR2& force);
    void move();
    void edge();
    void draw();
    const VECTOR2& pos();
};

