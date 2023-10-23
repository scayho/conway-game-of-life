# Example file showing a basic pygame "game loop"
import pygame
import sys
# CONFIG

HEIGHT = 1800
WIDTH = 1000
WAIT_TIME = 200
SPEED = 100
ZOOM = 1
STEP = 8
#####

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
    sx = x + 2 if x + 2 <= len(cell_array) else x + 1
    sy = y + 2 if y + 2 <= len(cell_array[0]) else y + 1
    live_neighbours = 0
    for i in range(start_x, sx):
        for j in range(start_y, sy):
            if (i != x or j != y) and cell_array[i][j]:
                live_neighbours += 1
    return live_neighbours

def death_rule(cell_array, x, y):
    live_neighbours = get_live_neighbours(cell_array, x, y)
    return (live_neighbours == 3)

def survive_rule(cell_array, x, y):
    live_neighbours = get_live_neighbours(cell_array, x, y)
    return (live_neighbours == 3 or live_neighbours == 2)

def apply_rules(cell_array):
    cell_array_dup = [[False for x in range(len(cell_array[0]))] for y in range(len(cell_array))]
    for nx, x in enumerate(cell_array):
        for ny, y in enumerate(cell_array[0]):
            if not cell_array[nx][ny] and death_rule(cell_array, nx, ny):
                cell_array_dup[nx][ny] = True
            elif cell_array[nx][ny] and survive_rule(cell_array, nx, ny):
                cell_array_dup[nx][ny] = True
            else:
                cell_array_dup[nx][ny] = False
    return cell_array_dup

def paused():
    while True:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                return False
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_p:
                    return True

cells = cells_gen(sys.argv[1])
# print()
# sys.exit()
# pygame setup
pygame.init()
screen = pygame.display.set_mode((WIDTH, HEIGHT))
clock = pygame.time.Clock()
running = True
cell_array = [[False for x in range(200)] for y in range(200)]
print("dimensions: ", len(cell_array), len(cell_array[0]))
# sys.exit()
map_cells_to_cell_array(cell_array, cells, 30, 10)
while running:
    # poll for events
    # pygame.QUIT event means the user clicked X to close your window
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False
        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_p:
                running = paused()
            elif event.key == pygame.K_LEFT:
                SPEED = SPEED + 100 if SPEED < 1200 else SPEED
            elif event.key == pygame.K_RIGHT:
                SPEED = SPEED - 100 if SPEED > 0 else SPEED
                print(SPEED, "what speed")
            elif event.key == pygame.K_o:
                STEP -= 1
            elif event.key == pygame.K_i:
                STEP += 1



    screen.fill((180, 190, 185))
    ys = 0
    xs = 0
    for row in range(len(cell_array)):
        sr = 0
        sc = 0
        for col in range(len(cell_array[0])):
            if (cell_array[row][col]):
                if not (row % (STEP * 5)):
                    sr = 1
                if not (col % (STEP * 5)):
                    sc = 1
                pygame.draw.rect(screen, "yellow", [col * STEP + 1, row * STEP + 1, STEP, STEP])
    while (ys < HEIGHT or xs < WIDTH):
        if (ys % (STEP * 5)):
            w = 1
        else:
            w = 1# 2
        if (ys < HEIGHT):
            pygame.draw.line(screen, (220, 220, 220), (0, ys), (WIDTH, ys), w)
        if (xs < WIDTH):
            pygame.draw.line(screen, (220, 220, 220), (xs, 0), (xs, HEIGHT), w)
        ys += STEP
        xs += STEP
    # sys.exit()


    # fill the screen with a color to wipe away anything from last frame

    # RENDER YOUR GAME HERE

    # flip() the display to put your work on screen
    pygame.display.flip()
    pygame.time.wait(SPEED)
    cell_array = apply_rules(cell_array)

    clock.tick(60)  # limits FPS to 24

pygame.quit()