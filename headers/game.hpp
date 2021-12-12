#ifndef GAME_HPP
#define GAME_HPP

#include <raylib.h>
#include <string>
#include "headers/window.hpp"

enum class GameState 
{
    MAINMENU, RUNNING, PAUSED, GAMEOVER
};

namespace Game 
{
    void Run();
    void Initialize(Window& Window, int FPS, std::string Title);
    void Tick(Window& Window);
    void CheckScreenSizing(Window& Window);
    void SetFullScreen(Window& Window);
    void Update();
    void Draw();
}

#endif