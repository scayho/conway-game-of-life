# Example file showing a basic pygame "game loop"
import pygame
import sys
# pygame setup
HEIGHT = 200
WIDTH = 200
pygame.init()
screen = pygame.display.set_mode((WIDTH, HEIGHT))
clock = pygame.time.Clock()
running = True
step = 20
cell_array = [[False for x in range(WIDTH // step)] for y in range(HEIGHT // step)]
cell_array[0][5] = True
cell_array[5][3] = True
cell_array[4][6] = True
cell_array[2][7] = True
cell_array[9][6] = True
while running:
    # poll for events
    # pygame.QUIT event means the user clicked X to close your window
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    screen.fill("black")
    ys = 0
    xs = 0
    while (ys < HEIGHT or xs < WIDTH):
        if (ys % 50):
            w = 1
        else:
            w = 2
        if (ys < HEIGHT):
            pygame.draw.line(screen, (220, 220, 220), (0, ys), (WIDTH, ys), w)
        if (xs < WIDTH):
            pygame.draw.line(screen, (220, 220, 220), (xs, 0), (xs, HEIGHT), w)
        ys += step
        xs += step

    for row in range(len(cell_array)):
        for col in range(len(cell_array[0])):
            if (cell_array[row][col]):
                pygame.draw.rect(screen, "white", [col * step, row * step, step, step])

    # fill the screen with a color to wipe away anything from last frame

    # RENDER YOUR GAME HERE

    # flip() the display to put your work on screen
    pygame.display.flip()

    clock.tick(60)  # limits FPS to 60

pygame.quit()