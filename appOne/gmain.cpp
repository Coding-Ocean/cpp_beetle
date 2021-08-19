#include"CREATURE.h"
void gmain() {
    window(1920, 1080, full);
    hideCursor();
    CREATURE osu, mesu, karasu;
    osu.setImg(loadImage("assets\\osu.png"));
    osu.setPos(width / 2, height);
    mesu.setImg(loadImage("assets\\mesu.png"));
    mesu.setPos(width / 2, height / 2);
    karasu.setImg(loadImage("assets\\karasu.png"));
    karasu.setPos(-400, -400);
    while (notQuit) {
        clear(130,170,255);

        osu.setMaxSpeed(15);
        osu.setMaxForce(1.5f);
        osu.setNearDistance(100);
        osu.chase(mesu.pos());
        osu.setNearDistance(200);
        osu.runAway(karasu.pos());
        osu.setRotSpeed(0.25f);
        osu.move();

        mesu.setMaxSpeed(15);
        mesu.setMaxForce(1.5f);
        mesu.setNearDistance(100);
        mesu.chase(VECTOR2(width/2,height/2));
        mesu.setNearDistance(200);
        mesu.runAway(karasu.pos());
        mesu.setRotSpeed(0.25f);
        mesu.move();
        mesu.edge();

        karasu.setMaxSpeed(5);
        karasu.setMaxForce(0.5f);
        karasu.setNearDistance(50);
        karasu.setRotSpeed(0.08f);
        float ofsX = random(-30.0f, 30.0f);
        float ofsY = random(-30.0f, 30.0f);
        karasu.seek(osu.pos()+VECTOR2(ofsX,ofsY));
        karasu.move();

        mesu.draw();
        osu.draw();
        karasu.draw();
    }
}
