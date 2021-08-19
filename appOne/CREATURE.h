#pragma once
#include"libOne.h"
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
    void setImg(int img){
        Img = img;
    }
    void setPos(float x, float y){
        Pos.x = x;
        Pos.y = y;
    }
    void setMaxSpeed(float maxSpeed){
        MaxSpeed = maxSpeed;
    }
    void setMaxForce(float maxForce){
        MaxForce = maxForce;
    }
    void setNearDistance(float nearDistance){
        NearDistance = nearDistance;
    }
    void setRotSpeed(float rotSpeed){
        RotSpeed = rotSpeed;
    }
    void seek(const VECTOR2& target) {
        VECTOR2 acc = target - Pos;
        acc.setMag(MaxSpeed);
        //VelをtargetにMaxForceだけ向けるような加速度を求める
        acc -= Vel;
        acc.limmit(MaxForce);
        applyForce(acc);
    }
    void chase(const VECTOR2& target) {
        VECTOR2 acc = target - Pos;
        //ターゲットに近づいたら加速度を減速
        float distance = acc.mag();
        float speed = MaxSpeed;
        if (distance < NearDistance) {
            speed = map(distance, 0, NearDistance, 0, MaxSpeed);
        }
        acc.setMag(speed);
        //VelをtargetにMaxForceだけ向けるような加速度を求める
        acc -= Vel;
        acc.limmit(MaxForce);
        applyForce(acc);
    }
    void runAway(const VECTOR2& target){
        VECTOR2 acc = Pos - target;
        if (acc.mag() < NearDistance) {
            acc.setMag(MaxSpeed);
            //VelをtargetにMaxForceだけ向けるような加速度を求める
            acc -= Vel;
            acc.limmit(MaxForce);
            applyForce(acc);
        }
    }
    void applyForce(const VECTOR2& force){
        Acc += force;
    }
    void move(){
        Vel += Acc;
        Vel.limmit(MaxSpeed);
        Pos += Vel;
        Acc *= 0;

        //進む方向にゆるりと回転させる
        if (Vel.sqMag() > 0.00002f) {
            VECTOR2 v(sin(Angle), -cos(Angle));
            Angle += atan2(v.cross(Vel), v.dot(Vel)) * RotSpeed;
        }
    }
    void edge(){
        if (Pos.x < -50)Pos.x = width + 50;
        if (Pos.x > width + 50)Pos.x = -50;
        if (Pos.y < -50)Pos.y = height + 50;
        if (Pos.y > height + 50)Pos.y = -50;
    }
    void draw(){
        rectMode(CENTER);
        image(Img, Pos.x, Pos.y, Angle);
    }
    const VECTOR2& pos(){
        return Pos;
    }
};

