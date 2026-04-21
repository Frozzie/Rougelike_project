#pragma once

#include "Floor.h"
#include "Music.h"
#include "Player.h"
#include "Roamer.h"
#include "Scene.h"
#include "Wall.h"
#include <array>
#include <iostream>

using namespace XYZEngine;

namespace XYZRoguelike
{
class DeveloperLevel : public Scene
{
  public:
    virtual void Start() = 0;

    void Restart()
    {
        Stop();
        Start();
    }
    void Stop()
    {
        GameWorld::Instance()->Clear();
    }
    std::shared_ptr<Player> GetPlayer()
    {
		return player;
    }


    std::vector<std::unique_ptr<Wall>> walls;
    std::vector<std::unique_ptr<Floor>> floors;
    std::vector<std::unique_ptr<Roamer>> roamers;
    std::shared_ptr<Player> player;
    std::unique_ptr<Music> music;
    
    //std::shared_ptr<Roamers> roamers; // needs to be shared_ptr
    //Roamers* roamers;

    //DeveloperLevel()
    //{
    //    volatile int i = 1;
    //    i++;
    //    
    //    roamers = new Roamers;
    //    //roamers = std::shared_ptr<Roamers>(new Roamers); //Source of error
    //}

  private:

};
} // namespace XYZRoguelike
