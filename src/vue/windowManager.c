#include "windowManager.h"

static int counter = 0;


#include <assert.h>

/**
 * @brief Implementation de la fonction windowManager_init.
 */
windowManager *windowManager_init(char *name, int w, int h) {
  // init la SDL si pas encore fait.
  if (counter == 0) {
    printf("[LOG] La SDL va être initialisée.\n");
    if (SDL_Init(SDL_INIT_AUDIO)) {
      fprintf(stderr, "Erreur SDL_Init : %s", SDL_GetError());
      exit(EXIT_FAILURE);
    }
  }
    TTF_Init();

  // essaie de créer un fenêtre.
  windowManager *window = (windowManager *)malloc(sizeof(windowManager));
  assert(window);

  SDL_CreateWindowAndRenderer(w, h, SDL_WINDOW_RESIZABLE, &window->window,
                              &window->renderer);
  SDL_SetWindowTitle(window->window, name);

  if (!window->window) {
    fprintf(stderr, "Erreur SDL_CreateWindow : %s", SDL_GetError());
    free(window);
    printf("[LOG] Nombre de fenêtre active %d\n", counter);
    exit(EXIT_FAILURE);
  }

  counter++;
  printf("[LOG] Création d'une nouvelle fenêtre\n");
  printf("[LOG] Nombre de fenêtre active %d\n", counter);
  return window;
}  // windowManager_init


/**
 * @brief Implementation de la fonction windowManager_destroy.
 */
void windowManager_destroy(windowManager *window) {
  assert(window && window->window && window->renderer);
  if (!counter) return;

  SDL_DestroyRenderer(window->renderer);
  SDL_DestroyWindow(window->window);

  counter--;
  free(window);

  printf("[LOG] Déstruction d'une fenêtre\n");
  printf("[LOG] Nombre de fenêtre active %d\n", counter);

  if (!counter) {
    printf("[LOG] La SDL a été stoppée\n");
    SDL_Quit();
    TTF_Quit();
  }
}  // windowManager_destroy