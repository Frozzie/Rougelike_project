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
    virtual void Start();
    void Restart() override;
    void Stop() override;

    std::vector<std::unique_ptr<Wall>> walls;
    std::vector<std::unique_ptr<Floor>> floors;
    std::vector<std::unique_ptr<Roamer>> roamers;
    
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
    
    std::shared_ptr<Player> player;
    std::unique_ptr<Music> music;
};
} // namespace XYZRoguelike
