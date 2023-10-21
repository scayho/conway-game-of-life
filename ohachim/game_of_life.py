# Example file showing a basic pygame "game loop"
import pygame
import sys

def cells_gen(filename):
    file1 = open(filename, 'r')
    lines = file1.readlines()
    count = 0
    while lines[count][0] == '!':
        count += 1
    return [[x == 'O' for x in line] for line in lines[count:]]

def map_cells_to_cell_array(cell_array, cells, start_x, start_y):
    start_y_dup = start_y
    for x in cells:
        start_y  = start_y_dup
        for y in x:
            cell_array[start_x][start_y] = y
            start_y += 1
        start_x += 1
def get_live_neighbours(cell_array, x, y):
    start_y =  y - 1 if y - 1 >= 0 else y
    start_x = x - 1 if x - 1 >= 0 else x
    sx = x - start_x + 1
    sy = y - start_y + 1
    print(sy, start_y)
    live_neighbours = 0
    print(cell_array[49][49], "printed")
    for i in range(start_x, start_x + sx):
        for j in range(start_y, start_y + sy):
            print(i, j, cell_array[i][j], x, y)
            if (i != x or j != y) and cell_array[i][j]:
                print("we come in")
                live_neighbours += 1
    return live_neighbours

def death_rule(cell_array, x, y):
    neighbours = 0
    cols = len(cell_array[0])
    rows = len(cell_array)
    life_neighbours = get_live_neighbours(cell_array, x, y)
    return (neighbours >= 3)

def apply_rules(cell_array):
    cell_array_dup = [[False for x in range(len(cell_array[0]))] for y in range(len(cell_array))]
    for nx, x in enumerate(cell_array):
        for ny, y in enumerate(cell_array[0]):
            if not y and death_rule(cell_array, nx, ny):
                cell_array_dup[nx][ny] = True
    return cell_array_dup

cells = cells_gen('spaceship1.cells')
# pygame setup
HEIGHT = 1000
WIDTH = 1000
pygame.init()
screen = pygame.display.set_mode((WIDTH, HEIGHT))
clock = pygame.time.Clock()
running = True
step = 20
cell_array = [[False for x in range(WIDTH // step)] for y in range(HEIGHT // step)]
cell_array[20][20] = True
cell_array[21][20] = True
cell_array[22][20] = True
print(get_live_neighbours(cell_array, 0, 0), "livelve")
sys.exit()
# map_cells_to_cell_array(cell_array, cells, 30, 10)
while running:
    # poll for events
    # pygame.QUIT event means the user clicked X to close your window
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    screen.fill((65, 62, 67))
    ys = 0
    xs = 0
    for row in range(len(cell_array)):
        for col in range(len(cell_array[0])):
            if (cell_array[row][col]):
                pygame.draw.rect(screen, "teal", [col * step, row * step, step, step])
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
    # sys.exit()


    # fill the screen with a color to wipe away anything from last frame

    # RENDER YOUR GAME HERE

    # flip() the display to put your work on screen
    pygame.display.flip()
    pygame.time.wait(1000)
    cell_array = apply_rules(cell_array)

    clock.tick(60)  # limits FPS to 60

pygame.quit()