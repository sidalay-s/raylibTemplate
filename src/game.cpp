#include "headers/game.hpp"
#include <assert.h>
#include <vector>

void Game::Run() 
{

    // Initialization ---------------------------
    Window Window {1280, 720};                      // Window Dimensions
    int FPS {144};                                  // Frames Per Second
    Game::Initialize(Window, FPS, "Template");      // Create Window


    // Start Game Loop
    while (!WindowShouldClose()) 
    {
        Game::Tick(Window);
    }

    // Clean-up
    assert(GetWindowHandle());
    CloseWindow();
}

// Set the Game's window configurations
void Game::Initialize(Window& Window, int FPS, std::string Title)
{
    assert(!GetWindowHandle());
    SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);
    InitWindow(Window.x, Window.y, Title.c_str());
    SetTargetFPS(FPS);
    SetExitKey(0);
}

void Game::Tick(Window& Window)
{
    // Check if Window has been resized or fullscreened
    Game::CheckScreenSizing(Window);

    // Begin Drawing
    BeginDrawing();
    ClearBackground(BLACK);

    // Tick Functions called here
    Game::Update();
    Game::Draw();

    // End Drawing
    EndDrawing();
}

void Game::CheckScreenSizing(Window& Window)
{
    // set window.x / window.y to resized dimensions
    if (IsWindowResized()) 
    {
        Window.x = GetScreenWidth();
        Window.y = GetScreenHeight();
    }

    // check for alt + enter [FULLSCREEN]
    if (IsKeyPressed(KEY_ENTER) && (IsKeyDown(KEY_RIGHT_ALT) || IsKeyDown(KEY_LEFT_ALT)))
    {
        SetFullScreen(Window);
    }
}

void Game::SetFullScreen(Window& Window)
{
    // see what display we are on right now
    int display = GetCurrentMonitor();

    if (IsWindowFullscreen()) 
    {
        // if we are full screen, then go back to the windowed size
        ToggleFullscreen();                  
        SetWindowSize(Window.x, Window.y); 
    }
    else
    {                                        
        // if we are not full screen, set the window size to match the monitor we are on
        SetWindowSize(GetMonitorWidth(display), GetMonitorHeight(display));
        ToggleFullscreen();
    }
}


void Game::Update()
{

}

void Game::Draw()
{

}

