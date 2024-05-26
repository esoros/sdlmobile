#include <SDL2/SDL.h>
#include <stdio.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

int main() {
  SDL_Window* window = NULL;
  SDL_Renderer* renderer = NULL;
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    fprintf(stderr, "could not initialize sdl2: %s\n", SDL_GetError());
    return 1;
  }

  SDL_CreateWindowAndRenderer(680, 480, SDL_WINDOW_RESIZABLE, &window, &renderer);
  if(window == NULL) {
    fprintf(stderr, "could not create window: %s\n", SDL_GetError());
    return 1;
  }
  
  SDL_Rect rect;
  rect.x = 10; rect.y = 10; rect.w = 100; rect.h = 100;
  SDL_ShowWindow(window);
  
  SDL_RenderClear(renderer);
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
  SDL_RenderDrawRect(renderer, &rect);
  SDL_RenderFillRect(renderer, &rect);
  SDL_RenderPresent(renderer);

  SDL_Event e;
  while(true) {
      while(SDL_PollEvent(&e) != 0) {
        if(e.type == SDL_QUIT) {
            goto exit;
        }
    }
  }

  exit:
  return 0;
}